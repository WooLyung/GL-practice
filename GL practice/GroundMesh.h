#pragma once
#include "Mesh.h"

class GroundMesh :
	public Mesh
{
private:
	GLuint VAO;

public:
	GroundMesh();

	size_t getVAOcount();
	GLuint* getVAOs();
	void render(Vector3, Vector3, Vector3);
};