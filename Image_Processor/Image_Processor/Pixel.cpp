#include "Pixel.h"


template<class T>
Pixel::Pixel()
{
	color.set_color(0);
}

template<class T>
Pixel::Pixel(Color<T> arg)
{

}

template<class T>
void Pixel::set_color(Color a_c)
{
	color = a_c;
}

template<class T>
Color<T> Pixel::get_color()
{
	return color;
}

template<class T>
Pixel::~Pixel()
{
	//std::cout << "Pixel destroyed" << std::endl;
}
