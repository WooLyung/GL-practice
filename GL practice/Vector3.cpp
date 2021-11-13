#include "Vector.h"

const Vector3 Vector3::one = Vector3(1.0f, 1.0f, 1.0f);
const Vector3 Vector3::zero = Vector3(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::x_axis = Vector3(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::y_axis = Vector3(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::z_axis = Vector3(0.0f, 0.0f, 1.0f);

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator+(const Vector3& v) const
{
	return Vector3(v.x + x, v.y + y, v.z + z);
}

Vector3 Vector3::operator-(const Vector3& v) const
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

float Vector3::operator*(const Vector3& v) const
{
	return v.x * x + v.y * y + v.z * z;
}

Vector3 Vector3::operator+=(const Vector3& v)
{
	return *this = *this + v;
}

Vector3 Vector3::operator-=(const Vector3& v)
{
	return *this = *this - v;
}

bool Vector3::operator==(const Vector3& v) const
{
	return v.x == x && v.y == y && v.z == z;
}

bool Vector3::operator!=(const Vector3& v) const
{
	return !(v == *this);
}

Vector3 Vector3::operator*(const float& i) const
{
	return Vector3(x * i, y * i, z * i);
}

Vector3 Vector3::operator/(const float& i) const
{
	return Vector3(x / i, y / i, z / i);
}

Vector3 Vector3::operator*=(const float& i)
{
	return *this = *this * i;
}

Vector3 Vector3::operator/=(const float& i)
{
	return *this = *this / i;
}

Vector3 Vector3::operator%(const Vector3& v) const
{
	return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

Vector3 Vector3::operator%=(const Vector3& v)
{
	return *this = *this % v;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}