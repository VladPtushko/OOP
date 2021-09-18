#include <iostream>
#include "Header.h"

float getFloat()
{
	float f;
linkf:
	std::cin >> f;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "incorrect input\n";
		goto linkf;
	}
	return f;
}

int getInt()
{
	int i;
linki:
	std::cin >> i;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "incorrect input\n";
		goto linki;
	}
	return i;
}

Tractrisa::Tractrisa(float high = 1, float x = 0, float y = 1, float c = 0)
{
	this->high = high;
	this->l.a = x;
	this->l.b = y;
	this->l.c = c;
}
void Tractrisa::SetLine(float x, float y, float c)
{
	this->l.a = x;
	this->l.b = y;
	this->l.c = c;
}

Line Tractrisa::GetLine()
{
	Line lin;
	lin.a = this->l.a;
	lin.b = this->l.b;
	lin.c = this->l.c;
	return lin;
}

void Tractrisa::SetHigh(float a)
{
	this->high = high;
}

float Tractrisa::Gethigh()
{
	return this->high;
}

Point Tractrisa::GetPoint(float angle)
{
	Point p;
	p.y = this->high * sin(angle);
	p.x = this->high * log((this->high + sqrt(this->high * this->high - p.y * p.y)) / p.y) - sqrt(this->high * this->high - p.y * p.y);
	if (this->l.a == 0)
		p.y -= this->l.c;
	else if (this->l.b == 0)
		p.x -= this->l.c;
	else
	{
		float gipotenyza = sqrt(l.a * l.a + l.b * l.b);
		p.x *= sin(angle + M_PI_2);
		p.y *= cos(angle + M_PI_2);
		p.y -= this->l.c;
	}
	return p;
}

float Tractrisa::GetLengthOfArc(float angle)
{
	return (-1 * this->high * log(sin(angle)));
}

float Tractrisa::GetCurvature(float angle)
{
	return this->high / tan(angle);
}

float Tractrisa::GetSquare()
{
	return (M_PI * this->high * this->high) / 2;
}


int SLine(Tractrisa& t)
{
	float a, b, c;
	std::cout << "Enter a, b, c\n";
	a = getFloat();
	b = getFloat();
	c = getFloat();
	t.SetLine(a, b, c);
	return 0;
}
int SHight(Tractrisa& t)
{
	float high;
	std::cout << "Enter high\n";
	high = getFloat();
	t.SetHigh(high);
	return 0;
}
int GLine(Tractrisa& t)
{
	Line l = t.GetLine();
	std::cout << "\nLine " << l.a << "x + " << l.b << "y + " << l.c << " = 0\n";
	return 0;
}
int GHight(Tractrisa& t)
{
	std::cout << "High " << t.Gethigh() << '\n';
	return 0;
}
int GPoint(Tractrisa& t)
{
	float ang;
	std::cout << "Enter angle\n";
	ang = getInt();
	Point p = t.GetPoint(ang);
	std::cout << "Point " << p.x << "x " << p.y << "y\n";
	return 0;
}
int GLength(Tractrisa& t)
{
	float angl;
	std::cout << "Enter angle\n";
	angl = getFloat();
	std::cout << "Arc " << t.GetLengthOfArc(angl) << '\n';
	return 0;
}
int GCurvature(Tractrisa& t)
{
	float angle;
	std::cout << "Enter angle\n";
	angle = getFloat();
	std::cout << "Curvature " << t.GetCurvature(angle) << '\n';
	return 0;
}
int GSquare(Tractrisa& t)
{
	std::cout << "Square " << t.GetSquare() << '\n';
	return 0;
}

int dialog(const char* msgs[], int N)
{
	char* errmsg = (char*)"";
	int rc;
	int i;
	do {
		puts(errmsg);
		errmsg = (char*)"You are wrong. Repeate, please!";
		for (i = 0; i < N; ++i)
			puts(msgs[i]);
		puts("Make your choice: -->");
		rc = getInt();
	} while (rc < 0 || rc >= N);
	return rc;
}