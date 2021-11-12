#pragma once

typedef class Vector2
{
public:
	float x, y;

	// »ý¼ºÀÚ
	Vector2();
	Vector2(float, float);

	// º¤ÅÍ-º¤ÅÍ ¿¬»ê
	Vector2 operator+(const Vector2&) const;
	Vector2 operator-(const Vector2&) const;
	Vector2 operator+=(const Vector2&);
	Vector2 operator-=(const Vector2&);
	float operator*(const Vector2&) const;
	bool operator==(const Vector2&) const;
	bool operator!=(const Vector2&) const;

	// º¤ÅÍ-½ºÄ®¶ó ¿¬»ê
	Vector2 operator*(const float&) const;
	Vector2 operator/(const float&) const;
	Vector2 operator*=(const float&);
	Vector2 operator/=(const float&);
} vec2;