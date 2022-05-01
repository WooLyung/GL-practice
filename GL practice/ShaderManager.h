#pragma once
#include <map>
#include "pch.h"
#include "Shader.h"

class ShaderManager
{
private:
	static ShaderManager* instance;
	map<string, Shader*> shaders;

public:
	~ShaderManager();

	void addShader(string, string, string);
	Shader* getShader(string);

	static ShaderManager* getInstance();
};