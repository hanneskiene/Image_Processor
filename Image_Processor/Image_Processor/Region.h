#pragma once

#include "Image_t.h"
#include <vector>

class Region
{
public:
	Region(Image_8* image, int);
	Region(Image_8* image, int, int, int, int, int);

	~Region();

	std::vector<Region> solve();

	void evaluate();

	bool region_ok();

	std::vector<Region> subdivide();

	void mark_edge();

	void fill();

	unsigned int start_x;
	unsigned int start_y;
	unsigned int size_x;
	unsigned int size_y;

	Image_8* image;

	std::vector<Region> child_regions;

	int threshold;
};

