#pragma once
#include "Mesh.h"

class UtahTeapot :
	public Mesh
{
private:
	GLuint VAO;

public:
	UtahTeapot();

	size_t getVAOcount();
	GLuint* getVAOs();
	void render(Vector3, Vector3, Vector3);
};