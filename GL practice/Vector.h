#pragma once

template<typename T = float>
class Vector2
{
public:
	// ������Ƽ
	T x, y;
	
	// ������
	Vector2(T, T);
};

typedef Vector2<float> vec2;