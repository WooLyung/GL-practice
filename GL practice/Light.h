#pragma once
#include "pch.h"

class Light
{
public:
	vec3 position;
	
	vec3 light_ambient;
	vec3 light_diffuse;
	vec3 light_specular;
};