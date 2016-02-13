#pragma once

#include <iostream>

class Color
{
public:
	//Default Color
	Color();
	//Grey COlor
	Color(int);
	//RGB Color
	Color(int, int, int);

	void set_color(int);

	void set_color(int, int, int);

	unsigned char get_r();
	unsigned char get_g();
	unsigned char get_b();

	~Color();

	unsigned char r, g, b;

};

