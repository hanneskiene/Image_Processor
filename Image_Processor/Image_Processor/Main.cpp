//Initializes First Object

#include "Image_Processor.h"
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
	std::cout << "Programm started" << std::endl;

	//Create Main Processing Class
	auto my_Image_Processor = std::make_unique<Image_Processor>();

	//Specify parameters for the Image Processor here
	//my_Image_Processor->someSetter();

	//Run the processing
	my_Image_Processor->run();

	//Destroy the Image Processor
	my_Image_Processor.reset();

	//Everything should have been deleted
	std::cout << "Programm finished" << std::endl;

	std::cin.get();
	return 0;
}