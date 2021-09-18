#pragma once

#include <string>
#include <map>

struct element
{
	int atomic_number;
	std::string symbol;
	std::string name;
	int group;
	int period;
	double atomic_weight;

	friend std::ostream& operator << (std::ostream & os, const element & elem)
	{
		os  << "Atomic number: " << elem.atomic_number << ", " 
			<< "Symbol: "        << elem.symbol        << ", "
			<< "Name: "          << elem.name          << ", "
			<< "Group: "         << elem.group         << ", "
			<< "Period: "        << elem.period        << ", "
			<< "Atomic weight: " << elem.atomic_weight;
		return os;
	}

	// TODO 3:
	// Implement an equality test for elements.


};

class periodic_table
{
	// TODO 2:
	// Implement the periodic_table class.


};


// TODO 3:
// Implement hash support for the element structure.
