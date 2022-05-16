#pragma once
#include <vector>
#include "pch.h"
#include "Object.h"
#include "Light.h"

class WObjects
{
public:
	vector<Object*> objects;
	vector<Light*> lights;

	~WObjects();

	void init();
	void update();
};