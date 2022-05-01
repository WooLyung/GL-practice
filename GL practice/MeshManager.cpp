#include "MeshManager.h"

MeshManager* MeshManager::instance = nullptr;

void MeshManager::addMesh(string key, Mesh* mesh)
{
	meshs[key] = mesh;
}

Mesh* MeshManager::getMesh(string key)
{
	if (meshs.find(key) == meshs.end())
		return nullptr;
	return meshs[key];
}

MeshManager* MeshManager::getInstance()
{
	if (instance)
		return instance;
	else
		return instance = new MeshManager();
}

MeshManager::~MeshManager()
{
	for (auto pair : meshs)
		delete pair.second;
}