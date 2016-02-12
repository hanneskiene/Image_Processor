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

	signed char get_r();
	signed char get_g();
	signed char get_b();

	~Color();

	signed char r, g, b;

};

