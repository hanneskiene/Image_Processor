#pragma once

#include "Image_t.h"
#include "Matrix.h"

class Image_Modifier
{
public:
	Image_Modifier();

	static void invert(Image_8*);
	static void grey_value(Image_8*);
	static void edge_highlite(Image_8*, int);

	static void apply_matrix(Image_8*, Matrix);
	static void smooth();
	~Image_Modifier();
};

