#include "Matrix.h"
#include "Vector.h"

template<typename T>
Matrix2<T>::Matrix2<T>(T a11, T a12, T a21, T a22)
{
	data[0][0] = a11;
	data[1][0] = a21;
	data[0][1] = a12;
	data[1][1] = a22;
}

template<typename T>
Matrix2<T>::Matrix2<T>(Vector2<T> v1, Vector2<T> v2)
{
	data[0][0] = v1.x;
	data[0][1] = v1.y;
	data[1][0] = v2.x;
	data[1][0] = v2.y;
}

template<typename T>
Matrix2<T> Matrix2<T>::operator+(Matrix2<T> m)
{
	return Matrix2<T>(
		data[0][0] + m[0][0], data[0][1] + m[0][1],
		data[1][0] + m[1][0], data[1][1] + m[1][1]
	);
}

template<typename T>
Matrix2<T> Matrix2<T>::operator-(Matrix2<T> m)
{
	return Matrix2<T>(
		data[0][0] - m[0][0], data[0][1] - m[0][1],
		data[1][0] - m[1][0], data[1][1] - m[1][1]
	);
}

template<typename T>
Matrix2<T> Matrix2<T>::operator*(Matrix2<T> m)
{
	return Matrix2<T>(
		data[0][0] * m[0][0] + data[0][1] * m[1][0], data[0][0] * m[0][1] + data[0][1] * m[1][1],
		data[1][0] * m[0][0] + data[1][1] * m[1][0], data[1][0] * m[0][1] + data[1][1] * m[1][1]
	);
}

template<typename T>
Vector2<T> Matrix2<T>::operator*(Vector2<T> v)
{
	return Vector2<T>(
		data[0][0] * v.x + data[0][1] * v.y,
		data[1][0] * v.x + data[1][1] * v.y
		);
}

template<typename T>
Matrix2<T> Matrix2<T>::operator*(T s)
{
	return Matrix2<T>(
		data[0][0] * s, data[0][1] * s,
		data[1][0] * s, data[1][1] * s
	);
}

template<typename T>
T* Matrix2<T>::operator[](int r)
{
	return data[r];
}