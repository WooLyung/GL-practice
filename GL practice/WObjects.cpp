#include "WObjects.h"
#include "ShaderManager.h"
#include "MeshManager.h"

void WObjects::init()
{
	Object* obj = new Object();
	obj->shader = ShaderManager::getInstance()->getShader("default");
	obj->mesh = MeshManager::getInstance()->getMesh("test");
	obj->scale = vec3(0.2f, 0.2f, 0.2f);
	objects.push_back(obj);
}