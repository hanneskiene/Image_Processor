#pragma once

#include <vector>
#include <memory>



class Matrix
{
public:
	int size_x;
	int size_y;

	Matrix();
    
	bool set_value(int arg, int val);
	
	bool set_value(int a_x, int a_y, int val);
	
	int get_value(int arg);
	
	int get_value(int a_x, int a_y);
	
	
	~Matrix();
	
private:
	std::vector<int> values;
};
