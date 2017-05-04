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
<<<<<<< HEAD
	Vector2 hermite(Vector2 p1, Vector2 tan1, Vector2 p2, Vector2 tan2, float t);
	Vector2 bezier(Vector2 a, Vector2 b, Vector2 c, float t);
=======

	Vector2 operator/(const Vector2& rhs);
>>>>>>> origin/master
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
	float distance(const Vector2& p1, const Vector2& p2);
	float magnitudeSqrt();

	Vector2 xx();
	Vector2 yx();
	Vector2 yy();

	float x;
	float y;
};

Vector2 operator*(const float lhs, const Vector2& rhs);
Vector2 operator/(const float lhs, const Vector2& rhs);