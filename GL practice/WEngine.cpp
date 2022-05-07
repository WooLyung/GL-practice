#include "WEngine.h"
#include "ShaderManager.h"
#include "MeshManager.h"

static WEngine* engine = NULL;

namespace callbacks
{
	void display()
	{
		if (engine)
			engine->display();
	}

	void idle()
	{
		if (engine)
			engine->idle();
	}
}

void WEngine::idle()
{
	time->update();
	input->update();
	objects->update();
	graphic->update();
	graphic->idle();
}

void WEngine::init(int argc, char** argv)
{
	engine = this;

	window = new WWindow();
	objects = new WObjects();
	graphic = new WGraphic();
	time = new WTime();
	input = new WInput();

	window->init(argc, argv);
	graphic->init(objects);
	objects->init();

	glutDisplayFunc(callbacks::display);
	glutIdleFunc(callbacks::idle);
}

void WEngine::display()
{
	graphic->render();
}

void WEngine::start()
{
	glutMainLoop();
}

WEngine::~WEngine()
{
	delete objects;
	delete window;
	delete graphic;
	delete time;
	delete input;
	delete ShaderManager::getInstance();
	delete MeshManager::getInstance();
}