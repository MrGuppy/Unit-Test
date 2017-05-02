#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	float x;
	float y;
	float z;

	float& operator[](const int rhs); //subscript operator
	Vector3 normalised(Vector3& data);
	Vector3 operator+(const Vector3& rhs);
	Vector3 operator*(const float rhs);
	Vector3 operator-(const Vector3& rhs);
	Vector3 operator/(const Vector3& rhs);
	Vector3 operator+=(const Vector3& rhs);
	Vector3 cross(const Vector3& rhs);
	Vector3 min(const Vector3& rhs);
	Vector3 max(const Vector3& rhs);
	Vector3 clamp(Vector3 min, Vector3 max);

	Vector3 lerp(Vector3& a, Vector3& b, float& t);
	bool operator<(const Vector3& rhs);  //smaller than operator 
	bool operator>(const Vector3& rhs);  //greater than operator
	bool operator>=(const Vector3& rhs); //greater than or equal to operator 
	bool operator<=(const Vector3& rhs); //smaller than or equal to operator 
	bool operator==(const Vector3& rhs); //equal to operator
	bool operator!=(const Vector3& rhs); //copy Vectors - not equal 
	float distance(const Vector3& p1, const Vector3& p2);					//help!
	float magnitudeSqrt();

	float dot(const Vector3 rhs);
	float normalise();
	float magnitude();

	operator float*();


};

Vector3 operator*(const float lhs, const Vector3& rhs);
Vector3 operator/(const float lhs, const Vector3& rhs);