#pragma once

typedef unsigned char uchar;
typedef unsigned int uint;

struct float2
{
	float x;
	float y;
	float2() {};
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
	uint2 top_left;
	uint2 size;
	Rect() {};
};