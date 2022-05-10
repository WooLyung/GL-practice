#include "WObjects.h"
#include "ShaderManager.h"
#include "MeshManager.h"
#include "WTime.h"
#include "WInput.h"

void WObjects::init()
{
	Object* sphere = new Object();
	sphere->shader = ShaderManager::getInstance()->getShader("default");
	sphere->mesh = MeshManager::getInstance()->getMesh("sphere");
	objects.push_back(sphere);
}

void WObjects::update()
{
	objects[0]->rotation.x += WTime::getDeltaTime() * 0.7f;
	objects[0]->rotation.y += WTime::getDeltaTime() * 0.6f;
	objects[0]->rotation.z += WTime::getDeltaTime() * 0.5f;
}

WObjects::~WObjects()
{
	for (Object* obj : objects)
		delete obj;
}