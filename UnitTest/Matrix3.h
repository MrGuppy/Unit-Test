#pragma once
#include "Vector3.h"
#include "Vector2.h"
class Matrix3
{
public:
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	Matrix3();
	~Matrix3();

	Matrix3 operator*(const Matrix3& rhs);
	Vector3 operator*(const Vector3& rhs);
	Vector3& operator[](const int rhs);
	bool isIdentity();
	void transpose();
	float det3();

	Vector2 getScale();
	void setScale(float x, float y, float z);

	Vector2 getPos();
	void setPos(const Vector2& pos);
	void setRotateX(const float a);
	void setRotateY(const float a);
	void setRotateZ(const float a);

	operator float*();
	
	//float fp v cast operator
	//float fp m cast operator

	union
	{
		float m[9];
		float a[3][3];
	};

};

