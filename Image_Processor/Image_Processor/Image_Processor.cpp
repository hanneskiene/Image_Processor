#include "Image_Processor.h"

#include "Image_t.h"
#include "Matrix.h"
#include "Bitmap_Handler.h"
#include "Image_Modifier.h"
#include <memory>
#include <iostream>
#include <chrono>
#define INIT_TIMER auto start = std::chrono::high_resolution_clock::now()
#define START_TIMER  start = std::chrono::high_resolution_clock::now()
#define STOP_TIMER(name)  std::cout << "RUNTIME of " << name << ": " << \
    std::chrono::duration_cast<std::chrono::milliseconds>( \
            std::chrono::high_resolution_clock::now()-start \
    ).count() << " ms " << std::endl


Image_Processor::Image_Processor()
{
}

int Image_Processor::run()
{
	INIT_TIMER;
	START_TIMER;

	
	auto my_bitmap_handler = Bitmap_Handler{};

	auto bmp_image_2 = my_bitmap_handler.get_Image("test6.bmp");
	auto matrix = Matrix{};
	matrix.set_value(0, 0, 0, 1, 0, 0, 0, 0, 0);
	Image_Modifier::apply_matrix(bmp_image_2.get(),matrix);
	my_bitmap_handler.export_image(bmp_image_2.get(), "export_matrix.bmp");
	/*
	Image_Modifier::invert(bmp_image_2.get());
	my_bitmap_handler.export_image(bmp_image_2.get(), "export_invert.bmp");
	std::cout << "Image loaded" << std::endl;
	STOP_TIMER("Image Import");
	/*
	START_TIMER;
	Image_Modifier::grey_value(bmp_image_2.get());
	std::cout << "Image greyed" << std::endl;
	STOP_TIMER("Grey Algo");
	*/
	START_TIMER;
	Image_Modifier::edge_highlite(bmp_image_2.get(), 150);
	STOP_TIMER("Edge Highlite");

	START_TIMER;
	my_bitmap_handler.export_image(bmp_image_2.get(), "export_edge.bmp");
	std::cout << "Edge exported" << std::endl;
	STOP_TIMER("Edge Export");
	
	START_TIMER;
	Image_Modifier::invert(bmp_image_2.get());
	std::cout << "Image invertet" << std::endl;
	STOP_TIMER("Invert Algot");

	START_TIMER;
	my_bitmap_handler.export_image(bmp_image_2.get(), "export_invert.bmp");
	std::cout << "Image exportet" << std::endl;
	STOP_TIMER("Invert Export");
	/*
	START_TIMER;
	Image_Modifier::grey_value(bmp_image_2.get());
	std::cout << "Image greyed" << std::endl;
	STOP_TIMER("Grey Algo");

	START_TIMER;
	my_bitmap_handler.export_image(bmp_image_2.get(), "export_grey.bmp");
	std::cout << "Image exportet" << std::endl;
	STOP_TIMER("Grey Export");
	*/
	return true;
}


Image_Processor::~Image_Processor()
{
	//std::cout << "Image Processor destroyed" << std::endl;
}
