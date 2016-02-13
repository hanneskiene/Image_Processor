#pragma once

#include <iostream>

#include "Color.h"

template<class T>
class Pixel
{
public:
	//Create default Pixel
	Pixel();
	//Create RGB Pixel
	Pixel(Color<T>);

	void set_color(Color<T>);

	Color<T> get_color();

	~Pixel();
	
private:
	Color<T> color;
};

#include "Pixel.cpp"
