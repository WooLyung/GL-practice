#include "Matrix.h"

const Matrix2 Matrix2::one = Matrix2(1.0f, 1.0f, 1.0f, 1.0f);
const Matrix2 Matrix2::zero = Matrix2(0.0f, 0.0f, 0.0f, 0.0f);
const Matrix2 Matrix2::identity = Matrix2(1.0f, 0.0f, 0.0f, 1.0f);

Matrix2::Matrix2()
{
	data_11 = 0.0f;
	data_12 = 0.0f;
	data_21 = 0.0f;
	data_22 = 0.0f;
}

Matrix2::Matrix2(float a11, float a12, float a21, float a22)
{
	data_11 = a11;
	data_12 = a12;
	data_21 = a21;
	data_22 = a22;
}

Matrix2::Matrix2(const Vector2& v1, const Vector2& v2)
{
	data_11 = v1.x;
	data_12 = v1.y;
	data_21 = v2.x;
	data_22 = v2.y;
}

Matrix2 Matrix2::operator+(const Matrix2& m) const
{
	return Matrix2(
		m.data_11 + data_11, m.data_12 + data_12,
		m.data_21 + data_21, m.data_22 + data_22
		);
}

Matrix2 Matrix2::operator-(const Matrix2& m) const
{
	return Matrix2(
		data_11 - m.data_11, data_12 - m.data_12,
		data_21 - m.data_21, data_22 - m.data_22
	);
}

Matrix2 Matrix2::operator*(const Matrix2& m) const
{
	return Matrix2(
		data_11 * m.data_11 + data_12 * m.data_21, data_11 * m.data_12 + data_12 * m.data_22,
		data_21 * m.data_11 + data_22 * m.data_21, data_21 * m.data_12 + data_22 * m.data_22
	);
}

Matrix2 Matrix2::operator+=(const Matrix2& m)
{
	return *this = *this + m;
}

Matrix2 Matrix2::operator-=(const Matrix2& m)
{
	return *this = *this - m;
}

Matrix2 Matrix2::operator*=(const Matrix2& m)
{
	return *this = *this * m;
}

bool Matrix2::operator==(const Matrix2& m) const
{
	return m.data_11 == data_11 &&
		m.data_12 == data_12 &&
		m.data_21 == data_21 &&
		m.data_22 == data_22;
}

bool Matrix2::operator!=(const Matrix2& m) const
{
	return !(*this == m);
}

Matrix2 Matrix2::operator*(const float& i) const
{
	return Matrix2(
		data_11 * i, data_12 * i,
		data_21 * i, data_22 * i
	);
}

Matrix2 Matrix2::operator*=(const float& i)
{
	return *this = *this * i;
}

Matrix2 Matrix2::operator/(const float& i) const
{
	return Matrix2(
		data_11 / i, data_12 / i,
		data_21 / i, data_22 / i
	);
}

Matrix2 Matrix2::operator/=(const float& i)
{
	return *this = *this / i;
}

float& Matrix2::operator()(const int& row, const int& col)
{
	switch (row)
	{
	case 1:
		switch (col)
		{
		case 1: return data_11;
		case 2: return data_12;
		}
	case 2:
		switch (col)
		{
		case 1: return data_21;
		case 2: return data_22;
		}
	}
	return data_11;
}

Matrix2 Matrix2::operator~() const
{
	return Matrix2(
		data_11, data_21,
		data_12, data_22
	);
}

Matrix2 Matrix2::operator-() const
{
	return Matrix2(
		-data_11, -data_12,
		-data_21, -data_22
	);
}

Vector2 operator*(const Matrix2& m, const Vector2& v)
{
	return Vector2(v.x * m.data_11 + v.y * m.data_12, v.x * m.data_21 + v.y * m.data_22);
}

Vector2 operator*(const Vector2& v, const Matrix2& m)
{
	return Vector2(v.x * m.data_11 + v.y * m.data_21, v.x * m.data_12 + v.y * m.data_22);
}

Vector2 operator*=(Vector2& v, const Matrix2& m)
{
	return v = v * m;
}