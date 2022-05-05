#pragma once
#include "Mesh.h"

class LineMesh :
	public Mesh
{
private:
	GLuint VAO[42];

public:
	LineMesh();

	size_t getVAOcount();
	GLuint* getVAOs();
	void render();
};