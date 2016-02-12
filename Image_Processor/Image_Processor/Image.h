#pragma once

#include "Pixel.h"
#include <memory>
#include <vector>
#include <iostream>

class Image
{
public:
	//Create empty Image
	Image();
	//Create Image size X Y
	Image(int, int);

	void set_size(int, int);

	//Could change to return unique_ptr
	Pixel* get_pixel(int);

	Pixel* get_pixel(int, int);

	//Console Output Funktion
	void console_print();

	~Image();
private:
	int size_x;
	int size_y;

	std::vector<std::unique_ptr<Pixel>> pixels;
};
