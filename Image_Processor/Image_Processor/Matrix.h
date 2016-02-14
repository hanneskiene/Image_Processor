#pragma once

#include <vector>
#include <memory>



class Matrix
{
public:
	
	Matrix()
	{
		size_x = 0;
		size_y = 0;
		values.reserve(size_x * size_y);
		//Add values to Matrix
		for (int i = 0; i < size_x; i++) {
			for (int z = 0; z < size_y; z++) {
				values.push_back(0);
			}
		}
	}
	bool set_value(int arg,int val)
	{
		values.at(arg)=val;
		return true;
	}
	bool set_value(int a_x, int a_y, int val)
	{
		values.at(a_y * size_x + a_x) = val;
		return true;
	}
	int get_value(int arg)
	{
		return values.at(arg);
	}
	int get_value(int a_x, int a_y)
	{
		return values.at(a_y * size_x + a_x);
	}
	int size_x;
	int size_y;
	~Matrix()
	{

	}
private:
	std::vector<int> values;
};
