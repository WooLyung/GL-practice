#pragma once
#include "WObjects.h"

class WGraphic
{
private:
	WObjects* objects;

	void shaderInit();

public:
	void init(WObjects*);
	void render();
	void idle();
};