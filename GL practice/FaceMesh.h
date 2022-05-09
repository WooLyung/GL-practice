#pragma once
#include "Mesh.h"

class FaceMesh :
    public Mesh
{
private:
	int n;
	GLuint VAO;

public:
	FaceMesh(int);

	size_t getVAOcount();
	GLuint* getVAOs();
	void render(Vector3, Vector3, Vector3);
};