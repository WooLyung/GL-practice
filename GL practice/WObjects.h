#pragma once
#include <vector>
#include "pch.h"
#include "Object.h"

class WObjects
{
public:
	vector<Object*> objects;

	~WObjects();

	void init();
	void update();
};