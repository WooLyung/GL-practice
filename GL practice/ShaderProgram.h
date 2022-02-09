#pragma once
#include "pch.h"

#pragma once
class ShaderProgram
{
private:
	GLuint shaderProgram;

public:
	ShaderProgram();

	GLuint getShaderProgram();
};