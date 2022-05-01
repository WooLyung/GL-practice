#include "ShaderManager.h"

ShaderManager* ShaderManager::instance = nullptr;

void ShaderManager::addShader(string key, string vertex, string fragment)
{
	Shader* shader = new Shader(vertex, fragment);
	shaders[key] = shader;
}

Shader* ShaderManager::getShader(string key)
{
	if (shaders.find(key) == shaders.end())
		return nullptr;
	return shaders[key];
}

ShaderManager* ShaderManager::getInstance()
{
	if (instance)
		return instance;
	else
		return instance = new ShaderManager();
}

ShaderManager::~ShaderManager()
{
	for (auto pair : shaders)
		delete pair.second;
}