#pragma once
#include "Vector.h"

typedef class Matrix2
{
	friend Vector2 operator*(const Matrix2&, const Vector2&);
	friend Vector2 operator*(const Vector2&, const Matrix2&);

private:
	float data_11, data_12, data_21, data_22;

public:
	// 생성자
	Matrix2();
	Matrix2(float, float, float, float);
	Matrix2(const Vector2&, const Vector2&);

	// 행렬-행렬 연산
	Matrix2 operator+(const Matrix2&) const;
	Matrix2 operator-(const Matrix2&) const;
	Matrix2 operator*(const Matrix2&) const;
	Matrix2 operator+=(const Matrix2&);
	Matrix2 operator-=(const Matrix2&);
	Matrix2 operator*=(const Matrix2&);
	bool operator==(const Matrix2&) const;
	bool operator!=(const Matrix2&) const;

	// 행렬-스칼라 연산
	Matrix2 operator*(const float&) const;
	Matrix2 operator/(const float&) const;
	Matrix2 operator*=(const float&);
	Matrix2 operator/=(const float&);

	// 단항 연산
	float& operator()(const int&, const int&); // 인덱스
	Matrix2 operator~() const; // 전치 행렬
} mat2;

// 행렬-벡터 연산 (2차원)
Vector2 operator*(const Matrix2&, const Vector2&);
Vector2 operator*(const Vector2&, const Matrix2&);