#pragma once

typedef unsigned char uchar;
typedef unsigned int uint;

struct float2
{
	float x;
	float y;
	float2() {};
	/*
	float2(float _x, float _y) :x(_x), y(_y) {};
	float2& operator=(const float2 &copy)
	{
		x = copy.x;
		y = copy.y;
		return *this;
	}
	*/
};

struct int2
{
	int x;
	int y;
	int2() {};
};

struct uint2
{
	uint x;
	uint y;
	uint2() {};
};

struct Rect
{
	uint2 left_top;
	uint2 size;
	Rect() {};
};