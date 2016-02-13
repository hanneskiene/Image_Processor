#include "Image_Processor.h"

#include "Image.h"
#include "Bitmap_Handler.h"
#include <memory>
#include <iostream>

Image_Processor::Image_Processor()
{
}

int Image_Processor::run()
{
	auto my_image = std::make_unique<Image>(10, 10);

	Bitmap_Handler my_bitmap_handler;
	auto bmp_image = my_bitmap_handler.get_Image("test2.bmp");

	bmp_image->console_print();

	return true;
}


Image_Processor::~Image_Processor()
{
	//std::cout << "Image Processor destroyed" << std::endl;
}
