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

void Matrix2::setRotate(const float a)
{
	m[0] = cosf(a);
	m[1] = sinf(a);
	m[2] = -sinf(a);
	m[3] = cosf(a);
}

Matrix2::operator float*()
{
	return &m[0];
}

Matrix2 Matrix2::operator*(const Matrix2& rhs) // M * M
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
	result.x = m[0] * rhs.x + m[2] * rhs.y; // M * V
	result.y = m[1] * rhs.x + m[3] * rhs.y;
	return result;
}

Vector2 Matrix2::operator[](const int rhs)
{
	return *(Vector2*)(m + 2 * rhs); 
}

void Matrix2::setScale(float x, float y)
{
	m[0] = x;
	m[1] = 0;
	m[2] = 0;
	m[3] = y;
}

<<<<<<< HEAD
float Matrix2::det2(float a, float b, float c, float d) 
{
	m[0] = a;
	m[1] = b;
	m[2] = c;
	m[3] = d;

	return (a * d - b * c);
}

bool Matrix2::isIdentity()
{
	int count = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (m[i] == 1 && i % 5 == 0)
			++count;
		else if (m[i] == 0)
			++count;
	}

	if (count == 4)
		return true;

	return false;
}
void Matrix2::transpose()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			a[i][j] = a[j][i];
		}
	}
=======
Vector2 Matrix2::hermite(Vector2 p1, Vector2 tan1, Vector2 p2, Vector2 tan2, float t)
{
	float tSquare = t * t;
	float tCube = tSquare * t;

	float h00 = 2 * tCube - 3 * tSquare + 1;
	float h01 = -2 * tCube + 3 * tSquare;
	float h10 = tCube - 2 * tSquare + t;
	float h11 = tCube - tSquare;

	return h00 * p1 + h10 * tan1 + h01 * p2 + h11 * tan2;
>>>>>>> origin/master
}