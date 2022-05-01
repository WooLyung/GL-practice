#include "WEngine.h"

void WEngine::init(int argc, char** argv)
{
	window = new WWindow(argc, argv);
	meshs = new WMeshs();
	graphic = new WGraphic();

	graphic->init();
}

void WEngine::start()
{
	glutMainLoop();
}