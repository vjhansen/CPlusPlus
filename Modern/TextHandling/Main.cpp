// Main.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <iostream>
#include <string>
#include <regex>

void parse_line(const std::string& line);

int main()
{
	std::ifstream file("Data.txt");
	std::string line;
	while (std::getline(file, line))
	{
		parse_line(line);
	}
    return 0;
}

void parse_line(const std::string& line)
{
	// TODO:
	// Complete the implementation of this function, so that it parses the 
	// incoming line of text to extract its fields. Take a look at Data.txt 
	// to see the format of each line, so you can define your regular expression 
	// appropriately.
	

}

