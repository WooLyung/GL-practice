#pragma once
#include "Vector.h"

typedef class Matrix2
{
	friend Vector2 operator*(const Matrix2&, const Vector2&);
	friend Vector2 operator*(const Vector2&, const Matrix2&);

private:
	float data_11, data_12, data_21, data_22;

public:
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
} mat2;

// ���-���� ���� (2����)
Vector2 operator*(const Matrix2&, const Vector2&);
Vector2 operator*(const Vector2&, const Matrix2&);