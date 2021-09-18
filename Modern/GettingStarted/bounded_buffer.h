#pragma once

#include <stdexcept>

template<typename T, int SIZE>
class bounded_buffer
{
	// TODO: Define a nested iterator type here.


public:  
	bounded_buffer() 
	{}

	// TODO: Add methods to support range-based for loops over bounded_buffer.


	T get(int idx) const
	{
		if (idx < 0 || idx >= SIZE)
			throw std::out_of_range("get() index out of range");
		return _data[idx];
	}

	void set(int idx, T value) 
	{
		if (idx < 0 || idx >= SIZE)
			throw std::out_of_range("set() index out of range");
		_data[idx] = value;
	}

private:  // Private state.
	T _data[SIZE];
};

