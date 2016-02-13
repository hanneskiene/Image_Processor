#include "Image_Processor.h"

#include "Image_t.h"
#include "Bitmap_Handler.h"
#include "Image_Modifier.h"
#include <memory>
#include <iostream>

Image_Processor::Image_Processor()
{
}

int Image_Processor::run()
{

	Bitmap_Handler my_bitmap_handler;

	auto bmp_image_2 = my_bitmap_handler.get_Image("test3.bmp");

	bmp_image_2->console_print();

	Image_Modifier::invert(bmp_image_2.get());

	bmp_image_2->console_print();

	return true;
}


Image_Processor::~Image_Processor()
{
	//std::cout << "Image Processor destroyed" << std::endl;
}
