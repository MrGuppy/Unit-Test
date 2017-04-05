#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	Matrix3();
	~Matrix3();

	Matrix3 operator*(const Matrix3& rhs);
	Vector3 operator*(const Vector3& rhs);

	Vector3& operator[](const int rhs);

	Matrix3 setRotateX(const float a);
	Matrix3 setRotateY(const float a);
	Matrix3 setRoataeZ(const float a);

	operator float*();
	
	//float fp v cast operator
	//float fp m cast operator

	float m[9];
};

