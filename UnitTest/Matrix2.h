#pragma once
#include "Vector2.h"
class Matrix2
{
public:
	Matrix2(float a, float b, float c, float d);
	Matrix2();
	~Matrix2();

	Matrix2 operator*(const Matrix2& rhs); //M * M
	Vector2 operator*(const Vector2& rhs); //V * M
<<<<<<< HEAD
	Vector2& operator[](const int rhs); // subscript operator returning with reference
	float det2(float a, float b, float c, float d);
	bool isIdentity();
	void transpose();
=======
	Vector2 operator[](const int rhs); // subscript operator returning with reference
	Vector2 hermite(Vector2 p1, Vector2 tan1, Vector2 p2, Vector2 tan2, float t);
>>>>>>> origin/master
	void setRotate(const float a); // set rotate
	void setScale(float x, float y);



	operator float*();

	union
	{
		float m[4];
		float a[2][2];
	};
};
