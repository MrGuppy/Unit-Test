#pragma once
#include "Vector4.h"
#include "Vector3.h"
class Matrix4
{
public:
	Matrix4(float a, float b, float c, float d, 
			float e, float f, float g, float h,
			float i, float j, float k, float l,
			float f_m, float n, float o, float p);
	Matrix4();
	~Matrix4();
	bool isIdentity();
	void lookAt(Vector3 from, Vector3 look, Vector3 up);
	Matrix4 operator*(const Matrix4& rhs);
	Vector4 operator*(const Vector4& rhs);
	Vector4& operator[](const int rhs);
	float det4();
	void setScale(float x, float y, float z, float w);
	void setRotateX(const float a);
	void setRotateY(const float a);
	void setRotateZ(const float a);
	void setRotateW();
	void transpose();
	operator float*();

	union
	{
		float m[16];
		float a[4][4];
	};
};