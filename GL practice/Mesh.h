#pragma once
#include "pch.h"

class Mesh
{
private:
	GLuint VAO = 0;

public:
	virtual size_t getVAOcount() = 0;
	virtual GLuint* getVAOs() = 0;
	virtual void render(Vector3, Vector3, Vector3) = 0;
};