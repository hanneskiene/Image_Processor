#include "Image_Modifier.h"
#include <memory>
#include <vector>
#include <iostream>
#include "Region.h"

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

void Image_Modifier::edge_highlite(Image_8* image, int threshold)
{
	std::vector<Region> unsolved_regions;
	std::vector<Region> solved_regions;

	unsolved_regions.push_back(Region (image, threshold));

	do {
		for (int c = 0; c < unsolved_regions.size(); c++) {
			auto res = unsolved_regions.at(c).solve();
			if (res.size() > 0) {
				unsolved_regions.erase(unsolved_regions.begin() + c);
				for (int i = 0; i < res.size(); i++) {
					unsolved_regions.push_back(res.at(i));
				}
			}
			else {
				solved_regions.push_back(unsolved_regions.at(c));
				unsolved_regions.erase(unsolved_regions.begin() + c);
				unsolved_regions.shrink_to_fit();
			}
		}
	} while (unsolved_regions.size() > 0);
	for (unsigned int i = 0; i < solved_regions.size(); i++) {
		solved_regions.at(i).mark_edge();
	}
}


Image_Modifier::~Image_Modifier()
{
}
