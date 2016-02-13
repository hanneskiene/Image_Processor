#include "Bitmap_Handler.h"

#include <fstream>

Bitmap_Handler::Bitmap_Handler()
{
}

std::shared_ptr<Image> Bitmap_Handler::get_Image(const char * file_name)
{

	auto input = std::ifstream{ file_name, std::ios::binary };
	if (input.is_open()) {

		// get length of file:
		input.seekg(0, input.end);
		auto length = input.tellg();
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


		auto output = std::make_shared<Image>(size_x, size_y);

		int index = data_offset;

		for (int i = 0; i < size_y; i++) {
			//Row index must be %4
			int row_ind = 0;
			for (int z = 0; z < size_x; z++) {
				Color temp_color((unsigned char)(buffer[index]), (unsigned char)(buffer[index + 1]), (unsigned char)(buffer[index + 2]));
				output->get_pixel( z, i)->set_color(temp_color);
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
		return std::make_shared<Image>(0, 0);
		std::cout << "Image not found" << std::endl;
	}
}

bool Bitmap_Handler::export_image(Image * image, const char * file_name) 
{
	std::cout << "WARNING: BMP Output not implemented yet" << std::endl;
	return false;
}

Bitmap_Handler::~Bitmap_Handler()
{
}
