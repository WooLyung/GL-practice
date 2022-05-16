#pragma once
#include "Mesh.h"
#include "Material.h"

class SphereMesh2 :
	public Mesh
{
private:
	Material material;
	GLuint VAO;
	int vertexs;

public:
	SphereMesh2();

	size_t getVAOcount();
	GLuint* getVAOs();
	void render(Vector3, Vector3, Vector3);
};