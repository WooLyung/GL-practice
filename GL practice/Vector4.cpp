#include "Vector.h"

const Vector4 Vector4::one = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
const Vector4 Vector4::zero = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
const Vector4 Vector4::x_axis = Vector4(1.0f, 0.0f, 0.0f, 0.0f);
const Vector4 Vector4::y_axis = Vector4(0.0f, 1.0f, 0.0f, 0.0f);
const Vector4 Vector4::z_axis = Vector4(0.0f, 0.0f, 1.0f, 0.0f);
const Vector4 Vector4::w_axis = Vector4(0.0f, 0.0f, 0.0f, 1.0f);

Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4 Vector4::operator+(const Vector4& v) const
{
	return Vector4(v.x + x, v.y + y, v.z + z, v.w + w);
}

Vector4 Vector4::operator-(const Vector4& v) const
{
	return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}

float Vector4::operator*(const Vector4& v) const
{
	return v.x * x + v.y * y + v.z * z, v.w * w;
}

Vector4 Vector4::operator+=(const Vector4& v)
{
	return *this = *this + v;
}

Vector4 Vector4::operator-=(const Vector4& v)
{
	return *this = *this - v;
}

bool Vector4::operator==(const Vector4& v) const
{
	return v.x == x && v.y == y;
}

bool Vector4::operator!=(const Vector4& v) const
{
	return !(v == *this);
}

Vector4 Vector4::operator*(const float& i) const
{
	return Vector4(x * i, y * i, z * i, w * i);
}

Vector4 Vector4::operator/(const float& i) const
{
	return Vector4(x / i, y / i, z / i, w / i);
}

Vector4 Vector4::operator*=(const float& i)
{
	return *this = *this * i;
}

Vector4 Vector4::operator/=(const float& i)
{
	return *this = *this / i;
}