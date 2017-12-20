#include "Window.hpp"

Window::Window(std::string filename) : Map(filename) 
{
	scale = calcScale(height, width);
}

int Window::calcScale(const int calc_height, const int calc_width)
{
	int ret_scale;
	int scale_x = 1280/calc_width;
	int scale_y = 720/calc_height;
	if(scale_x > scale_y) {
		ret_scale = (float)scale_y;
	}
	else
		ret_scale = (float)scale_x;
	return ret_scale;
}


