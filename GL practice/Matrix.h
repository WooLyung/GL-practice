#pragma once
#include "Vector.h"

typedef class Matrix2
{
	friend Vector2 operator*(const Matrix2&, const Vector2&);
	friend Vector2 operator*(const Vector2&, const Matrix2&);

private:
	float data_11, data_12, data_21, data_22;

public:
	const static Matrix2 one;
	const static Matrix2 zero;
	const static Matrix2 identity;

	// ������
	Matrix2();
	Matrix2(float, float, float, float);
	Matrix2(const Vector2&, const Vector2&);

	// ���-��� ����
	Matrix2 operator+(const Matrix2&) const;
	Matrix2 operator-(const Matrix2&) const;
	Matrix2 operator*(const Matrix2&) const;
	Matrix2 operator+=(const Matrix2&);
	Matrix2 operator-=(const Matrix2&);
	Matrix2 operator*=(const Matrix2&);
	bool operator==(const Matrix2&) const;
	bool operator!=(const Matrix2&) const;

	// ���-��Į�� ����
	Matrix2 operator*(const float&) const;
	Matrix2 operator/(const float&) const;
	Matrix2 operator*=(const float&);
	Matrix2 operator/=(const float&);

	// ���� ����
	float& operator()(const int&, const int&); // �ε���
	Matrix2 operator~() const; // ��ġ ���
	Matrix2 operator-() const;
} mat2;

// ���-���� ���� (2����)
Vector2 operator*(const Matrix2&, const Vector2&);
Vector2 operator*(const Vector2&, const Matrix2&);
Vector2 operator*=(Vector2&, const Matrix2&);

typedef class Matrix3
{
	friend Vector3 operator*(const Matrix3&, const Vector3&);
	friend Vector3 operator*(const Vector3&, const Matrix3&);

private:
	float data_11, data_12, data_13, data_21, data_22, data_23, data_31, data_32, data_33;

public:
	const static Matrix3 one;
	const static Matrix3 zero;
	const static Matrix3 identity;

	// ������
	Matrix3();
	Matrix3(float, float, float, float, float, float, float, float, float);
	Matrix3(const Vector3&, const Vector3&, const Vector3&);

	// ���-��� ����
	Matrix3 operator+(const Matrix3&) const;
	Matrix3 operator-(const Matrix3&) const;
	Matrix3 operator*(const Matrix3&) const;
	Matrix3 operator+=(const Matrix3&);
	Matrix3 operator-=(const Matrix3&);
	Matrix3 operator*=(const Matrix3&);
	bool operator==(const Matrix3&) const;
	bool operator!=(const Matrix3&) const;

	// ���-��Į�� ����
	Matrix3 operator*(const float&) const;
	Matrix3 operator/(const float&) const;
	Matrix3 operator*=(const float&);
	Matrix3 operator/=(const float&);

	// ���� ����
	float& operator()(const int&, const int&); // �ε���
	Matrix3 operator~() const; // ��ġ ���
	Matrix3 operator-() const;
} mat3;

// ���-���� ���� (2����)
Vector3 operator*(const Matrix3&, const Vector3&);
Vector3 operator*(const Vector3&, const Matrix3&);
Vector3 operator*=(Vector3&, const Matrix3&);

typedef class Matrix4
{
	friend Vector4 operator*(const Matrix4&, const Vector4&);
	friend Vector4 operator*(const Vector4&, const Matrix4&);

private:
	float data_11, data_12, data_13, data_14, data_21, data_22, data_23, data_24, data_31, data_32, data_33, data_34, data_41, data_42, data_43, data_44;

public:
	const static Matrix4 one;
	const static Matrix4 zero;
	const static Matrix4 identity;

	// ������
	Matrix4();
	Matrix4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
	Matrix4(const Vector4&, const Vector4&, const Vector4&, const Vector4&);

	// ���-��� ����
	Matrix4 operator+(const Matrix4&) const;
	Matrix4 operator-(const Matrix4&) const;
	Matrix4 operator*(const Matrix4&) const;
	Matrix4 operator+=(const Matrix4&);
	Matrix4 operator-=(const Matrix4&);
	Matrix4 operator*=(const Matrix4&);
	bool operator==(const Matrix4&) const;
	bool operator!=(const Matrix4&) const;

	// ���-��Į�� ����
	Matrix4 operator*(const float&) const;
	Matrix4 operator/(const float&) const;
	Matrix4 operator*=(const float&);
	Matrix4 operator/=(const float&);

	// ���� ����
	float& operator()(const int&, const int&); // �ε���
	Matrix4 operator~() const; // ��ġ ���
	Matrix4 operator-() const;
} mat4;

// ���-���� ���� (2����)
Vector4 operator*(const Matrix4&, const Vector4&);
Vector4 operator*(const Vector4&, const Matrix4&);
Vector4 operator*=(Vector4&, const Matrix4&);