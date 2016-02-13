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

		//Should be replaced by an import into a vector
		char *buffer = new char[length];
		input.read(buffer, length);

		unsigned int data_offset = 0;
		data_offset |= (unsigned char)buffer[10];
		data_offset |= (unsigned char)buffer[11] << 8;
		data_offset |= (unsigned char)buffer[12] << 16;
		data_offset |= (unsigned char)buffer[13] << 24;

		unsigned int size_x = 0;
		size_x |= (unsigned char)buffer[18];
		size_x |= (unsigned char)buffer[19] << 8;
		size_x |= (unsigned char)buffer[20] << 16;
		size_x |= (unsigned char)buffer[21] << 24;

		unsigned int size_y = 0;
		size_y |= (unsigned char)buffer[22];
		size_y |= (unsigned char)buffer[23] << 8;
		size_y |= (unsigned char)buffer[24] << 16;
		size_y |= (unsigned char)buffer[25] << 24;

		uint16_t biBitCount = 0;
		biBitCount |= (unsigned char)buffer[28];
		biBitCount |= (unsigned char)buffer[29] << 8;

		unsigned int bCompression = 0;
		bCompression |= (unsigned char)buffer[30];
		bCompression |= (unsigned char)buffer[31] << 8;
		bCompression |= (unsigned char)buffer[32] << 16;
		bCompression |= (unsigned char)buffer[33] << 24;

		auto output = std::make_shared<Image_8>(size_x, size_y);

		unsigned long index = data_offset;

		for (unsigned int i = 0; i < size_y; i++) {
			//Row index must be %4
			unsigned int row_ind = 0;
			for (unsigned int z = 0; z < size_x; z++) {
				output->get_pixel( z, i)->set_RGB((unsigned char)(buffer[index]), (unsigned char)(buffer[index + 1]), (unsigned char)(buffer[index + 2]));
				index += 3;
				row_ind += 3;
				//Catch last Bytes in Row
				if(z == (size_x - 1)) {
					while (row_ind % 4 != 0) { index++; row_ind++; }
				}

			}
		}

		input.close();

		delete[] buffer;

		return output;
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
