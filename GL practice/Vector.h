#pragma once

template<typename T = float>
class Vector2
{
public:
	// 프로퍼티
	T x, y;
	
	// 생성자
	Vector2(T, T);
};

typedef Vector2<float> vec2;