#pragma once
#include "pch.h"

class Shader
{
private:
	GLuint program;
	GLuint ctm_param;
	GLuint pro_param;

public:
	Shader(string, string);

	GLuint getProgram();
	GLuint getCTMparam();
	GLuint getPROparam();
};