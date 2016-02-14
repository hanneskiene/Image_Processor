#include "Image_Modifier.h"
#include <memory>
#include <vector>

Image_Modifier::Image_Modifier()
{
}

void Image_Modifier::invert(Image_8 * image)
{
	auto pixels = image->get_pixels();
	for (auto it = pixels->begin(); it != pixels->end(); it++) {
		(*it)->set_RGB((255 - (*it)->get_r()), (255 - (*it)->get_g()), (255 - (*it)->get_b()));
	}
}
void Image_Modifier::grey_value(Image_8 * image)
{
	auto pixels = image->get_pixels();
	for (auto it = pixels->begin(); it != pixels->end(); it++) {
		unsigned char grauwert = (unsigned char)( ((*it)->get_r() + (*it)->get_g() + (*it)->get_b() ) / 3);
		(*it)->set_RGB(grauwert, grauwert, grauwert);
	}
}


Image_Modifier::~Image_Modifier()
{
}
