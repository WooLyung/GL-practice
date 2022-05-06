#pragma once
#include "WObjects.h"
#include "Camera.h"

class WGraphic
{
private:
	Camera* camera = new Camera();
	WObjects* objects;

	void shaderInit();

public:
	void init(WObjects*);
	void render();
	void idle();
	void update();
};