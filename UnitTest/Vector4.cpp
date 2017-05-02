#include "Vector4.h"
#include <math.h>

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::~Vector4()
{
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4 Vector4::operator+(const Vector4& rhs)
{
	Vector4 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;
	return result;
}

Vector4 Vector4::operator+=(const Vector4& rhs)
{
	Vector4 result;
	result.x += rhs.x;
	result.y += rhs.y;
	result.z += rhs.z;
	result.w += rhs.w;
	return result;
}

Vector4 Vector4::operator*(const float rhs)
{
	Vector4 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w * rhs;
	return result;
}

Vector4 operator*(const float lhs, const Vector4& rhs)
{
	Vector4 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;
	return result;
}

Vector4 operator/(const float lhs, const Vector4 & rhs)
{
	Vector4 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	result.w = lhs / rhs.w;
	return result;
}

Vector4 Vector4::operator-(const Vector4& rhs)
{
	Vector4 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w - rhs.w;
	return result;

}

Vector4 Vector4::operator/(const Vector4& rhs)
{
	Vector4 result;
	result.x = x / rhs.x;
	result.y = y / rhs.y;
	result.z = z / rhs.z;
	result.w = w / rhs.w;
	return result;
}

float Vector4::magnitude()
{
	float result;
	result = sqrtf((x * x) + (y * y) + (z * z) + (w * w));
	return result;
}

Vector4::operator float*()
{
	return &x;
}

float Vector4::dot(const Vector4 rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	return result;
}

float Vector4::normalise()
{
	float mag = magnitude();
	x = x / mag;
	y = y / mag;
	z = z / mag;
	w = w / mag;
	return mag;
}

Vector4 operator/(const float & lhs, const Vector4 rhs)
{
	Vector4 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	result.w = lhs / rhs.w;
	return result;
}

Vector4 Vector4::cross(const Vector4& rhs)
{
	Vector4 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	result.w = 0;
	return result;
}

float& Vector4::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	if (rhs == 1)
		return y;
	if (rhs == 2)
		return z;
	if (rhs == 3)
		return w;
	else
		return x;
}

Vector4 Vector4::normalised(Vector4& data)
{
	Vector4 result;
	float mag = data.magnitude();
	if (!mag == 0)
	{
		result.x = x / mag;
		result.y = y / mag;
		result.z = z / mag;
		result.w = w / mag;
		return result;
	}
	return result;
}

Vector4 Vector4::min(const Vector4& rhs)
{
	Vector4 result;
	if (x < rhs.x)
		result.x = x;
	else
		result.x = x;

	if (y < rhs.y)
		result.y = y;
	else
		result.y = y;

	if (z < result.z)
		result.z = z;
	else
		result.z = z;

	if (w < result.w)
		result.w = w;
	else
		result.w = w;

	return result;
}

Vector4 Vector4::max(const Vector4& rhs)
{
	Vector4 result;
	if (x > rhs.x)
		result.x = x;
	else
		result.x = x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = y;

	if (z > result.z)
		result.z = z;
	else
		result.z = z;

	if (w > result.w)
		result.w = w;
	else
		result.w = w;

	return result;
}

Vector4 Vector4::clamp(Vector4 min, Vector4 max)
{
	Vector4 result;

	result = this->min(min);
	result = result.max(max);

	return result;
}