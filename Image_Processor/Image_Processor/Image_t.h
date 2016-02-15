#pragma once

#include <vector>
#include <memory>
#include "Pixel_t.h"

template <class T>
class Image_t
{
public:
	Image_t()
	{
		size_x = 0;
		size_y = 0;
	}

	Image_t(int a_x, int a_y)
	{
		size_x = a_x;
		size_y = a_y;
		//std::vector<Pixel_t<T>> pixels(size_x * size_x, Pixel_t<T>());
		pixels.reserve(size_x * size_y);
		//Add Pixels to Image
		for (int i = 0; i < size_x; i++) {
			for (int z = 0; z < size_y; z++) {
				pixels.push_back(Pixel_t<T>());
			}
		}
	}

	Pixel_t<T> * get_pixel(int arg)
	{
		return &pixels.at(arg);
	}

	Pixel_t<T> * get_pixel(int a_x, int a_y)
	{
		return &pixels.at(a_y * size_x + a_x);
	}

	std::vector<Pixel_t<T>>* get_pixels()
	{
		return &pixels;
	}

	int  checkIndexBounds(int index) {
		if (index < 0) {
			index = 0;
		}
		else if (index >= size_x*size_y){
			index = size_y*size_y;
		}
		return index;
	}

	~Image_t()
	{

	}

	int size_x;
	int size_y;
private:
	std::vector<Pixel_t<T>> pixels;
};

//Default Image Type
using Image_8 = Image_t<unsigned char>;