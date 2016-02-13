#pragma once

#include <memory>
#include "Image.h"

class Bitmap_Handler
{
public:
	Bitmap_Handler();

	//Is only able to import standard 8bit BMP without compression
	std::shared_ptr<Image<unsigned char>> get_Image(const char *file_name);

	bool export_image(Image<unsigned char> *, const char *);

	~Bitmap_Handler();

private:

};

