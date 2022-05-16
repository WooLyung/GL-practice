#pragma once
#include "pch.h"

struct  Material
{
	color4 ambient;
	color4 diffuse;
	color4 specular;
	color4 emission;
	float shininess;
};