#pragma once
template<typename T = float>
class Vector2;

template<typename T = float>
class Matrix2
{
private:
	T data[2][2];

public:
	// ������
	Matrix2<T>(T, T, T, T);
	Matrix2<T>(Vector2<T>, Vector2<T>);

	// ���-��� ����
	Matrix2<T> operator+(Matrix2<T>);
	Matrix2<T> operator-(Matrix2<T>);
	Matrix2<T> operator*(Matrix2<T>);

	// ���-���� ����
	Vector2<T> operator*(Vector2<T>);

	// ���-��Į�� ����
	Matrix2<T> operator*(T);

	//// ���-��� ���� ����
	//Matrix2<T> operator+=(Matrix2<T>);
	//Matrix2<T> operator-=(Matrix2<T>);
	//Matrix2<T> operator*=(Matrix2<T>);

	//// ���-���� ���� ����
	//Matrix2<T> operator*=(Vector2<T>);

	//// ���-��Į�� ���� ����
	//Matrix2<T> operator*=(T);

	// ���� ����
	T* operator[](int);
};

typedef Matrix2<float> mat2;