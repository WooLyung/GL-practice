#include "Matrix.h"

const Matrix4 Matrix4::one = Matrix4(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
const Matrix4 Matrix4::zero = Matrix4(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
const Matrix4 Matrix4::identity = Matrix4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

Matrix4::Matrix4()
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

Matrix4::Matrix4(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44)
{
	data_11 = a11;
	data_12 = a12;
	data_13 = a13;
	data_14 = a14;
	data_21 = a21;
	data_22 = a22;
	data_23 = a23;
	data_24 = a24;
	data_31 = a31;
	data_32 = a32;
	data_33 = a33;
	data_34 = a34;
	data_41 = a41;
	data_42 = a42;
	data_43 = a43;
	data_44 = a44;
}

Matrix4::Matrix4(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4)
{
	data_11 = v1.x;
	data_12 = v1.y;
	data_13 = v1.z;
	data_14 = v1.w;
	data_21 = v2.x;
	data_22 = v2.y;
	data_23 = v2.z;
	data_24 = v2.w;
	data_31 = v3.x;
	data_32 = v3.y;
	data_33 = v3.z;
	data_34 = v3.w;
	data_41 = v4.x;
	data_42 = v4.y;
	data_43 = v4.z;
	data_44 = v4.w;
}

Matrix4 Matrix4::operator+(const Matrix4& m) const
{
	return Matrix4(
		m.data_11 + data_11, m.data_12 + data_12, m.data_13 + data_13, m.data_14 + data_14,
		m.data_21 + data_21, m.data_22 + data_22, m.data_23 + data_23, m.data_24 + data_24,
		m.data_31 + data_31, m.data_32 + data_32, m.data_33 + data_33, m.data_34 + data_34,
		m.data_41 + data_41, m.data_42 + data_42, m.data_43 + data_43, m.data_44 + data_44
	);
}

Matrix4 Matrix4::operator-(const Matrix4& m) const
{
	return Matrix4(
		data_11 - m.data_11, data_12 - m.data_12, data_13 - m.data_13, data_14 - m.data_14,
		data_21 - m.data_21, data_22 - m.data_22, data_23 - m.data_23, data_24 - m.data_24,
		data_31 - m.data_31, data_32 - m.data_32, data_33 - m.data_33, data_34 - m.data_34,
		data_41 - m.data_41, data_42 - m.data_42, data_43 - m.data_43, data_44 - m.data_44
	);
}

Matrix4 Matrix4::operator*(const Matrix4& m) const
{
	return Matrix4(
		data_11 * m.data_11 + data_12 * m.data_21 + data_13 * m.data_31 + data_14 * m.data_41, data_11 * m.data_12 + data_12 * m.data_22 + data_13 * m.data_32 + data_14 * m.data_42, data_11 * m.data_13 + data_12 * m.data_23 + data_13 * m.data_33 + data_14 * m.data_43, data_11 * m.data_14 + data_12 * m.data_24 + data_13 * m.data_34 + data_14 * m.data_44,
		data_21 * m.data_11 + data_22 * m.data_21 + data_23 * m.data_31 + data_24 * m.data_41, data_21 * m.data_12 + data_22 * m.data_22 + data_23 * m.data_32 + data_24 * m.data_42, data_21 * m.data_13 + data_22 * m.data_23 + data_23 * m.data_33 + data_24 * m.data_43, data_21 * m.data_14 + data_22 * m.data_24 + data_23 * m.data_34 + data_24 * m.data_44,
		data_31 * m.data_11 + data_32 * m.data_21 + data_33 * m.data_31 + data_34 * m.data_41, data_31 * m.data_12 + data_32 * m.data_22 + data_33 * m.data_32 + data_34 * m.data_42, data_31 * m.data_13 + data_32 * m.data_23 + data_33 * m.data_33 + data_34 * m.data_43, data_31 * m.data_14 + data_32 * m.data_24 + data_33 * m.data_34 + data_34 * m.data_44,
		data_41 * m.data_11 + data_42 * m.data_21 + data_43 * m.data_31 + data_44 * m.data_41, data_41 * m.data_12 + data_42 * m.data_22 + data_43 * m.data_32 + data_44 * m.data_42, data_41 * m.data_13 + data_42 * m.data_23 + data_43 * m.data_33 + data_44 * m.data_43, data_41 * m.data_14 + data_42 * m.data_24 + data_43 * m.data_34 + data_44 * m.data_44
	);
}

Matrix4 Matrix4::operator+=(const Matrix4& m)
{
	return *this = *this + m;
}

Matrix4 Matrix4::operator-=(const Matrix4& m)
{
	return *this = *this - m;
}

Matrix4 Matrix4::operator*=(const Matrix4& m)
{
	return *this = *this * m;
}

bool Matrix4::operator==(const Matrix4& m) const
{
	return m.data_11 == data_11 &&
		m.data_12 == data_12 &&
		m.data_13 == data_13 &&
		m.data_14 == data_14 &&
		m.data_21 == data_21 &&
		m.data_22 == data_22 &&
		m.data_23 == data_23 &&
		m.data_24 == data_24 &&
		m.data_31 == data_31 &&
		m.data_32 == data_32 &&
		m.data_33 == data_33 &&
		m.data_34 == data_34 &&
		m.data_41 == data_41 &&
		m.data_42 == data_42 &&
		m.data_43 == data_43 &&
		m.data_44 == data_44;
}

bool Matrix4::operator!=(const Matrix4& m) const
{
	return !(*this == m);
}

Matrix4 Matrix4::operator*(const float& i) const
{
	return Matrix4(
		data_11 * i, data_12 * i, data_13 * i, data_14 * i,
		data_21 * i, data_22 * i, data_23 * i, data_24 * i,
		data_31 * i, data_32 * i, data_33 * i, data_34 * i,
		data_41 * i, data_42 * i, data_43 * i, data_44 * i
	);
}

Matrix4 Matrix4::operator*=(const float& i)
{
	return *this = *this * i;
}

Matrix4 Matrix4::operator/(const float& i) const
{
	return Matrix4(
		data_11 / i, data_12 / i, data_13 * i, data_14 / i,
		data_21 / i, data_22 / i, data_23 * i, data_24 / i,
		data_31 / i, data_32 / i, data_33 * i, data_34 / i,
		data_41 / i, data_42 / i, data_43 * i, data_44 / i
	);
}

Matrix4 Matrix4::operator/=(const float& i)
{
	return *this = *this / i;
}

float& Matrix4::operator()(const int& row, const int& col)
{
	switch (row)
	{
	case 1:
		switch (col)
		{
		case 1: return data_11;
		case 2: return data_12;
		case 3: return data_13;
		case 4: return data_14;
		}
	case 2:
		switch (col)
		{
		case 1: return data_21;
		case 2: return data_22;
		case 3: return data_23;
		case 4: return data_24;
		}
	case 3:
		switch (col)
		{
		case 1: return data_31;
		case 2: return data_32;
		case 3: return data_33;
		case 4: return data_34;
		}
	case 4:
		switch (col)
		{
		case 1: return data_41;
		case 2: return data_42;
		case 3: return data_43;
		case 4: return data_44;
		}
	}
	return data_11;
}

Matrix4 Matrix4::operator~() const
{
	return Matrix4(
		data_11, data_21, data_31, data_41,
		data_12, data_22, data_32, data_42,
		data_13, data_23, data_33, data_43,
		data_14, data_24, data_34, data_44
	);
}

Matrix4 Matrix4::operator-() const
{
	return Matrix4(
		-data_11, -data_12, -data_13, -data_14,
		-data_21, -data_22, -data_23, -data_24,
		-data_31, -data_32, -data_33, -data_34,
		-data_41, -data_42, -data_43, -data_44
	);
}

Vector4 operator*(const Matrix4& m, const Vector4& v)
{
	return Vector4(v.x * m.data_11 + v.y * m.data_12 + v.z * m.data_13 + v.w * m.data_14, v.x * m.data_21 + v.y * m.data_22 + v.z * m.data_23 + v.w * m.data_24, v.x * m.data_31 + v.y * m.data_32 + v.z * m.data_33 + v.w * m.data_34, v.x * m.data_41 + v.y * m.data_42 + v.z * m.data_43 + v.w * m.data_44);
}

Vector4 operator*(const Vector4& v, const Matrix4& m)
{
	return Vector4(v.x * m.data_11 + v.y * m.data_21 + v.z * m.data_31 + v.w * m.data_41, v.x * m.data_12 + v.y * m.data_22 + v.z * m.data_32 + v.w * m.data_42, v.x * m.data_13 + v.y * m.data_23 + v.z * m.data_33 + v.w * m.data_43, v.x * m.data_14 + v.y * m.data_24 + v.z * m.data_34 + v.w * m.data_44);
}

Vector4 operator*=(Vector4& v, const Matrix4& m)
{
	return v = v * m;
}