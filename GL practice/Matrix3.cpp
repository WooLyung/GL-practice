#include "Matrix.h"

const Matrix3 Matrix3::one = Matrix3(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
const Matrix3 Matrix3::zero = Matrix3(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
const Matrix3 Matrix3::identity = Matrix3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

Matrix3::Matrix3()
{
	data_11 = 0.0f;
	data_12 = 0.0f;
	data_13 = 0.0f;
	data_21 = 0.0f;
	data_22 = 0.0f;
	data_23 = 0.0f;
	data_31 = 0.0f;
	data_32 = 0.0f;
	data_33 = 0.0f;
}

Matrix3::Matrix3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33)
{
	data_11 = a11;
	data_12 = a12;
	data_13 = a13;
	data_21 = a21;
	data_22 = a22;
	data_23 = a23;
	data_31 = a31;
	data_32 = a32;
	data_33 = a33;
}

Matrix3::Matrix3(const Vector3& v1, const Vector3& v2, const Vector3& v3)
{
	data_11 = v1.x;
	data_12 = v1.y;
	data_13 = v1.z;
	data_21 = v2.x;
	data_22 = v2.y;
	data_23 = v2.z;
	data_31 = v3.x;
	data_32 = v3.y;
	data_33 = v3.z;
}

Matrix3 Matrix3::operator+(const Matrix3& m) const
{
	return Matrix3(
		m.data_11 + data_11, m.data_12 + data_12, m.data_13 + data_13,
		m.data_21 + data_21, m.data_22 + data_22, m.data_23 + data_23,
		m.data_31 + data_31, m.data_32 + data_32, m.data_33 + data_33
	);
}


Matrix3 Matrix3::operator-(const Matrix3& m) const
{
	return Matrix3(
		data_11 - m.data_11, data_12 - m.data_12, data_13 - m.data_13,
		data_21 - m.data_21, data_22 - m.data_22, data_23 - m.data_23,
		data_31 - m.data_31, data_32 - m.data_32, data_33 - m.data_33
	);
}

Matrix3 Matrix3::operator*(const Matrix3& m) const
{
	return Matrix3(
		data_11 * m.data_11 + data_12 * m.data_21 + data_13 * m.data_31, data_11 * m.data_12 + data_12 * m.data_22 + data_13 * m.data_32, data_11 * m.data_13 + data_12 * m.data_23 + data_13 * m.data_33,
		data_21 * m.data_11 + data_22 * m.data_21 + data_23 * m.data_31, data_21 * m.data_12 + data_22 * m.data_22 + data_23 * m.data_32, data_21 * m.data_13 + data_22 * m.data_23 + data_23 * m.data_33,
		data_31 * m.data_11 + data_32 * m.data_21 + data_33 * m.data_31, data_31 * m.data_12 + data_32 * m.data_22 + data_33 * m.data_32, data_31 * m.data_13 + data_32 * m.data_23 + data_33 * m.data_33
	);
}

Matrix3 Matrix3::operator+=(const Matrix3& m)
{
	return *this = *this + m;
}

Matrix3 Matrix3::operator-=(const Matrix3& m)
{
	return *this = *this - m;
}

Matrix3 Matrix3::operator*=(const Matrix3& m)
{
	return *this = *this * m;
}

bool Matrix3::operator==(const Matrix3& m) const
{
	return m.data_11 == data_11 &&
		m.data_12 == data_12 &&
		m.data_13 == data_13 &&
		m.data_21 == data_21 &&
		m.data_22 == data_22 &&
		m.data_23 == data_23 &&
		m.data_31 == data_31 &&
		m.data_32 == data_32 &&
		m.data_33 == data_33;
}

bool Matrix3::operator!=(const Matrix3& m) const
{
	return !(*this == m);
}

Matrix3 Matrix3::operator*(const float& i) const
{
	return Matrix3(
		data_11 * i, data_12 * i, data_13 * i,
		data_21 * i, data_22 * i, data_23 * i,
		data_31 * i, data_32 * i, data_33 * i
	);
}

Matrix3 Matrix3::operator*=(const float& i)
{
	return *this = *this * i;
}

Matrix3 Matrix3::operator/(const float& i) const
{
	return Matrix3(
		data_11 / i, data_12 / i, data_13 / i,
		data_21 / i, data_22 / i, data_23 / i,
		data_31 / i, data_32 / i, data_33 / i
	);
}

Matrix3 Matrix3::operator/=(const float& i)
{
	return *this = *this / i;
}

float& Matrix3::operator()(const int& row, const int& col)
{
	switch (row)
	{
	case 1:
		switch (col)
		{
		case 1: return data_11;
		case 2: return data_12;
		case 3: return data_13;
		}
	case 2:
		switch (col)
		{
		case 1: return data_21;
		case 2: return data_22;
		case 3: return data_23;
		}
	case 3:
		switch (col)
		{
		case 1: return data_31;
		case 2: return data_32;
		case 3: return data_33;
		}
	}
	return data_11;
}

Matrix3 Matrix3::operator~() const
{
	return Matrix3(
		data_11, data_21, data_31,
		data_12, data_22, data_32,
		data_13, data_23, data_33
	);
}

Matrix3 Matrix3::operator-() const
{
	return Matrix3(
		-data_11, -data_12, -data_13,
		-data_21, -data_22, -data_23,
		-data_31, -data_32, -data_33
	);
}

Vector3 operator*(const Matrix3& m, const Vector3& v)
{
	return Vector3(v.x * m.data_11 + v.y * m.data_12 + v.z * m.data_13, v.x * m.data_21 + v.y * m.data_22 + v.z * m.data_23, v.x * m.data_31 + v.y * m.data_32 + v.z * m.data_33);
}

Vector3 operator*(const Vector3& v, const Matrix3& m)
{
	return Vector3(v.x * m.data_11 + v.y * m.data_21 + v.z * m.data_31, v.x * m.data_12 + v.y * m.data_22 + v.z * m.data_32, v.x * m.data_13 + v.y * m.data_23 + v.z * m.data_33);
}

Vector3 operator*=(Vector3& v, const Matrix3& m)
{
	return v = v * m;
}