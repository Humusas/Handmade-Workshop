#pragma once
#include "Object.h"

const GLfloat MIN_FOV = 1.0f;
const GLfloat MAX_FOV = 100.0f;
const GLfloat NEAR_CLIP = 0.1f;
const GLfloat FAR_CLIP = 1000.0f;

class Camera : public Object
{

public:

	enum class Origin2D
	{
		TopLeft,
		BottomLeft
	};

	Camera(const std::string& tag);
	virtual ~Camera() = 0 {}

	const glm::ivec2 GetResolution() const;

	void SetVelocity(GLfloat velocity);
	void SetFieldOfView(GLfloat fieldOfView);
	void SetViewport(GLint x, GLint y, GLsizei width, GLsizei height);

	void SetBackgroundColor(const glm::vec4& backgroundColor);
	void SetBackgroundColor(const glm::uvec4& backgroundColor);
	void SetBackgroundColor(GLuint r, GLuint g, GLuint b, GLuint a = 1U);
	void SetBackgroundColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f);

	void CreatePerspView();
	void CreateOrthoView(Origin2D origin = Origin2D::BottomLeft);

	glm::vec2 ConvertWorldToScreen(const glm::vec3& worldPosition);
	glm::vec3 ConvertScreenToWorld(const glm::vec2& screenPosition, GLfloat zNDC);

	void Reset();

	virtual void Render(Shader& shader) = 0;
	virtual void Update(GLfloat deltaTime) = 0;
	virtual void SendToShader(Shader& shader);

protected:

	GLfloat m_velocity{ 0.0f };
	GLfloat m_fieldOfView{ 45.0f };

	glm::vec3 m_up{ 0.0f, 1.0f, 0.0f };
	glm::vec3 m_forward{ 0.0f, 0.0f, -1.0f };

	glm::ivec4 m_viewport{ 0 };
	glm::ivec2 m_resolution{ 0 };
	glm::vec4 m_backgroundColor{ 0.0f };

	glm::mat4 m_viewMatrix{ 1.0f };
	glm::mat4 m_projectionMatrix{ 1.0f };

};