#pragma once

#include <memory>
#include "Image_t.h"

class Bitmap_Handler
{
public:
	Bitmap_Handler();

	//Is only able to import standard 8bit BMP without compression
	std::shared_ptr<Image_8> get_Image(const char *file_name);

	bool export_image(Image_8 *, const char *);

	~Bitmap_Handler();

private:

};

