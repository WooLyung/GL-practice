#include "WObjects.h"
#include "ShaderManager.h"
#include "MeshManager.h"
#include "WTime.h"
#include "WInput.h"

void WObjects::init()
{
	Object* obj2 = new Object();
	obj2->shader = ShaderManager::getInstance()->getShader("white");
	obj2->mesh = MeshManager::getInstance()->getMesh("line");
	obj2->scale = vec3(0.2f, 0.2f, 0.2f);
	obj2->location = vec3(0.0f, 0.0f, 4.0f);
	objects.push_back(obj2);

	Object* obj = new Object();
	obj->shader = ShaderManager::getInstance()->getShader("default");
	obj->mesh = MeshManager::getInstance()->getMesh("face");
	obj->scale = vec3(0.2f, 0.2f, 0.2f);
	obj->location = vec3(0.0f, 0.0f, 4.0f);
	objects.push_back(obj);

	Object* obj3 = new Object();
	obj3->shader = ShaderManager::getInstance()->getShader("shadow");
	obj3->mesh = MeshManager::getInstance()->getMesh("shadow");
	obj3->scale = vec3(0.2f, 0.2f, 0.2f);
	obj3->location = vec3(0.0f, 0.0f, 4.0f);
	objects.push_back(obj3);
}

void WObjects::update()
{
	objects[0]->rotation.x += WTime::getDeltaTime() * 0.1f * 3;
	objects[0]->rotation.y += WTime::getDeltaTime() * 0.15f * 3;
	objects[0]->rotation.z += WTime::getDeltaTime() * 0.08f * 3;
	objects[1]->rotation.x += WTime::getDeltaTime() * 0.1f * 3;
	objects[1]->rotation.y += WTime::getDeltaTime() * 0.15f * 3;
	objects[1]->rotation.z += WTime::getDeltaTime() * 0.08f * 3;
	objects[2]->rotation.x += WTime::getDeltaTime() * 0.1f * 3;
	objects[2]->rotation.y += WTime::getDeltaTime() * 0.15f * 3;
	objects[2]->rotation.z += WTime::getDeltaTime() * 0.08f * 3;
}

WObjects::~WObjects()
{
	for (Object* obj : objects)
		delete obj;
}