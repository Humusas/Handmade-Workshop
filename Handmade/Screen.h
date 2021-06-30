#pragma once

/*===================================================================#
| 'Screen' source files last updated on 30 June 2021                 |
#===================================================================*/

#include <Windows.h>
#include <glm.hpp>
#include <string>
#include "glad.h"
#include "wglext.h"

//TODO - Refine class such that it follows newer design

class Screen
{

public:

	enum class VSyncState
	{
		VSYNC_OFF,
		VSYNC_ON
	};

	static Screen* Instance();

	const glm::vec2& GetResolution() const;
	
	void SetResolution(GLuint width, GLuint height);
	void SetViewport(GLint x, GLint y, GLsizei width, GLsizei height);

	void IsDepthTestEnabled(bool flag);

	bool Initialize(HWND wnd, const std::string& filename);

	void ActivateContext();
	void DeactivateContext();

	void Update();
	void Present();
	void ShutDown();

private:

	Screen();
	Screen(const Screen&);
	Screen& operator=(const Screen&);

	GLint m_pixelFormat;
	
	glm::ivec4 m_viewport;
	glm::uvec2 m_resolution;

	HDC m_deviceContext;
	HGLRC m_renderContext;

	PIXELFORMATDESCRIPTOR m_pixelFormatClass;
	PFNWGLCREATECONTEXTATTRIBSARBPROC m_wglCreateContextAttribsARB;

};