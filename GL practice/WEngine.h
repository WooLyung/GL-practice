#pragma once
#include "WWindow.h"
#include "WGraphic.h"
#include "WMeshs.h"

class WEngine
{
private:
	WWindow* window;
	WMeshs* meshs;
	WGraphic* graphic;

public:
	void init(int argc, char** argv);
	void start();
};