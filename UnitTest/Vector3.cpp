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

Vector3 Vector3::hermite(Vector3 p1, Vector3 tan1, Vector3 p2, Vector3 tan2, float t)
{
	float tSquare = t * t;
	float tCube = tSquare * t;
	float h00 = 2 * tCube - 3 * tSquare + 1;
	float h01 = -2 * tCube + 3 * tSquare;
	float h10 = tCube - 2 * tSquare + t;
	float h11 = tCube - tSquare;

	return h00 * p1 + h10 * tan1 + h01 * p2 + h11 * tan2;
}

Vector3 Vector3::bezier(Vector3 a, Vector3 b, Vector3 c, float t)
{
	Vector3 mid1 = lerp(a, b, t);
	Vector3 mid2 = lerp(b, c, t);

	return lerp(mid1, mid2, t);
}

Vector3 Vector3::zxx()
{
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = x;
	return result;
}
Vector3 Vector3::zxy()
{
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = y;
	return result;
}
Vector3 Vector3::zxz()
{
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = z;
	return result;
}
Vector3 Vector3::zyx()
{
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = x;
	return result;
}
Vector3 Vector3::zyy()
{
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = y;
	return result;
}
Vector3 Vector3::zyz()
{
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = z;
	return result;
}
Vector3 Vector3::zzx()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = x;
	return result;
}
Vector3 Vector3::zzy()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = y;
	return result;
}
Vector3 Vector3::zzz()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = z;
	return result;
}
Vector3 Vector3::yxx()
{
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = x;
	return result;
}
Vector3 Vector3::yxy()
{
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = y;
	return result;
}
Vector3 Vector3::yxz()
{
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = z;
	return result;
}
Vector3 Vector3::yyx()
{
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = x;
	return result;
}
Vector3 Vector3::yyy()
{
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = y;
	return result;
}
Vector3 Vector3::yyz()
{
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = z;
	return result;
}
Vector3 Vector3::yzx()
{
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = x;
	return result;
}
Vector3 Vector3::yzy()
{
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = y;
	return result;
}
Vector3 Vector3::yzz()
{
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = z;
	return result;
}
Vector3 Vector3::xxx()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = x;
	return result;
}

Vector3 Vector3::xxy()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = y;
	return result;
}
Vector3 Vector3::xxz()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = z;
	return result;
}
Vector3 Vector3::xyx()
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = x;
	return result;
}
Vector3 Vector3::xyy()
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = y;
	return result;
}
Vector3 Vector3::xyz()
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}
Vector3 Vector3::xzx()
{
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = x;
	return result;
}
Vector3 Vector3::xzy()
{
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = y;
	return result;
}
Vector3 Vector3::xzz()
{
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = z;
	return result;
}