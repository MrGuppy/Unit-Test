#include "Matrix2.h"
#include <math.h>


Matrix2::Matrix2(float a, float b, float c, float d)
{
	m[0] = a;
	m[1] = b;
	m[2] = c;
	m[3] = d;

}

Matrix2::Matrix2()
{
	m[0] = 1; 
	m[1] = 0;
	m[2] = 0;
	m[3] = 1;
}

Matrix2::~Matrix2()
{
}

Matrix2 Matrix2::setRotate(const float a)
{
	m[0] = cos(a);
	m[1] = sin(a);
	m[2] = -sin(a);
	m[3] = cos(a);
}

Matrix2::operator float*()
{
	return &m[0];
}

Matrix2 Matrix2::operator*(const Matrix2& rhs)
{
	Matrix2 result;
	result.m[0] = m[0] * rhs.m[0] + m[2] * rhs.m[1];
	result.m[1] = m[1] * rhs.m[0] + m[3] * rhs.m[1];
	result.m[2] = m[0] * rhs.m[2] + m[2] * rhs.m[3];
	result.m[3] = m[1] * rhs.m[2] + m[3] * rhs.m[3];
	return result;
}

Vector2 Matrix2::operator*(const Vector2& rhs)
{
	Vector2 result;
	result.x = m[0] * rhs.x + m[1] * rhs.y;
	result.y = m[2] * rhs.x + m[3] * rhs.y;
	return result;
}

Vector2& Matrix2::operator[](const int rhs)
{
	return *(Vector2*)(m + 2 * rhs);
}

