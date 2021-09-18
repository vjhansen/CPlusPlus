#include "stdafx.h"
#include "student.h"

// TODO:
// Implement student constructors here.
// Make appropriate use of constructor delegation.
// Also use brace-delimited initialization to set the credits array to 10, 0, 0, 0 
// i.e. 10 credits for the first year, then 0 for the other three years.

void student::display() const
{
	std::cout << name << "[id " << id << "], subjects: ";
	for (auto s : subjects)
	{
		std::cout << s << " ";
	}

	std::cout << std::endl << "Credits: ";
	for (auto c : credits)
	{
		std::cout << c << " ";
	}

	std::cout << std::endl << "Fine accrued: " << fine_accrued << std::endl << std::endl;
}

// TODO:
// Implement international_student::display() here.
