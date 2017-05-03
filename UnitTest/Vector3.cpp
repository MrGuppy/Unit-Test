#include "Vector3.h"
#include <math.h>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::~Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	return result;
}

Vector3 Vector3::operator+=(const Vector3& rhs)
{
	Vector3 result;
	result.x += rhs.x;
	result.y += rhs.y;
	result.z += rhs.z;
	return result;
}

Vector3 Vector3::operator*(const float rhs)
{
	Vector3 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	return result;
}

Vector3 operator*(const float lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	return result;
}

Vector3 operator/(const float lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	return result;
}

Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	return result;
}

Vector3 Vector3::operator/(const Vector3& rhs)
{
	Vector3 result;
	result.x = x / rhs.x;
	result.y = y / rhs.y;
	result.z = z / rhs.z;
	return result;
}

float Vector3::magnitude()
{
	float result;
	result = sqrtf((x * x) + (y * y) + (z * z));
	return result;
}

Vector3::operator float*()
{
	return &x;
}

float Vector3::dot(const Vector3 rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z;
	return result;
}

float Vector3::normalise()
{
	float mag = magnitude();
	x = x / mag;
	y = y / mag;
	z = z / mag;
	return mag;
}

Vector3 Vector3::cross(const Vector3& rhs)
{
	Vector3 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	return result;
}

Vector3 operator/(const float & lhs, const Vector3 rhs)
{
	Vector3 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	return result;
}

float& Vector3::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	if (rhs == 1)
		return y;
	if (rhs == 2)
		return z;
	else
		return x;
}

Vector3 Vector3::normalised(Vector3& data)
{
	Vector3 result;
	float mag = data.magnitude();
	if (!mag == 0)
	{
		result.x = x / mag;
		result.y = y / mag;
		result.z = z / mag;
		return result;
	}
	return result;
}

Vector3 Vector3::max(const Vector3& rhs)
{
	Vector3 result;
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
	return result;
}

Vector3 Vector3::min(const Vector3& rhs)
{
	Vector3 result;
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

	return result;
}

Vector3 Vector3::clamp(Vector3 min, Vector3 max)
{
	Vector3 result;

	result = this->min(min);
	result = result.max(max);

	return result;
}

Vector3 Vector3::lerp(Vector3& a, Vector3& b, float& t)
{
	return (a + b) * t;
}

bool Vector3::operator!=(const Vector3& rhs)
{
	return (x != rhs.x && y != rhs.y && z != rhs.z);
}

bool Vector3::operator<(const Vector3& rhs)
{
	return (x < rhs.x && y < rhs.y && z < rhs.z);
}

bool Vector3::operator>(const Vector3& rhs)
{
	return (x > rhs.x && y > rhs.y && z > rhs.z);
}

bool Vector3::operator>=(const Vector3& rhs)
{
	return (x >= rhs.x && y >= rhs.y && z >= rhs.z);
}

bool Vector3::operator<=(const Vector3& rhs)
{
	return (x <= rhs.x && y <= rhs.y && z <= rhs.z);
}

bool Vector3::operator==(const Vector3& rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

float Vector3::distance(const Vector3& p1, const Vector3& p2) //check 
{
	float diffx = p1.x - p2.x;
	float diffy = p1.y - p2.y;
	float diffz = p1.z - p2.z;
	return sqrtf((diffx * diffx) + (diffy * diffy) + (diffz * diffz));
}

float Vector3::magnitudeSqrt() //ask richard sqrtf
{
	float result;
	result = (x * x + y * y + z * z);
	return result;
}