#pragma once
#include "Vector3.h"
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator+(const Vector2& rhs);
	Vector2 operator*(const float rhs);
	Vector2 operator-(const Vector2& rhs);
	Vector2 operator+=(const Vector2& rhs);
	float dot(const Vector2& rhs);
	float& operator[](const int rhs); //subscript operator returning with reference
	float normalise();
	float magnitude();
	operator float*();

	Vector2 operator/(const Vector2& rhs);
	Vector2 normailsed(Vector2& data);
	Vector2 min(const Vector2& rhs);
	Vector2 max(const Vector2& rhs);
	Vector2 clamp(Vector2 min, Vector2 max);
	Vector2 lerp(Vector2& a, Vector2& b, float& t);
	bool operator<(const Vector2& rhs);  //smaller than operator 
	bool operator>(const Vector2& rhs);  //greater than operator
	bool operator>=(const Vector2& rhs); //greater than or equal to operator 
	bool operator<=(const Vector2& rhs); //smaller than or equal to operator 
	bool operator==(const Vector2& rhs); //equal to operator
	bool operator!=(const Vector2& rhs); //copy Vectors - not equal 
	float distance(const Vector2& p1, const Vector2& p2);					//help!
	float magnitudeSqrt();

	float x;
	float y;
};

Vector2 operator*(const float lhs, const Vector2& rhs);
Vector2 operator/(const float lhs, const Vector2& rhs);