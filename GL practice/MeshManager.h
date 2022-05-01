#pragma once
#include <map>
#include "pch.h"
#include "Mesh.h"

class MeshManager
{
private:
	static MeshManager* instance;
	map<string, Mesh*> meshs;

public:
	~MeshManager();

	void addMesh(string, Mesh*);
	Mesh* getMesh(string);

	static MeshManager* getInstance();
};