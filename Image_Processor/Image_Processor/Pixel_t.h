#pragma once

template<class T>
class Pixel_t
{
public:
	Pixel_t() 
	{
		r = 0;
		g = 0;
		b = 0;
	}

	void set_RGB(T a_r, T a_g, T a_b) 
	{
		r = a_r;
		g = a_g;
		b = a_b;
	}

	T get_r() { return r; }
	T get_g() { return g; }
	T get_b() { return b; }

	~Pixel_t() 
	{

	}

//private:
	T r, g, b;
};

using Pixel_8 = Pixel_t<unsigned char>;

