#pragma once

class Vector4
{
public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();

	//initializing axis x, y, z, w

	float x; 
	float y;
	float z;
	float w;

	//essential functions 			
	Vector4 operator+(const Vector4& rhs);			//Vector + a Vector
	Vector4 operator*(const float rhs);				//Vector * a float
	Vector4 operator-(const Vector4& rhs);			//Vector - a Vector
	Vector4 operator/(const Vector4& rhs);			//Vector / Vector
	Vector4 operator+=(const Vector4& rhs);			//Vector += a Vector
	Vector4 Vector4::cross(const Vector4& rhs);		//croos product of a vector

	float& operator[](const int rhs);				//subscript operator
	float dot(const Vector4 rhs);					//creates dot product 
	float normalise();								//normailising a vector
	float magnitude();								//finding the magnitude of a vector
	operator float*();								//casting a vector

	//extra functions 
	Vector4 min(const Vector4& rhs);				//calculates minimum number
	Vector4 max(const Vector4& rhs);				//calculates maximum number 
	Vector4 clamp(Vector4 min, Vector4 max);		//'clamps' number between min and max number 
	Vector4 normalised(Vector4& data);
	Vector4 lerp(Vector4& a, Vector4& b, float& t); // lerp
	bool operator<(const Vector4& rhs);				//smaller than operator 
	bool operator>(const Vector4& rhs);				//greater than operator
	bool operator>=(const Vector4& rhs);			//greater than or equal to operator 
	bool operator<=(const Vector4& rhs);			//smaller than or equal to operator 
	bool operator==(const Vector4& rhs);			//equal to operator
	bool operator!=(const Vector4& rhs);			//copy Vectors - not equal 
	float distance(const Vector4& p1, const Vector4& p2);							//help!
	float magnitudeSqrt();




};

Vector4 operator*(const float lhs, const Vector4& rhs);
Vector4 operator/(const float lhs, const Vector4& rhs);