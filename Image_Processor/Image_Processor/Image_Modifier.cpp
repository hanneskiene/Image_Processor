#include "Image_Modifier.h"
#include <memory>
#include <vector>
#include <iostream>

Image_Modifier::Image_Modifier()
{
}


void Image_Modifier::invert(Image_8 * image)
{
	auto pixels = image->get_pixels();
	for (int i = 0; i < pixels->size(); i++) {
		pixels->at(i).set_RGB((255 - pixels->at(i).get_r()), (255 - pixels->at(i).get_g()), (255 - pixels->at(i).get_b()));
	}
	int i = 0;
}
void Image_Modifier::grey_value(Image_8 * image)
{
	auto pixels = image->get_pixels();
	for (int i = 0; i < pixels->size(); i++) {
		unsigned char grauwert = (unsigned char)((pixels->at(i).get_r() + pixels->at(i).get_g() + pixels->at(i).get_b()) / 3);
		pixels->at(i).set_RGB(grauwert, grauwert, grauwert);
	}
}

void Image_Modifier::edge_highlite(Image_8* image, int a_x, int a_y, int threshold)
{
	struct Color{ int r; int g; int b; };
	std::vector<Color> area;
	area.reserve(a_x * a_y);
	for (int i = 0; i < a_x * a_y; i++) {
		Color c; c.b = 0; c.g = 0; c.r = 0;
		area.push_back(c);
	}
	
	//Pixel per Region X
	unsigned int ppr_x = (unsigned int)(image->size_x / a_x);
	//Pixel per Region Y
	unsigned int ppr_y = (unsigned int)(image->size_y / a_y);

	auto pixels = image->get_pixels();
	unsigned int index_x = 0;
	unsigned int count_x = 0;
	unsigned int index_y = 0;
	unsigned int count_y = 0;
	for (unsigned int i = 0; i < pixels->size(); i++) {
		area.at(index_x + (index_y * a_x)).r += pixels->at(i).get_r();
		area.at(index_x + (index_y * a_x)).g += pixels->at(i).get_g();
		area.at(index_x + (index_y * a_x)).b += pixels->at(i).get_b();
		count_x++;
		if (count_x == (ppr_x)) {
			index_x++;
			std::cout << "Index X: " << index_x << std::endl;
			count_x = 0;
			if (index_x == (a_x)) {
				index_x = 0;
				count_y++;
				if (count_y == (ppr_y)) {
					index_y++;
					std::cout << "Index X: " << index_x << std::endl;
					count_y = 0;
				}
			}
		}
	}
	for (unsigned int i = 0; i < area.size(); i++) {
		area[i].b /= ppr_x*ppr_y;
	}

}


Image_Modifier::~Image_Modifier()
{
}
