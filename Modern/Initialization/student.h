#pragma once

#include <string>
#include <list>
#include <iostream>

class student
{
public:
	// TODO:
	// Declare 2 constructors here:
	//   - the 1st constructor takes just the student's name.
	//   - the 2nd constructor takes the student's name plus a list of subjects.


	virtual void display() const;

private:
	std::string name;
	std::list<std::string> subjects;
	int credits[4];
	
	// TODO:
	// Initialize the fine_accrued to 50 (i.e. assume student will do at least £50 of damage!)
	double fine_accrued;

	// TODO:
	// Initialize the id to a unique id (use some kind of static id generator).
	int id;
};


// TODO: 
// Define an international_student class.
// An international student is a kind of student, with the same constructors.
// Override display() to display a prefix message "[International student]", 
// followed by the normal student data.