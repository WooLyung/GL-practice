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

	lights.push_back(new Light());
	lights[0]->position.y = 4.0f;
	lights[0]->light_ambient = vec3(0.5f, 0.5f, 0.5f);
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

	for (Light* light : lights)
		delete light;
}