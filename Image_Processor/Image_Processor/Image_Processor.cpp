#include "Image_Processor.h"

#include "Image_t.h"
#include "Bitmap_Handler.h"
#include <memory>
#include <iostream>

Image_Processor::Image_Processor()
{
}

int Image_Processor::run()
{
	auto my_image = std::make_unique<Image_8>(10, 10);

	Bitmap_Handler my_bitmap_handler;
	auto bmp_image = my_bitmap_handler.get_Image("test3.bmp");

	bmp_image->console_print();

	return true;
}


Image_Processor::~Image_Processor()
{
	//std::cout << "Image Processor destroyed" << std::endl;
}
