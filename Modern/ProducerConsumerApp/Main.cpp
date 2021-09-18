// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "cyclic_buffer.h"

// Global buffer, for simplicity.
cyclic_buffer<int> buffer(10);

// Function for the producer thread.
void produce()
{
	// Produce some items for the buffer.
	for (int i = 0; i < 20; i++)
	{
		buffer.insert(i);
	}
}

// Function for the consumer thread.
void consume()
{
	// Keep retrieving/displaying items from the buffer until the function returns false.
	while (buffer.retrieve_and_display())
		;
}


int main()
{
	// Call produce() synchronously.
	produce();

	// Call consume() synchronously.
	consume();

	return 0;
}

