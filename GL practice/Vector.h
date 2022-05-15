#pragma once

typedef class Vector2
{
public:
	float x, y;
	const static Vector2 one;
	const static Vector2 zero;
	const static Vector2 x_axis;
	const static Vector2 y_axis;

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

	// ����
	Vector2 operator-() const;
	Vector2 normallized() const;
	float norm() const;
} vec2;

typedef class Vector3
{
public:
	float x, y, z;
	const static Vector3 one;
	const static Vector3 zero;
	const static Vector3 x_axis;
	const static Vector3 y_axis;
	const static Vector3 z_axis;

	// ������
	Vector3();
	Vector3(float, float, float);

	// ����-���� ����
	Vector3 operator+(const Vector3&) const;
	Vector3 operator-(const Vector3&) const;
	Vector3 operator+=(const Vector3&);
	Vector3 operator-=(const Vector3&);
	float operator*(const Vector3&) const;
	bool operator==(const Vector3&) const;
	bool operator!=(const Vector3&) const;

	// ����-��Į�� ����
	Vector3 operator*(const float&) const;
	Vector3 operator/(const float&) const;
	Vector3 operator*=(const float&);
	Vector3 operator/=(const float&);

	// ����
	Vector3 operator%(const Vector3&) const;
	Vector3 operator%=(const Vector3&);

	// ����
	Vector3 operator-() const;
	Vector3 normallized() const;
	float norm() const;
} vec3;

typedef class Vector4
{
public:
	float x, y, z, w;
	const static Vector4 one;
	const static Vector4 zero;
	const static Vector4 x_axis;
	const static Vector4 y_axis;
	const static Vector4 z_axis;
	const static Vector4 w_axis;

	// ������
	Vector4();
	Vector4(float, float, float, float);

	// ����-���� ����
	Vector4 operator+(const Vector4&) const;
	Vector4 operator-(const Vector4&) const;
	Vector4 operator+=(const Vector4&);
	Vector4 operator-=(const Vector4&);
	float operator*(const Vector4&) const;
	bool operator==(const Vector4&) const;
	bool operator!=(const Vector4&) const;

	// ����-��Į�� ����
	Vector4 operator*(const float&) const;
	Vector4 operator/(const float&) const;
	Vector4 operator*=(const float&);
	Vector4 operator/=(const float&);

	// ����
	Vector4 operator-() const;
	Vector4 normallized() const;
	float norm() const;
} vec4;

typedef Vector2 point2;
typedef Vector2 color2;
typedef Vector2 pos2;
typedef Vector3 point3;
typedef Vector3 color3;
typedef Vector3 pos3;
typedef Vector4 point4;
typedef Vector4 color4;
typedef Vector4 pos4;