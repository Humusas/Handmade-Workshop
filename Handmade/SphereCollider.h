#pragma once
#include "GLAD/gl.h"
#include <glm.hpp>
#include "BoxCollider.h"
#include "LineSegment.h"

//TODO - Add some kind of 'central system' to render all colliders in the scene

class SphereCollider
{

public:

	SphereCollider();

	GLfloat GetScale() const;
	GLfloat GetRadius() const;
	GLfloat GetRadiusScaled() const;
	const glm::vec3& GetPosition() const;

	void SetScale(GLfloat scale);
	void SetRadius(GLfloat radius);

	void SetPosition(const glm::vec3& position);
	void SetPosition(GLfloat x, GLfloat y, GLfloat z);

	bool IsColliding(const BoxCollider& secondBox) const;
	bool IsColliding(const LineSegment& secondLine) const;
	bool IsColliding(const SphereCollider& secondSphere) const;

	void Update();
	void Render() { /*debug only*/ }

private:

	GLfloat m_scale{ 1.0f };
	GLfloat m_radius{ 1.0f };
	GLfloat m_radiusScaled{ 1.0f };
	glm::vec3 m_position{ 0.0f };
	glm::vec4 m_color{ 0.0f, 1.0f, 0.0f, 0.4f };

};