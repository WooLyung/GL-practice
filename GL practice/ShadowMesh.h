#pragma once
#include "Mesh.h"

class ShadowMesh :
	public Mesh
{
private:
	int n;
	GLuint VAO;
	GLuint light_param;

public:
	ShadowMesh(int);

	size_t getVAOcount();
	GLuint* getVAOs();
	void render(Vector3, Vector3, Vector3);
};