#pragma once

#include <iostream>

template<class T>
class Color
{
public:
	//Default Color
	Color();
	//Grey Color
	Color(T);
	//RGB Color
	Color(T, T, T);

	void set_color(T);

	void set_color(T, T, T);

	T get_r();
	T get_g();
	T get_b();

	~Color();

	T r, g, b;

};

