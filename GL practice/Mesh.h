#pragma once
#include "pch.h"

class Mesh
{
private:
	GLuint VAO = 0;

public:
	virtual GLuint getVAO() = 0;
	virtual void render() = 0;
};