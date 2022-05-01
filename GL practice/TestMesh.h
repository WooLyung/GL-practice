#pragma once
#include "Mesh.h"

class TestMesh :
    public Mesh
{
private:
	int n;
	GLuint VAO;

public:
	TestMesh(int);

	size_t getVAOcount();
	GLuint* getVAOs();
	void render();
};