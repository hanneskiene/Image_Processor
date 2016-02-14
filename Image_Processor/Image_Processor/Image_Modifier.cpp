#include "Image_Modifier.h"
#include <memory>
#include <vector>

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
void Image_Modifier::apply_matrix(Image_8 * image, Matrix matrix)
{
	Image_8 *imgBuffer = image;
	auto pixels_B = imgBuffer->get_pixels();
	auto pixels = image->get_pixels();
	for (int i = 0; i < pixels->size(); i++) {
		
		unsigned char resultR = (unsigned char)((pixels_B->at(i - 1).get_r())*matrix.get_value(i - 1) + (pixels_B->at(i).get_r())*matrix.get_value(i - 1) + (pixels_B->at(i + 1).get_r())*matrix.get_value(i - 1) + (pixels_B->at(i - 1).get_r())*matrix.get_value(i) + (pixels_B->at(i).get_r())*matrix.get_value(i) + (pixels_B->at(i).get_r())*matrix.get_value(i + 1) + (pixels_B->at(i - 1).get_r())*matrix.get_value(i + 1) + (pixels_B->at(i).get_r())*matrix.get_value(i + 1) + (pixels_B->at(i + 1).get_r())*matrix.get_value(i + 1));
		unsigned char resultG = (unsigned char)((pixels_B->at(i - 1).get_g())*matrix.get_value(i - 1) + (pixels_B->at(i).get_g())*matrix.get_value(i - 1) + (pixels_B->at(i + 1).get_g())*matrix.get_value(i - 1) + (pixels_B->at(i - 1).get_g())*matrix.get_value(i) + (pixels_B->at(i).get_g())*matrix.get_value(i) + (pixels_B->at(i).get_g())*matrix.get_value(i + 1) + (pixels_B->at(i - 1).get_g())*matrix.get_value(i + 1) + (pixels_B->at(i).get_g())*matrix.get_value(i + 1) + (pixels_B->at(i + 1).get_g())*matrix.get_value(i + 1));
		unsigned char resultB = (unsigned char)((pixels_B->at(i - 1).get_b())*matrix.get_value(i - 1) + (pixels_B->at(i).get_b())*matrix.get_value(i - 1) + (pixels_B->at(i + 1).get_b())*matrix.get_value(i - 1) + (pixels_B->at(i - 1).get_b())*matrix.get_value(i) + (pixels_B->at(i).get_b())*matrix.get_value(i) + (pixels_B->at(i).get_b())*matrix.get_value(i + 1) + (pixels_B->at(i - 1).get_b())*matrix.get_value(i + 1) + (pixels_B->at(i).get_b())*matrix.get_value(i + 1) + (pixels_B->at(i + 1).get_b())*matrix.get_value(i + 1));

		pixels->at(i).set_RGB(resultR, resultG, resultB);

	}
}
Image_Modifier::~Image_Modifier()
{
}
