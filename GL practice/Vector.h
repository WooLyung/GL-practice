#pragma once

typedef class Vector2
{
public:
	float x, y;

	// ������
	Vector2();
	Vector2(float, float);

	// ����-���� ����
	Vector2 operator+(const Vector2&) const;
	Vector2 operator-(const Vector2&) const;
	Vector2 operator+=(const Vector2&);
	Vector2 operator-=(const Vector2&);
	float operator*(const Vector2&) const;
	bool operator==(const Vector2&) const;
	bool operator!=(const Vector2&) const;

	// ����-��Į�� ����
	Vector2 operator*(const float&) const;
	Vector2 operator/(const float&) const;
	Vector2 operator*=(const float&);
	Vector2 operator/=(const float&);
} vec2;