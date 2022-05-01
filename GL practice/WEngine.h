#pragma once
#include "WWindow.h"
#include "WGraphic.h"
#include "WObjects.h"

class WEngine
{
private:
	WWindow* window;
	WObjects* objects;
	WGraphic* graphic;

public:
	~WEngine();

	void init(int argc, char** argv);
	void start();

	void display();
	void idle();
};