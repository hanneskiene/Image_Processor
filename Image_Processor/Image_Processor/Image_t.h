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

		//Add Pixels to Image
		for (int i = 0; i < size_x; i++) {
			for (int z = 0; z < size_y; z++) {
				pixels.push_back(std::make_unique<Pixel_t<T>>());
			}
		}
	}

	Pixel_t<T> * get_pixel(int arg)
	{
		return pixels.at(arg).get();
	}

	Pixel_t<T> * get_pixel(int a_x, int a_y)
	{
		return pixels.at(a_y * size_x + a_x).get();
	}

	void console_print()
	{
		//In order not to display every Pixel
		const int compression = 5;
		for (int i = 0; i < size_y; i++) {
			if (i % compression == 0) {
				for (int z = 0; z < size_x; z++) {
					if (z % compression == 0) {
						if (pixels.at(i*size_x + z)->get_r() > 150)
							std::cout << "0";
						else
							std::cout << " ";
					}
				}
				std::cout << std::endl;
			}
		}
	}

	std::vector<std::unique_ptr<Pixel_t<T>>>* get_pixels()
	{
		return &pixels;
	}

	~Image_t()
	{

	}

	int size_x;
	int size_y;
private:
	std::vector<std::unique_ptr<Pixel_t<T>>> pixels;
};

//Default Image Type
using Image_8 = Image_t<unsigned char>;