#include "Region.h"



Region::Region(Image_8* a_i, int a_t)
{
	image = a_i;

	start_x = 0;
	start_y = 0;

	size_x = a_i->size_x;
	size_y = a_i->size_y;

	threshold = a_t;
}

Region::Region(Image_8* a_i, int a_t, int s_x, int s_y, int si_x, int si_y)
{
	image = a_i;

	start_x = s_x;
	start_y = s_y;

	size_x = si_x;
	size_y = si_y;

	threshold = a_t;
}

Region::~Region()
{
}

std::vector<Region> Region::solve()
{
	evaluate();
	return child_regions;
}

void Region::evaluate()
{
	if (region_ok()) {
		
	}
	else {
		child_regions = subdivide();
	}
}

bool Region::region_ok()
{
	unsigned char lowest = 255;
	unsigned char highest = 0;
	for (unsigned int i = 0; i < size_x; i++) {
		for (unsigned int z = 0; z < size_y; z++) {
			unsigned char current = image->get_pixel(i + start_x, z + start_y)->get_b();
			if (current > highest) highest = current;
			if (current < lowest) lowest = current;
		}
	}
	if (highest - lowest <= threshold) {
		return true;
	}
	else {
		return false;
	}
}


std::vector<Region> Region::subdivide()
{
	std::vector<Region> out;
	out.reserve(4);

	for (int i = 0; i < 2; i++) {
		for (int z = 0; z < 2; z++) {
			out.push_back(Region(image, threshold, start_x + (i * (size_x / 2)), start_y + (z * (size_y / 2)), (size_x / 2), (size_y / 2)) );
		}
	}
	return out;
}

void Region::mark_edge() 
{
	for (unsigned int i = 0; i < size_x; i++) {
		image->get_pixel(i + start_x, start_y)->set_RGB(255, 0, 0);
	}
	for (unsigned int z = 0; z < size_y; z++) {
		image->get_pixel(start_x, z + start_y)->set_RGB(255, 0, 0);
	}
}

void Region::fill()
{
	for (unsigned int i = 1; i <= size_x; i++) {
		for (unsigned int z = 1; z <= size_y; z++) {
			image->get_pixel(start_x + i, z + start_y)->set_RGB(0, 0, 255);
		}
	}
}
