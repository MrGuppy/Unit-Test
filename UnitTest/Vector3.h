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
	Vector3 hermite(Vector3 p1, Vector3 tan1, Vector3 p2, Vector3 tan2, float t);
	Vector3 bezier(Vector3 a, Vector3 b, Vector3 c, float t);

	float dot(const Vector3 rhs);
	float normalise();
	float magnitude();

	operator float*();

	//swizzle

	Vector3 xxx();
	Vector3 xxy();
	Vector3 xxz();
	Vector3 xyx();
	Vector3 xyy();
	Vector3 xyz();
	Vector3 xzx();
	Vector3 xzy();
	Vector3 xzz();
	Vector3 yxx();
	Vector3 yxy();
	Vector3 yxz();
	Vector3 yyx();
	Vector3 yyy();
	Vector3 yyz();
	Vector3 yzx();
	Vector3 yzy();
	Vector3 yzz();
	Vector3 zxx();
	Vector3 zxy();
	Vector3 zxz();
	Vector3 zyx();
	Vector3 zyy();
	Vector3 zyz();
	Vector3 zzx();
	Vector3 zzy();
	Vector3 zzz();
};

Vector3 operator*(const float lhs, const Vector3& rhs);
Vector3 operator/(const float lhs, const Vector3& rhs);