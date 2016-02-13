#pragma once

#include <iostream>

#include "Color.h"

class Pixel
{
public:
	//Create default Pixel
	Pixel();
	//Create RGB Pixel
	Pixel(Color);

	void set_color(Color);

	Color get_color();

	~Pixel();
	
private:
	Color color;
};

