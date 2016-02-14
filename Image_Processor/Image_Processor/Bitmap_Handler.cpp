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

			unsigned int row_ind = 0;

			auto pixels = output->get_pixels();

			unsigned int z = 0;

			for (auto it = pixels->begin(); it != pixels->end(); it++) {
				(*it)->set_RGB((unsigned char)(buffer[index]), (unsigned char)(buffer[index + 1]), (unsigned char)(buffer[index + 2]));
				index += 3;
				row_ind += 3;
				z++;
				//Catch last Bytes in Row
				if (z == (size_x)) {
					while (row_ind % 4 != 0) { index++; row_ind++; }
					row_ind = 0;
					z = 0;
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
	auto output = std::ofstream{ file_name, std::ios::binary };

	output << "BM";
	//File Size Parameter
	uint32_t var_32_u = 54 + 3 * image->get_pixels()->size(); 
	for (int i = 0; i < ((image->size_x * 3) % 4); i++) {
		var_32_u += image->size_y;
	}
	output.write( (char*) &var_32_u, sizeof(var_32_u));
	//Reserved
	var_32_u = 0;
	output.write((char*)&var_32_u, sizeof(var_32_u));
	//Image offset
	var_32_u = 54;
	output.write((char*)&var_32_u, sizeof(var_32_u));
	//Infoheader Size
	var_32_u = 40;
	output.write((char*)&var_32_u, sizeof(var_32_u));
	//Width
	int32_t var_32_s = image->size_x;
	output.write((char*)&var_32_s, sizeof(var_32_s));
	//Height
	var_32_s = image->size_y;
	output.write((char*)&var_32_s, sizeof(var_32_s));
	//Unused
	uint16_t var_16_u = 1;
	output.write((char*)&var_16_u, sizeof(var_16_u));
	//biBitCount
	var_16_u = 24;
	output.write((char*)&var_16_u, sizeof(var_16_u));
	//Compression
	var_32_u = 0;
	output.write((char*)&var_32_u, sizeof(var_32_u));
	//SizeImage
	var_32_u = 0;
	output.write((char*)&var_32_u, sizeof(var_32_u));
	//Pixels per Meter
	var_32_u = 0;
	output.write((char*)&var_32_u, sizeof(var_32_u));
	output.write((char*)&var_32_u, sizeof(var_32_u));
	//Color Table
	var_32_u = 0;
	output.write((char*)&var_32_u, sizeof(var_32_u));
	//Colors used
	var_32_u = 0;
	output.write((char*)&var_32_u, sizeof(var_32_u));

	unsigned int row_ind = 0;

	auto pixels = image->get_pixels();

	unsigned int z = 0;

	for (auto it = pixels->begin(); it != pixels->end(); it++) {
		int t_r = (*it)->get_r();
		output.write((char*)&(t_r), 1);
		int t_g = (*it)->get_g();
		output.write((char*)&(t_g), 1);
		int t_b = (*it)->get_b();
		output.write((char*)&(t_b), 1);
		row_ind += 3;
		z++;
		//Catch last Bytes in Row
		if (z == (image->size_x)) {
			while (row_ind % 4 != 0) { 
				row_ind++; 
				uint8_t t_a = 0;
				output.write((char*)&t_a, 1);
			}
			row_ind = 0;
			z = 0;
		}
	}

	output.close();

	return true;
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
