#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
struct Point
{
public:
	float x, y;
};

struct Line
{
public:
	float a, b, c;      //xa + by + c = 0
};

int getInt();
float getFloat();

class Tractrisa
{
private:
	float high;
	Line l;
public:
	Tractrisa(float high, float x, float y, float c);
	void SetLine(float x, float y, float c);
	Line GetLine();
	void SetHigh(float a);
	float Gethigh();
	Point GetPoint(float angle);
	float GetLengthOfArc(float angle);
	float GetCurvature(float angle);
	float GetSquare();

	~Tractrisa()
	{}
};

int SLine(Tractrisa& t);
int SHight(Tractrisa& t);
int GLine(Tractrisa& t);
int GHight(Tractrisa& t);
int GPoint(Tractrisa& t);
int GLength(Tractrisa& t);
int GCurvature(Tractrisa& t);
int GSquare(Tractrisa& t);

int dialog(const char* msgs[], int N);