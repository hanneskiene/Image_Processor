#include "Pixel.h"



Pixel::Pixel()
{
	color.set_color(0);
}

Pixel::Pixel(Color arg)
{

}

void Pixel::set_color(Color a_c)
{
	color = a_c;
}

Color Pixel::get_color()
{
	return color;
}


Pixel::~Pixel()
{
	//std::cout << "Pixel destroyed" << std::endl;
}
