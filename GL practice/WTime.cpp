#include "WTime.h"

float WTime::deltaTime = 0.0f;

void WTime::update()
{
	clock_t nowTime = clock();
	deltaTime = (float)(nowTime - preTime) / CLOCKS_PER_SEC;
	preTime = nowTime;
}

float WTime::getDeltaTime()
{
	return deltaTime;
}