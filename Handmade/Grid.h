#pragma once

/*===================================================================#
| 'Grid' source files last updated on 23 February 2022               |
#====================================================================#
| Class has not been fully tested. No known issues found.            |
#===================================================================*/

#include "Buffer.h"
#include "Object.h"

class Grid : public Object
{

public:

	Grid(bool hasSpaceForAxes = false,
		GLint size = 15, GLfloat lineWidth = 1.5f);
	virtual ~Grid();

	void SetSize(GLint size);
	void SetLineWidth(GLfloat lineWidth);

	virtual void SetColor(const glm::vec4& color);
	virtual void SetColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f);

	virtual void Render(Shader& shader);
	virtual void Update(GLfloat deltaTime) {}
	virtual void SendToShader(Shader& shader) {}

private:

	void Create();

	GLint m_size;
	Buffer m_buffer;
	GLfloat m_lineWidth;
	bool m_hasSpaceForAxes;

	const GLuint QUADRANTS = 4;
};