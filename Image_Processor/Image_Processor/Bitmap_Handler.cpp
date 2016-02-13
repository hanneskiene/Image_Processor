#include "Bitmap_Handler.h"

#include <fstream>
#include <iostream>

Bitmap_Handler::Bitmap_Handler()
{
}

std::shared_ptr<Image_8> Bitmap_Handler::get_Image(const char * file_name)
{

	auto input = std::ifstream{ file_name, std::ios::binary };
	if (input.is_open()) {

		// get length of file:
		input.seekg(0, input.end);
		unsigned long length = input.tellg();
		input.seekg(0, input.beg);

		if (length > 50) {

			//Should be replaced by an import into a vector
			char *buffer = new char[length];
			input.read(buffer, length);

			auto data_offset = merge_bytes_unsigned(buffer, 10, 4);

			auto size_x = merge_bytes_unsigned(buffer, 18, 4);

			auto size_y = merge_bytes_unsigned(buffer, 22, 4);

			auto biBitCount = merge_bytes_unsigned(buffer, 28, 2);

			auto bCompression = merge_bytes_unsigned(buffer, 30, 24);

			auto output = std::make_shared<Image_8>(size_x, size_y);

			unsigned long index = data_offset;

			for (unsigned int i = 0; i < size_y; i++) {
				//Row index must be %4
				unsigned int row_ind = 0;
				for (unsigned int z = 0; z < size_x; z++) {
					output->get_pixel(z, i)->set_RGB((unsigned char)(buffer[index]), (unsigned char)(buffer[index + 1]), (unsigned char)(buffer[index + 2]));
					index += 3;
					row_ind += 3;
					//Catch last Bytes in Row
					if (z == (size_x - 1)) {
						while (row_ind % 4 != 0) { index++; row_ind++; }
					}

				}
			}

			input.close();

			delete[] buffer;

			return output;
		}
	}
	else {
		return std::make_shared<Image_8>(0, 0);
		std::cout << "Image not found" << std::endl;
	}
}

bool Bitmap_Handler::export_image(Image_8 * image, const char * file_name) 
{
	std::cout << "WARNING: BMP Output not implemented yet" << std::endl;
	return false;
}

Bitmap_Handler::~Bitmap_Handler()
{
}

unsigned int Bitmap_Handler::merge_bytes_unsigned(char * data,int start, int byte_count)
{
	unsigned int out = 0;
	for (int i = 0; i < byte_count; i++) {
		out |= ((unsigned char)data[start + i] << (i * 8));
	}
	return out;
}
