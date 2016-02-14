#include "Image_Processor.h"

#include "Image_t.h"
#include "Bitmap_Handler.h"
#include "Image_Modifier.h"
#include <memory>
#include <iostream>
#include <ctime>

Image_Processor::Image_Processor()
{
}

int Image_Processor::run()
{

	auto my_bitmap_handler = Bitmap_Handler{};

	auto bmp_image_2 = my_bitmap_handler.get_Image("test4.bmp");
	std::cout << "Image loaded" << std::endl;
	my_bitmap_handler.export_image(bmp_image_2.get(), "export_old.bmp");
	std::cout << "Image exportet" << std::endl;
	Image_Modifier::invert(bmp_image_2.get());
	std::cout << "Image invertet" << std::endl;
	my_bitmap_handler.export_image(bmp_image_2.get(), "export_invert.bmp");
	std::cout << "Image exportet" << std::endl;
	Image_Modifier::grey_value(bmp_image_2.get());
	std::cout << "Image greyed" << std::endl;
	my_bitmap_handler.export_image(bmp_image_2.get(), "export_grey.bmp");

	return true;
}


Image_Processor::~Image_Processor()
{
	//std::cout << "Image Processor destroyed" << std::endl;
}
