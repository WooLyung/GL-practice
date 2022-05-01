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

	Object* obj2 = new Object();
	obj2->shader = ShaderManager::getInstance()->getShader("hello");
	obj2->mesh = MeshManager::getInstance()->getMesh("test");
	obj2->scale = vec3(0.2f, 0.2f, 0.2f);
	obj2->location.z = 0.2f;
	obj2->rotation.z = 0.5f;
	objects.push_back(obj2);
}

WObjects::~WObjects()
{
	for (Object* obj : objects)
		delete obj;
}