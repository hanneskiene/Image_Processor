#include "Matrix.h"
Matrix::Matrix()
{
	size_x = 3;
	size_y = 3;
	values.reserve(size_x * size_y);
	//Add values to Matrix
	for (int i = 0; i < size_x; i++) {
		for (int z = 0; z < size_y; z++) {
			values.push_back(0);
		}
	}
}
bool Matrix::set_value(int arg, int val)
{
	values.at(arg) = val;
	return true;
}
bool Matrix::set_value(int a_x, int a_y, int val)
{
	values.at(a_y * size_x + a_x) = val;
	return true;
}
int Matrix::get_value(int arg)
{
	return values.at(arg);
}
int Matrix::get_value(int a_x, int a_y)
{
	return values.at(a_y * size_x + a_x);
}

bool Matrix::set_value(int v0, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8) {
	values.at(0) = v0;
	values.at(1) = v1;
	values.at(2) = v2;
	values.at(3) = v3;
	values.at(4) = v4;
	values.at(5) = v5;
	values.at(6) = v6;
	values.at(7) = v7;
	values.at(8) = v8;
	return true;
}
Matrix::~Matrix()
{

}