#pragma once
#include "pch.h"
#include "Mesh.h"
#include "Shader.h"

class Object
{
public:
	Vector3 location;
	Vector3 rotation;
	Vector3 scale = Vector3(1.0f, 1.0f, 1.0f);
	
	Mesh* mesh;
	Shader* shader;
};