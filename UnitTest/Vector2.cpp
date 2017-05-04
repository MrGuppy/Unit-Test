#include "Vector2.h"
#include <math.h>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::~Vector2()
{
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	return result;
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	return result;
}

Vector2 Vector2::operator+=(const Vector2& rhs)
{
	Vector2 result;
	result.x += rhs.x;
	result.y += rhs.y;
	return result;
}

Vector2 Vector2::operator*(const float rhs)
{
	Vector2 result;
	result.x = x * rhs;
	result.y = y * rhs;
	return result;
}

Vector2 operator*(const float lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	return result;
}

Vector2 operator/(const float lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	return result;
}

Vector2 Vector2::operator/(const Vector2& rhs)
{
	Vector2 result;
	result.x = x / rhs.x;
	result.y = y / rhs.y;
	return result;
}

float Vector2::magnitude()
{
	float result;
	result = sqrtf(x * x + y * y);
	return result;
}

float Vector2::dot(const Vector2& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y;
	return result;
}

float Vector2::normalise()
{
	float mag = magnitude();
	x = x / mag;
	y = y / mag;
	return mag;
}

Vector2::operator float*()
{
	return &x;
}

float& Vector2::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	if (rhs == 1)
		return y;
	else
		return x;
}

Vector2 Vector2::normailsed(Vector2& data)
{
	Vector2 result;
	float mag = data.magnitude();
	if (!mag == 0)
	{
		result.x = x / mag;
		result.y = y / mag;
		return result;
	}
	return result;
}

Vector2 Vector2::min(const Vector2& rhs)
{
	Vector2 result;
	if (x < rhs.x)
		result.x = x;
	else
		result.x = x;

	if (y < rhs.y)
		result.y = y;
	else
		result.y = y;

	return result;
}

Vector2 Vector2::max(const Vector2& rhs)
{
	Vector2 result;
	if (x > rhs.x)
		result.x = x;
	else
		result.x = x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = y;

	return result;
}

Vector2 Vector2::clamp(Vector2 min, Vector2 max)
{
	Vector2 result;
	result = this->min(min);
	result = result.max(max);
	return result;
}

//check done

bool Vector2::operator!=(const Vector2& rhs)
{
	return (x != rhs.x && y != rhs.y);
}

bool Vector2::operator<(const Vector2& rhs)
{
	return (x < rhs.x && y < rhs.y);
}

bool Vector2::operator>(const Vector2& rhs)
{
	return (x > rhs.x && y > rhs.y);
}

bool Vector2::operator>=(const Vector2& rhs)
{
	return (x >= rhs.x && y >= rhs.y);
}

bool Vector2::operator<=(const Vector2& rhs)
{
	return (x <= rhs.x && y <= rhs.y);
}

bool Vector2::operator==(const Vector2& rhs)
{
	return (x == rhs.x && y == rhs.y);
}

float Vector2::distance(const Vector2& p1, const Vector2& p2) //check 
{
	float diffx = p1.x - p2.x;
	float diffy = p1.y - p2.y;
	return sqrtf((diffx * diffx) + (diffy * diffy));
}

float Vector2::magnitudeSqrt()
{
	float result;
	result = (x * x + y * y);
	return result;
}

Vector2 Vector2::lerp(Vector2& a, Vector2& b, float& t)
{
	return (a + b) * t;
}

Vector2 Vector2::xx()
{
	Vector2 result;
	result.x = x;
	result.y = x;
	return result;
}

Vector2 Vector2::yx()
{
	Vector2 result;
	result.x = y;
	result.y = x;
	return result;
}

Vector2 Vector2::yy()
{
	Vector2 result;
	result.x = y;
	result.y = y;
	return result;
}

Vector2 Vector2::hermite(Vector2 p1, Vector2 tan1, Vector2 p2, Vector2 tan2, float t)
{
	float tSquare = t * t;
	float tCube = tSquare * t;
	float h00 = 2 * tCube - 3 * tSquare + 1;
	float h01 = -2 * tCube + 3 * tSquare;
	float h10 = tCube - 2 * tSquare + t;
	float h11 = tCube - tSquare;

	return h00 * p1 + h10 * tan1 + h01 * p2 + h11 * tan2;
}

Vector2 Vector2::bezier(Vector2 a, Vector2 b, Vector2 c, float t) 
{
	Vector2 mid1 = lerp(a, b, t);
	Vector2 mid2 = lerp(b, c, t);

	return lerp(mid1, mid2, t);
}

