#include "Color.h"



Color::Color()
{
	r = 0;
	g = 0;
	b = 0;
}

Color::Color(int arg)
{
	r = arg;
	g = arg;
	b = arg;
}

Color::Color(int a_r, int a_g, int a_b)
{
	r = a_r;
	g = a_g;
	b = a_b;
}

void Color::set_color(int arg)
{
	r = arg;
	g = arg;
	b = arg;
}

void Color::set_color(int a_r, int a_g, int a_b)
{
	r = a_r;
	g = a_g;
	b = a_b;
}

signed char Color::get_r() { return r; }

signed char Color::get_g() { return g; }

signed char Color::get_b() { return b; }


Color::~Color()
{
	//std::cout << "Color destroyed" << std::endl;
}
