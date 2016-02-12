#include "Image.h"



Image::Image()
{
	size_x = 0;
	size_y = 0;
}

Image::Image(int a_x, int a_y)
{
	size_x = a_x;
	size_y = a_y;

	//Add Pixels to Image
	for (int i = 0; i < size_x; i++) {
		for (int z = 0; z < size_y; z++) {
			pixels.push_back(std::make_unique<Pixel>());
		}
	}

}


void Image::set_size(int a_x, int a_y)
{
	//Implement size changing here, needs to remove the right pixels out of the pixel array
	//size_x = a_x;
	//size_y = a_y;
	std::cout << "ERROR: Image size changing not implemented yet" << std::endl;
}

Pixel * Image::get_pixel(int arg)
{
	return pixels.at(arg).get();
}

Pixel * Image::get_pixel(int a_x, int a_y)
{
	return pixels.at(a_y * size_x + a_x).get();
}

void Image::console_print()
{
	for (int i = 0; i < size_x; i++) {
		for (int z = 0; z < size_y; z++) {
			if (pixels.at(i*size_x + z)->get_color().get_b() > 150)
				std::cout << "0";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

Image::~Image()
{
	std::cout << "Image destroyed" << std::endl;
}
