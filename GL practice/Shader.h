#pragma once
#include "pch.h"

class Shader
{
private:
	GLuint program;
	GLuint c_param;
	GLuint m_param;
	GLuint pro_param;

public:
	Shader(string, string);

	GLuint getProgram();
	GLuint getCparam();
	GLuint getMparam();
	GLuint getPROparam();
};