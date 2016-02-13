#include "Color.h"



template<class T> Color<T>::Color()
{
	r = 0;
	g = 0;
	b = 0;
}

template<class T> Color<T>::Color(T arg)
{
	r = arg;
	g = arg;
	b = arg;
}

template<class T> Color<T>::Color(T a_r, T a_g, T a_b)
{
	r = a_r;
	g = a_g;
	b = a_b;
}

template<class T> void Color<T>::set_color(T arg)
{
	r = arg;
	g = arg;
	b = arg;
}

template<class T> void Color<T>::set_color(T a_r, T a_g, T a_b)
{
	r = a_r;
	g = a_g;
	b = a_b;
}

template<class T> T Color<T>::get_r() { return r; }

template<class T> T Color<T>::get_g() { return g; }

template<class T> T Color<T>::get_b() { return b; }


template<class T> Color<T>::~Color()
{
	//std::cout << "Color destroyed" << std::endl;
}
