#include "Vector.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2(v.x + x, v.y + y);
}

Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(v.x - x, v.y - y);
}

float Vector2::operator*(const Vector2& v) const
{
	return v.x * x + v.y * y;
}

Vector2 Vector2::operator+=(const Vector2& v)
{
	return *this = *this + v;
}

Vector2 Vector2::operator-=(const Vector2& v)
{
	return *this = *this - v;
}

bool Vector2::operator==(const Vector2& v) const
{
	return v.x == x && v.y == y;
}

bool Vector2::operator!=(const Vector2& v) const
{
	return !(v == *this);
}

Vector2 Vector2::operator*(const float& i) const
{
	return Vector2(x * i, y * i);
}

Vector2 Vector2::operator/(const float& i) const
{
	return Vector2(x / i, y / i);
}

Vector2 Vector2::operator*=(const float& i)
{
	return *this = *this * i;
}

Vector2 Vector2::operator/=(const float& i)
{
	return *this = *this / i;
}