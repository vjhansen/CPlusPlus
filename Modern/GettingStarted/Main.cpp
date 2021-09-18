// Main.cpp : Defines the entry point for the console application.

#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "bounded_buffer.h"

template<typename T>
std::string get_type(T t) 
{
	return typeid(t).name();
}

void ex1();
void ex2();
void ex3();

int main()
{
	ex1();	// Using auto.
	ex2();	// Range-based for loops.
	ex3();	// Making a custom class iterable using range-based for loops.

    return 0;
}

void ex1()
{
	// TODO: 
	// Declare some auto variables, and call get_type(variableName) to get the type name.
	// For example:
	auto i = 42;
	std::cout << get_type(i) << "\n\n";
}

void ex2()
{
	// TODO: Use a range-based for loop to iterate over an array.


	// TODO: Use a range-based for loop to iterate over an STL collection, e.g. a map.


}

void ex3()
{
	bounded_buffer<int, 6> buff;

	// Set values in buffer.
	for (int i = 0; i < 6; i++)
	{
		buff.set(i, i * 1000);
	}

	// TODO: Replace this with a range-based for loop.
	for (int i = 0; i < 6; i++)
	{
		std::cout << buff.get(i) << std::endl;
	}
}
