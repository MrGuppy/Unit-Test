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
<<<<<<< HEAD
	Vector4 min(const Vector4& rhs);	        //calculates minimum number
	Vector4 max(const Vector4& rhs);		    //calculates maximum number 
	Vector4 clamp(Vector4 min, Vector4 max);    //'clamps' number between min and max number 
	Vector4 hermite(Vector4 p1, Vector4 tan1, Vector4 p2, Vector4 tan2, float t);
	Vector4 bezier(Vector4 a, Vector4 b, Vector4 c, float t);
	Vector4 lerp(Vector4& a, Vector4& b, float& t);
=======
	Vector4 min(const Vector4& rhs);				//calculates minimum number
	Vector4 max(const Vector4& rhs);				//calculates maximum number 
	Vector4 clamp(Vector4 min, Vector4 max);		//'clamps' number between min and max number 
>>>>>>> origin/master
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

	//swizzle

	Vector4 wwww();
	Vector4 wwwx();
	Vector4 wwwy();
	Vector4 wwwz();
	Vector4 wwxw();
	Vector4 wwxx();
	Vector4 wwxy();
	Vector4 wwxz();
	Vector4 wwyw();
	Vector4 wwyx();
	Vector4 wwyy();
	Vector4 wwyz();
	Vector4 wwzw();
	Vector4 wwzx();
	Vector4 wwzy();
	Vector4 wwzz();
	Vector4 wxww();
	Vector4 wxwx();
	Vector4 wxwy();
	Vector4 wxwz();
	Vector4 wxxw();
	Vector4 wxxx();
	Vector4 wxxy();
	Vector4 wxxz();
	Vector4 wxyw();
	Vector4 wxyx();
	Vector4 wxyy();
	Vector4 wxyz();
	Vector4 wxzw();
	Vector4 wxzx();
	Vector4 wxzy();
	Vector4 wxzz();
	Vector4 wyww();
	Vector4 wywx();
	Vector4 wywy();
	Vector4 wywz();
	Vector4 wyxw();
	Vector4 wyxx();
	Vector4 wyxy();
	Vector4 wyxz();
	Vector4 wyyw();
	Vector4 wyyx();
	Vector4 wyyy();
	Vector4 wyyz();
	Vector4 wyzw();
	Vector4 wyzx();
	Vector4 wyzy();
	Vector4 wyzz();
	Vector4 wzww();
	Vector4 wzwx();
	Vector4 wzwy();
	Vector4 wzwz();
	Vector4 wzxw();
	Vector4 wzxx();
	Vector4 wzxy();
	Vector4 wzxz();
	Vector4 wzyw();
	Vector4 wzyx();
	Vector4 wzyy();
	Vector4 wzyz();
	Vector4 wzzw();
	Vector4 wzzx();
	Vector4 wzzy();
	Vector4 wzzz();
	Vector4 xwww();
	Vector4 xwwx();
	Vector4 xwwy();
	Vector4 xwwz();
	Vector4 xwxw();
	Vector4 xwxx();
	Vector4 xwxy();
	Vector4 xwxz();
	Vector4 xwyw();
	Vector4 xwyx();
	Vector4 xwyy();
	Vector4 xwyz();
	Vector4 xwzw();
	Vector4 xwzx();
	Vector4 xwzy();
	Vector4 xwzz();
	Vector4 xxww();
	Vector4 xxwx();
	Vector4 xxwy();
	Vector4 xxwz();
	Vector4 xxxw();
	Vector4 xxxx();
	Vector4 xxxy();
	Vector4 xxxz();
	Vector4 xxyw();
	Vector4 xxyx();
	Vector4 xxyy();
	Vector4 xxyz();
	Vector4 xxzw();
	Vector4 xxzx();
	Vector4 xxzy();
	Vector4 xxzz();
	Vector4 xyww();
	Vector4 xywx();
	Vector4 xywy();
	Vector4 xywz();
	Vector4 xyxw();
	Vector4 xyxx();
	Vector4 xyxy();
	Vector4 xyxz();
	Vector4 xyyw();
	Vector4 xyyx();
	Vector4 xyyy();
	Vector4 xyyz();
	Vector4 xyzx();
	Vector4 xyzy();
	Vector4 xyzz();
	Vector4 xzww();
	Vector4 xzwx();
	Vector4 xzwy();
	Vector4 xzwz();
	Vector4 xzxw();
	Vector4 xzxx();
	Vector4 xzxy();
	Vector4 xzxz();
	Vector4 xzyw();
	Vector4 xzyx();
	Vector4 xzyy();
	Vector4 xzyz();
	Vector4 xzzw();
	Vector4 xzzx();
	Vector4 xzzy();
	Vector4 xzzz();
	Vector4 ywww();
	Vector4 ywwx();
	Vector4 ywwy();
	Vector4 ywwz();
	Vector4 ywxw();
	Vector4 ywxx();
	Vector4 ywxy();
	Vector4 ywxz();
	Vector4 ywyw();
	Vector4 ywyx();
	Vector4 ywyy();
	Vector4 ywyz();
	Vector4 ywzw();
	Vector4 ywzx();
	Vector4 ywzy();
	Vector4 ywzz();
	Vector4 yxww();
	Vector4 yxwx();
	Vector4 yxwy();
	Vector4 yxwz();
	Vector4 yxxw();
	Vector4 yxxx();
	Vector4 yxxy();
	Vector4 yxxz();
	Vector4 yxyw();
	Vector4 yxyx();
	Vector4 yxyy();
	Vector4 yxyz();
	Vector4 yxzw();
	Vector4 yxzx();
	Vector4 yxzy();
	Vector4 yxzz();
	Vector4 yyww();
	Vector4 yywx();
	Vector4 yywy();
	Vector4 yywz();
	Vector4 yyxw();
	Vector4 yyxx();
	Vector4 yyxy();
	Vector4 yyxz();
	Vector4 yyyw();
	Vector4 yyyx();
	Vector4 yyyy();
	Vector4 yyyz();
	Vector4 yyzw();
	Vector4 yyzx();
	Vector4 yyzy();
	Vector4 yyzz();
	Vector4 yzww();
	Vector4 yzwx();
	Vector4 yzwy();
	Vector4 yzwz();
	Vector4 yzxw();
	Vector4 yzxx();
	Vector4 yzxy();
	Vector4 yzxz();
	Vector4 yzyw();
	Vector4 yzyx();
	Vector4 yzyy();
	Vector4 yzyz();
	Vector4 yzzw();
	Vector4 yzzx();
	Vector4 yzzy();
	Vector4 yzzz();
	Vector4 zwww();
	Vector4 zwwx();
	Vector4 zwwy();
	Vector4 zwwz();
	Vector4 zwxw();
	Vector4 zwxx();
	Vector4 zwxy();
	Vector4 zwxz();
	Vector4 zwyw();
	Vector4 zwyx();
	Vector4 zwyy();
	Vector4 zwyz();
	Vector4 zwzw();
	Vector4 zwzx();
	Vector4 zwzy();
	Vector4 zwzz();
	Vector4 zxww();
	Vector4 zxwx();
	Vector4 zxwy();
	Vector4 zxwz();
	Vector4 zxxw();
	Vector4 zxxx();
	Vector4 zxxy();
	Vector4 zxxz();
	Vector4 zxyw();
	Vector4 zxyx();
	Vector4 zxyy();
	Vector4 zxyz();
	Vector4 zxzw();
	Vector4 zxzx();
	Vector4 zxzy();
	Vector4 zxzz();
	Vector4 zyww();
	Vector4 zywx();
	Vector4 zywy();
	Vector4 zywz();
	Vector4 zyxw();
	Vector4 zyxx();
	Vector4 zyxy();
	Vector4 zyxz();
	Vector4 zyyw();
	Vector4 zyyx();
	Vector4 zyyy();
	Vector4 zyyz();
	Vector4 zyzw();
	Vector4 zyzx();
	Vector4 zyzy();
	Vector4 zyzz();
	Vector4 zzww();
	Vector4 zzwx();
	Vector4 zzwy();
	Vector4 zzwz();
	Vector4 zzxw();
	Vector4 zzxx();
	Vector4 zzxy();
	Vector4 zzxz();
	Vector4 zzyw();
	Vector4 zzyx();
	Vector4 zzyy();
	Vector4 zzyz();
	Vector4 zzzw();
	Vector4 zzzx();
	Vector4 zzzy();
	Vector4 zzzz();

};

Vector4 operator*(const float lhs, const Vector4& rhs);
Vector4 operator/(const float lhs, const Vector4& rhs);