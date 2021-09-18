#pragma once

#include <stdexcept>
#include "refcounted.h"

template <typename T, int SIZE>
class buffer : public refcounted
{
public:
	// Allow default constructor, but disallow copy constructor and copy assignment operator.
	buffer() = default;
	buffer(const buffer &) = delete;
	buffer& operator=(const buffer &) = delete;

	void zeroize();

	T & operator[] (int index);
	const T & operator[] (int index) const;

private:
	T data[SIZE];
};

template <typename T, int SIZE>
void buffer<T, SIZE>::zeroize()
{
	for (int i = 0; i < SIZE; i++)
		data[i] = T();
}

template <typename T, int SIZE>
T & buffer<T, SIZE>::operator[] (int index)
{
	if (index < 0 || index >= SIZE)
		throw std::out_of_range("Buffer index out of range");

	return data[index];
}

template <typename T, int SIZE>
const T & buffer<T, SIZE>::operator[] (int index) const
{
	if (index < 0 || index >= SIZE)
		throw std::out_of_range("Buffer index out of range");

	return data[index];
}
