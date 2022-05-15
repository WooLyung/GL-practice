#pragma once
#include "Mesh.h"

class SphereMesh2 :
	public Mesh
{
private:
	GLuint VAO;
	int vertexs;

public:
	SphereMesh2();

	size_t getVAOcount();
	GLuint* getVAOs();
	void render(Vector3, Vector3, Vector3);
};