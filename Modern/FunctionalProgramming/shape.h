#pragma once

#include <iostream>

class shape
{
public:
	shape(int x, int y, int w, int h)
		: x(x), y(y), w(w), h(h)
	{}

	void move_by(int dx, int dy)
	{
		x += dx;
		y += dy;
		std::cout << "After move_by(" << dx << "," << dy << "):" << std::endl << *this << std::endl << std::endl;
	}

	void resize_by(int dw, int dh)
	{
		w += dw;
		h += dh;
		std::cout << "After resize_by(" << dw << "," << dh << "):" << std::endl << *this << std::endl << std::endl;
	}

	void double_size()
	{
		w *= 2;
		h *= 2;
		std::cout << "After double_size():" << std::endl << *this << std::endl << std::endl;
	}

	friend std::ostream& operator<<(std::ostream & os, const shape & s)
	{
		return std::cout << "     location: (" << s.x << ", " << s.y << "), width: " << s.w << ", height: " << s.h;
	}

private:
	int x, y, w, h;
};

