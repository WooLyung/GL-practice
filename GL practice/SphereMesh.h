#pragma once
#include "Mesh.h"

class SphereMesh :
	public Mesh
{
private:
	GLuint* VAO;

public:
	SphereMesh();
	~SphereMesh();

	size_t getVAOcount();
	GLuint* getVAOs();
	void render(Vector3, Vector3, Vector3);
};