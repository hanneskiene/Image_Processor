#pragma once

#include <memory>
#include "Image.h"

class Bitmap_Handler
{
public:
	Bitmap_Handler();

	std::shared_ptr<Image> get_Image(const char *file_name);

	~Bitmap_Handler();

private:

};

