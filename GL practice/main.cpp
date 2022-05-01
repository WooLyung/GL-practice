#include "pch.h"
#include "WEngine.h"

int main(int argc, char** argv)
{
	WEngine* engine = new WEngine();
	engine->init(argc, argv);
	engine->start();
	delete engine;
}