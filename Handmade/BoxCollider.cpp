#include <algorithm>
#include "BoxCollider.h"
#include "SphereCollider.h"

//======================================================================================================
BoxCollider::BoxCollider()
{
	m_min = glm::vec3(0.0f);
	m_max = glm::vec3(0.0f);
	m_scale = glm::vec3(1.0f);
	m_position = glm::vec3(0.0f);
	m_dimension = glm::vec3(1.0f);
	m_halfDimension = glm::vec3(0.5f);
	m_color = glm::vec4(1.0f, 0.0f, 0.0f, 0.4f);
}
//======================================================================================================
const glm::vec3& BoxCollider::GetScale() const
{
	return m_scale;
}
//======================================================================================================
const glm::vec3& BoxCollider::GetPosition() const
{
	return m_position;
}
//======================================================================================================
const glm::vec3& BoxCollider::GetDimension() const
{
	return m_dimension;
}
//======================================================================================================--
void BoxCollider::SetScale(float x, float y, float z)
{
	m_scale.x = x;
	m_scale.y = y;
	m_scale.z = z;
}
//======================================================================================================
void BoxCollider::SetPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}
//======================================================================================================
void BoxCollider::SetDimension(float width, float height, float depth)
{
	m_dimension.x = width;
	m_dimension.y = height;
	m_dimension.z = depth;
}
//======================================================================================================
bool BoxCollider::IsColliding(const BoxCollider& secondBox) const
{
	return ((m_max.x > secondBox.m_min.x && secondBox.m_max.x > m_min.x) &&
		(m_max.y > secondBox.m_min.y && secondBox.m_max.y > m_min.y) &&
		(m_max.z > secondBox.m_min.z && secondBox.m_max.z > m_min.z));
}
//======================================================================================================
bool BoxCollider::IsColliding(const SphereCollider& secondSphere) const
{
	glm::vec3 distanceFromBox;

	//calculate the distance the sphere and point on box edge are apart from each other
	//this makes use of inner function that calculates the point on box edge closest to sphere 
	distanceFromBox = secondSphere.GetPosition() - PointOnBox(secondSphere.GetPosition().x,
		secondSphere.GetPosition().y,
		secondSphere.GetPosition().z);

	//return flag based on if box intersects with sphere
	return (glm::length(distanceFromBox) <= secondSphere.GetRadius());
}
//======================================================================================================
const glm::vec3& BoxCollider::PointOnBox(float x, float y, float z) const
{
	glm::vec3 clampValue;
	glm::vec3 distanceFromObject;
	glm::vec3 position(x, y, z);

	//first calculate distance between the box's position and passed position
	distanceFromObject = m_position - position;

	//now clamp the distance vector between the half dimensions 
	//the half dimensions already have the scale factor included
	clampValue.x = glm::clamp(distanceFromObject.x, -m_halfDimension.x, m_halfDimension.x);
	clampValue.y = glm::clamp(distanceFromObject.y, -m_halfDimension.y, m_halfDimension.y);
	clampValue.z = glm::clamp(distanceFromObject.z, -m_halfDimension.z, m_halfDimension.z);

	//the clamp value is used to determine the exact point on the 
	//edge of the box that lines up with the passed position point
	return m_position - clampValue;
}
//======================================================================================================
void BoxCollider::Update()
{
	//first determine the half width, height and depth based on scale value  
	m_halfDimension = m_dimension * m_scale / 2.0f;

	//calculate min and max X, Y and Z values based on 
	//bound's centre position and its half dimension
	m_min.x = m_position.x - m_halfDimension.x;
	m_min.y = m_position.y - m_halfDimension.y;
	m_min.z = m_position.z - m_halfDimension.z;
	m_max.x = m_position.x + m_halfDimension.x;
	m_max.y = m_position.y + m_halfDimension.y;
	m_max.z = m_position.z + m_halfDimension.z;
}
//======================================================================================================
void BoxCollider::Draw()
{
	//draw bound based on dimension and color set 
	//TheDebug::Instance()->DrawCube3D(m_dimension.x, m_dimension.y, m_dimension.z, 
								   //  m_color.r, m_color.g, m_color.b, m_color.a);
}