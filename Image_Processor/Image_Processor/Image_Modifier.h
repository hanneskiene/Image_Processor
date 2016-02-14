#pragma once

#include "Image_t.h"

class Image_Modifier
{
public:
	Image_Modifier();

	static void invert(Image_8*);
	static void grey_value(Image_8*);
	~Image_Modifier();
};

