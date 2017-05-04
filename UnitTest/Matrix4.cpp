#include "Matrix4.h"
#include <math.h>
#include "VectorClassing.h"

Matrix4::Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float f_m, float n, float o, float p)
{
	m[0] = a;
	m[1] = b;
	m[2] = c;
	m[3] = d;
	m[4] = e;
	m[5] = f;
	m[6] = g;
	m[7] = h;
	m[8] = i;
	m[9] = j;
	m[10] = k;
	m[11] = l;
	m[12] = f_m;
	m[13] = n;
	m[14] = o;
	m[15] = p;
}

Matrix4::Matrix4()
{
	m[0] = 1; //col 1
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;

	m[4] = 0; //col 2
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;

	m[8] = 0; //col 3
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;

	m[12] = 0; //col 4
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

void Matrix4::setRotateX(const float a)
{
	m[0] = 1; //col 1
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;

	m[4] = 0; //col 2
	m[5] = cosf(a);
	m[6] = sinf(a);
	m[7] = 0;


	m[8] = 0; //col 3
	m[9] = -sinf(a);
	m[10] = cosf(a);
	m[11] = 0;

	m[12] = 0; //col 4
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

void Matrix4::setRotateY(const float a)
{
	m[0] = cosf(a); //col 1
	m[1] = 0;
	m[2] = -sinf(a);
	m[3] = 0;

	m[4] = 0; //col 2
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;

	m[8] = sinf(a); //col 3
	m[9] = 0;
	m[10] = cosf(a);
	m[11] = 0;

	m[12] = 0; //col 4
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

void Matrix4::setRotateZ(const float a)
{
	m[0] = cosf(a); //col 1
	m[1] = sinf(a);
	m[2] = 0;
	m[3] = 0;

	m[4] = -sinf(a); //col 2
	m[5] = cosf(a);
	m[6] = 0;
	m[7] = 0;

	m[8] = 0; //col 3
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;

	m[12] = 0; //col 4
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

void Matrix4::setRotateW()
{
	m[15] = 1;
}

Matrix4::operator float*()
{
	return &m[0];
}

Matrix4::~Matrix4()
{
}

void Matrix4::lookAt(Vector3 from, Vector3 look, Vector3 up)
{
	Vector3 zAxis = from - look;
	zAxis.normalise();

	Vector3 xAxis = zAxis.cross(up);
	xAxis.normalise();

	Vector3 yAxis = xAxis.cross(zAxis);
	yAxis.normalise();

	(*this)[0] = CastTo<Vector4>(xAxis);
	(*this)[1] = CastTo<Vector4>(yAxis);
	(*this)[2] = CastTo<Vector4>(zAxis);
	(*this)[3] = CastTo<Vector4>(from);

	m[15] = 1;
}

Matrix4 Matrix4::operator*(const Matrix4 & rhs)
{
	Matrix4 result;
	result.m[0] = m[0] * rhs.m[0] + m[4] * rhs.m[1] + m[8] * rhs.m[2] + m[12] * rhs.m[3];
	result.m[1] = m[1] * rhs.m[0] + m[5] * rhs.m[1] + m[9] * rhs.m[2] + m[13] * rhs.m[3];
	result.m[2] = m[2] * rhs.m[0] + m[6] * rhs.m[1] + m[10] * rhs.m[2] + m[14] * rhs.m[3];
	result.m[3] = m[3] * rhs.m[0] + m[7] * rhs.m[1] + m[11] * rhs.m[2] + m[15] * rhs.m[3];

	result.m[4] = m[0] * rhs.m[4] + m[4] * rhs.m[5] + m[8] * rhs.m[6] + m[12] * rhs.m[7];
	result.m[5] = m[1] * rhs.m[4] + m[5] * rhs.m[5] + m[9] * rhs.m[6] + m[13] * rhs.m[7];
	result.m[6] = m[2] * rhs.m[4] + m[6] * rhs.m[5] + m[10] * rhs.m[6] + m[14] * rhs.m[7];
	result.m[7] = m[3] * rhs.m[4] + m[6] * rhs.m[5] + m[11] * rhs.m[6] + m[15] * rhs.m[7];

	result.m[8] = m[0] * rhs.m[8] + m[4] * rhs.m[9] + m[8] * rhs.m[10] + m[12] * rhs.m[11];
	result.m[9] = m[1] * rhs.m[8] + m[5] * rhs.m[9] + m[9] * rhs.m[10] + m[13] * rhs.m[11];
	result.m[10] = m[2] * rhs.m[8] + m[6] * rhs.m[9] + m[10] * rhs.m[10] + m[14] * rhs.m[11];
	result.m[11] = m[3] * rhs.m[8] + m[7] * rhs.m[9] + m[11] * rhs.m[10] + m[15] * rhs.m[11];

	result.m[12] = m[0] * rhs.m[12] + m[4] * rhs.m[13] + m[8] * rhs.m[14] + m[12] * rhs.m[15];
	result.m[13] = m[1] * rhs.m[12] + m[5] * rhs.m[13] + m[9] * rhs.m[14] + m[13] * rhs.m[15];
	result.m[14] = m[2] * rhs.m[12] + m[6] * rhs.m[13] + m[10] * rhs.m[14] + m[14] * rhs.m[15];
	result.m[15] = m[3] * rhs.m[12] + m[7] * rhs.m[13] + m[11] * rhs.m[14] + m[15] * rhs.m[15];

	return result;
}

Vector4 Matrix4::operator*(const Vector4& rhs)
{
	Vector4 result;
	result.x = m[0] * rhs.x + m[4] * rhs.y + m[8] * rhs.z + m[12] * rhs.w;
	result.y = m[1] * rhs.x + m[5] * rhs.y + m[9] * rhs.z + m[13] * rhs.w;
	result.z = m[2] * rhs.x + m[6] * rhs.y + m[10] * rhs.z + m[14] * rhs.w;
	result.w = m[3] * rhs.x + m[7] * rhs.y + m[11] * rhs.z + m[15] * rhs.w;
	return result;
}

Vector4& Matrix4::operator[](const int rhs)
{
	return *(Vector4*) (m + 4 * rhs);
}

void Matrix4::setScale(float x, float y, float z, float w)
{
	m[0] = x; //col 1
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;

	m[4] = 0; //col 2
	m[5] = y;
	m[6] = 0;
	m[7] = 0;

	m[8] = 0; //col 3
	m[9] = 0;
	m[10] = z;
	m[11] = 0;

	m[12] = 0; //col 4
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

<<<<<<< HEAD
float Matrix4::det4()
{	
	float resA = m[0] * (m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[6] * m[9] * m[15] + m[6] * m[11] * m[13] + m[7] * m[9] * m[14] - m[7] * m[10] * m[13]);
	float resB = m[1] * (m[4] * m[10] * m[15] - m[4] * m[11] * m[14] - m[6] * m[8] * m[15] + m[6] * m[11] * m[12] + m[7] * m[8] * m[14] - m[7] * m[10] * m[12]);
	float resC = m[2] * (m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[5] * m[8] * m[15] + m[5] * m[11] * m[12] + m[7] * m[8] * m[13] - m[7] * m[9] * m[12]);
	float resD = m[3] * (m[4] * m[9] * m[14] - m[4] * m[10] * m[13] - m[5] * m[8] * m[14] + m[5] * m[10] * m[12] + m[6] * m[8] * m[13] - m[6] * m[9] * m[12]);

	return resA - resB + resC - resD;
}

bool Matrix4::isIdentity()
{
	int count = 0;
	for (int i = 0; i < 16; ++i)
	{
		if (m[i] == 1 && i % 5 == 0)
			++count;
		else if (m[i] == 0)
			++count;
	}

	if (count == 16)
		return true;

	return false;
}
void Matrix4::transpose()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			a[i][j] = a[j][i];
		}
	}
}
=======
Vector3 Matrix4::getScale()
{
	Vector3 result; 
	result.x = m[0];
	result.y = m[4];
	result.z = m[8];
	return result;
}

void Matrix4::setPos(const Vector3& pos) //GETTING VECTOR2 INFORMATION	
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;

	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;

	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;

	m[11] = pos.x;
	m[12] = pos.y;
	m[13] = pos.z;
	m[14] = 1;

}

Vector3 Matrix4::getPos()
{
	Vector3 result;
	result.x = m[11];
	result.y = m[12];
	result.z = m[13];
	return result;
}
>>>>>>> origin/master
