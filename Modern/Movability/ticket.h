#pragma once

#include <initializer_list>
#include <string>

class ticket
{
public:
	//  - regular constructor (to initialize the ticket object originally, with a series of lottery numbers)
	/* Define a regular constructor to set the numbers for the ticket. 
		The constructor should receive any amount of numbers, 
		allocate an array of that size, and copy the numbers into the array. 
		The constructor should also remember the size of the array, obviously.
		Also define a simple destructor that deallocates the array when the ticket object is being destructed.
	*/ 
	ticket(std::initializer_list<int> numbers);
	
	//  - copy constructor and move constructor
	ticket(const ticket& rhs);
	ticket(ticket&& rhs) noexcept;

	//  - copy assignment operator and move assignment operator
	ticket& operator=(const ticket& src);
	ticket& operator=(ticket&& rhs) noexcept;

	//  - destructor
	~ticket();
	void clean();
	void moveFrom(ticket& src) noexcept;

private:
	int *numbers; 	/* numbers is a raw pointer, which will be initialized 
						to point to a dynamically allocated array of numbers. 
					*/
	int count; 		/* count is the size of the dynamically allocated array. 
						This variable is required because the array won't remember 
						its size on its own. 
					*/
};
