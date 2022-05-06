#pragma once
#include <ctime>

class WTime
{
private:
	static float deltaTime;
	clock_t preTime = clock();

public:
	void update();
	float getDeltaTime();
};