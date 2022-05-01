#pragma once
#include "pch.h"
#include "Mesh.h"
#include "Shader.h"

class Object
{
public:
	Vector3 location;
	Vector3 rotation;
	Vector3 scale;
	
	Mesh* mesh;
	Shader* shader;
};