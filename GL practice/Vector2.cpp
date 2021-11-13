#include "Vector.h"

const Vector2 Vector2::one = Vector2(1.0f, 1.0f);
const Vector2 Vector2::zero = Vector2(0.0f, 0.0f);
const Vector2 Vector2::x_axis = Vector2(1.0f, 0.0f);
const Vector2 Vector2::y_axis = Vector2(0.0f, 1.0f);

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
	return Vector2(x - v.x, y - v.y);
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

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}