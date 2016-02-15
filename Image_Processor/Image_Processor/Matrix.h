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
	bool set_value(int v0, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8);
	int get_value(int arg);
	
	int get_value(int a_x, int a_y);

	int checkIndexBounds(int index);
	
	
	~Matrix();
	
private:

	std::vector<int> values;
};
