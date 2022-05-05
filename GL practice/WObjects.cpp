#include "WObjects.h"
#include "ShaderManager.h"
#include "MeshManager.h"

void WObjects::init()
{
	Object* obj2 = new Object();
	obj2->shader = ShaderManager::getInstance()->getShader("white");
	obj2->mesh = MeshManager::getInstance()->getMesh("line");
	obj2->scale = vec3(0.2f, 0.2f, 0.2f);
	objects.push_back(obj2);

	Object* obj = new Object();
	obj->shader = ShaderManager::getInstance()->getShader("default");
	obj->mesh = MeshManager::getInstance()->getMesh("face");
	obj->scale = vec3(0.2f, 0.2f, 0.2f);
	objects.push_back(obj);
}

WObjects::~WObjects()
{
	for (Object* obj : objects)
		delete obj;
}