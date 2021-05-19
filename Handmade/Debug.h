#ifndef DEBUG_H
#define DEBUG_H

#include <Windows.h>
#include <glm.hpp>
#include <string>
#include "glad.h"

//TODO - Research on modern OpenGL debug callbacks and add these

class Debug
{

public:

	enum ErrorCode { FAILURE = 4, WARNING = 6, SUCCESS = 10, DEFAULT = 15 };

public:


	static void GLError();
	static void PauseLog();
	static void ClearLog();

	static void DisplayProfile();
	static void DisplayExtensions();

	static void Log(GLfloat value, const std::string& label = "");
	static void Log(const glm::vec3& vector, const std::string& label = "");
	static void Log(const std::string& message, ErrorCode errorCode = DEFAULT);
	static void Log(GLfloat x, GLfloat y, GLfloat z = 0, const std::string& label = "");

private:

	static HANDLE s_consoleHandle;

};

#endif