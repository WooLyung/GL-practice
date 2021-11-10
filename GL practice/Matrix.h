#pragma once
template<typename T = float>
class Vector2;

template<typename T = float>
class Matrix2
{
private:
	T data[2][2];

public:
	// 생성자
	Matrix2<T>(T, T, T, T);
	Matrix2<T>(Vector2<T>, Vector2<T>);

	// 행렬-행렬 연산
	Matrix2<T> operator+(Matrix2<T>);
	Matrix2<T> operator-(Matrix2<T>);
	Matrix2<T> operator*(Matrix2<T>);

	// 행렬-벡터 연산
	Vector2<T> operator*(Vector2<T>);

	// 행렬-스칼라 연산
	Matrix2<T> operator*(T);

	//// 행렬-행렬 대입 연산
	//Matrix2<T> operator+=(Matrix2<T>);
	//Matrix2<T> operator-=(Matrix2<T>);
	//Matrix2<T> operator*=(Matrix2<T>);

	//// 행렬-벡터 대입 연산
	//Matrix2<T> operator*=(Vector2<T>);

	//// 행렬-스칼라 대입 연산
	//Matrix2<T> operator*=(T);

	// 단항 연산
	T* operator[](int);
};

typedef Matrix2<float> mat2;