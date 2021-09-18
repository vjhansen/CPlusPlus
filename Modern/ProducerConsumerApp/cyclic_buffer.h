#pragma once

#include <cstdlib>
#include <iostream>
#include <iomanip>

template <typename T>
class cyclic_buffer
{
private:
	// State data members.
	T * pBuffer;
	int count, size;
	int readPos, writePos;

public:
	// Constructor/destructor.
	cyclic_buffer(int size);
	~cyclic_buffer();

	// Producer/consumer methods.
	void insert(T & item);
	bool retrieve_and_display();

private:
	// Helper methods.
	void advance_pos(int & pos)
	{
		pos = (pos + 1) % size;
	}

	void random_sleep(int base, int extra)
	{
		int sleepAmount = base + std::rand() % extra;
		// Sleep here...
	}
};

//===================================================================================================================
// Implementation of template member functions.
//===================================================================================================================

// Constructor.
template <typename T>
cyclic_buffer<T>::cyclic_buffer(int size) :
	pBuffer(new T[size]),
	count(0),
	size(size),
	readPos(0),
	writePos(0)
{
}

// Destructor.
template <typename T>
cyclic_buffer<T>::~cyclic_buffer()
{
	delete[] pBuffer;
}


// Insert an item into the buffer.
template <typename T>
void cyclic_buffer<T>::insert(T & item)
{
	// If the buffer is full, just do nothing (i.e. the item is not inserted). You will implement a better approach in this lab!
	if (count == size)
		return;

	// Insert the item at the current write position, advance the write position, and increment the count of items.
	pBuffer[writePos] = item;
	advance_pos(writePos);
	count++;
}


// Retrieve and display item from the buffer. Return true if an item was retrieved successfully, else false.
template <typename T>
bool cyclic_buffer<T>::retrieve_and_display()
{
	if (count == 0)
		return false;

	// Display info about the item and the current thread.
	std::cout << "Retrieved from position[" << readPos << "], "
		<< pBuffer[readPos]
		<< std::endl;

	// Decrement the count of items, and advance the read position.
	count--;
	advance_pos(readPos);

	return true;
}
