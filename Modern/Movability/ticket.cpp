
#include "ticket.h"
#include <iostream>


// Regular
ticket::ticket(std::initializer_list<int> numberList) 
{
	count = numberList.size();
	numbers = new int[count];
	auto i = 0;
	for (auto x : numberList)
	{
		numbers[i++] = x;
	}
	std::cout <<"Regular" << "\n";
}
	

ticket::ticket(const ticket& src) 
{
	count = src.count;
	numbers = new int[count];
	for (auto i = 0; i < count; ++i)
	{
		numbers[i] = src.numbers[i];
	}
	std::cout << "Regular" << "\n";
}



ticket& ticket::operator=(const ticket& src) 
{
	if (this == src) 
		return *this;
	clean();
	count = src.count;
	numbers = new int[count];
	for (auto i = 0; i < count; ++i)
	{
		numbers[i++] = src.numbers[i];
	}
	return *this;
	std::cout << "Copy =" << "\n";
}


//  - destructor
ticket::~ticket() 
{
	delete [] numbers;
	numbers = nullptr;
	std::cout << "dtor" << "\n";
}


ticket::ticket(ticket&& src) noexcept
{
	moveFrom(src);
	std::cout << *this << "\n";

}


// Move assignment
ticket& ticket::operator=(ticket&& rhs) noexcept
{
	clean();
	moveFrom(rhs);
	std::cout << *this << "\n";
	return *this;
}


void ticket::clean() noexcept 
{
	delete [] numbers;
	numbers = nullptr;
	std::cout << "Clean" << "\n";
}


void ticket::moveFrom(ticket& src) noexcept 
{
	count= src.count;
	numbers = src.numbers;
	src.numbers = nullptr;
	src.count = 0;
}