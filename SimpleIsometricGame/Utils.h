#pragma once
#include <iostream>
#include <math.h>

typedef unsigned char uchar;
typedef unsigned int uint;

template <class T>
class Vector2D
{
public:
	T x;
	T y;
	Vector2D() {};
	Vector2D(T _x, T _y) :x(_x), y(_y) {};
	Vector2D& operator=(const Vector2D &copy)
	{
		x = copy.x;
		y = copy.y;
		return *this;
	}
	Vector2D operator+(const Vector2D &right)
	{
		Vector2D res;
		res.x = x + right.x;
		res.y = y + right.y;
		return res;
	}
	Vector2D operator-(const Vector2D &right)
	{
		Vector2D res;
		res.x = x - right.x;
		res.y = y - right.y;
		return res;
	}
	bool operator==(const Vector2D &right)
	{
		return (x == right.x && y == right.y);
	}
	bool operator!=(const Vector2D &right)
	{
		return (x != right.x || y != right.y);
	}
	T Dot(const Vector2D &v)
	{
		return (x*v.x + y * v.y);
	};
	T Norm()
	{
		return std::sqrt(Dot(*this));
	};
	T Dot(Vector2D v1, Vector2D v2)
	{
		return (v1.x*v2.x + v1.y*v2.y);
	};
	T Norm(Vector2D v)
	{
		return std::sqrt(Dot(v, v));
	};
};

typedef Vector2D<float> float2;
typedef Vector2D<int> int2;
typedef Vector2D<uint> uint2;

struct Rect
{
	uint2 left_top;
	uint2 size;
	Rect() {};
	Rect& operator=(const Rect &copy)
	{
		left_top = copy.left_top;
		size = copy.size;
		return *this;
	}
};