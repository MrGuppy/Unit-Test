#pragma once
#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"

template <class D, class S>

D CastTo(S Source) {};

template <>
Vector3  CastTo(Vector2 source)
{
	Vector3 result;
	result.x = source.x;
	result.y = source.y;
	return result;
}

template <>
Vector4 CastTo(Vector2 source)
{
	Vector4 result;
	result.x = source.x;
	result.y = source.y;
	return result;
}

//template<>
//Vector2 CastTo(Vector3 source)
//{
//	Vector2 result;
//	result.x = source.x;
//	result.y = source.y;
//	result.z = source.z;
//	return result;
//}