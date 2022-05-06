#include "WObjects.h"
#include "ShaderManager.h"
#include "MeshManager.h"
#include "WTime.h"

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

void WObjects::update()
{
	objects[0]->rotation.x += WTime::getDeltaTime() * 0.1f;
	objects[0]->rotation.y += WTime::getDeltaTime() * 0.15f;
	objects[0]->rotation.z += WTime::getDeltaTime() * 0.08f;
	objects[1]->rotation.x += WTime::getDeltaTime() * 0.1f;
	objects[1]->rotation.y += WTime::getDeltaTime() * 0.15f;
	objects[1]->rotation.z += WTime::getDeltaTime() * 0.08f;
}

WObjects::~WObjects()
{
	for (Object* obj : objects)
		delete obj;
}