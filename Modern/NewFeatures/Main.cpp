// Main.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include "myheader.h"
#include "bounded_buffer.h"

void ex1();
void ex2();
void ex3();

int main()
{
	ex1();
	ex2();
	ex3();

    return 0;
}

void ex1()
{
	// TODO 1a: 
	// In the bounded_buffer class, implement an allocsize() function 
	// that tells you the total size of a bounded_buffer object (hint: use constexpr).
	// Then call allocsize() on buffer1 here. The answer should be 48 bytes.
	bounded_buffer<double, 6> buffer1;


	// TODO 1b:
	// In the bounded_buffer class, add a static assert to ensure that the
	// SIZE type parameter is at least 6 (for example).
	// Then declare a bounded_buffer variable here, that fails the test.


	// TODO 1c:
	// Add a "using" statement here, similar to a typedef, to create a new type
	// representing a block of 500 characters. For example:
	// 	    using block = struct { char singlemember[500]; };
    //
	// Then in the bounded_buffer class, add a static assert to ensure the size
	// of the data type parameter is less than 100 (say).
	// Then declare a bounded_buffer variable here, that fails the test.
	using block = struct {char singlemember[500];};
	
		

}

void ex2()
{
	// TODO: 
	// In myheader.h, define a variadic template function named adder() to add a series of items recursively.
	// The template function requires two type parameters as follows:
	//     template<typename T, typename... Args>
	// typename T represents a single value.
    // typename... Args is a "template parameter pack".
	//
	// The adder() function signature should be as follows:
	//     T adder(const T& first, const Args&... args) 
	// const T& first is the first value to add.
	// const Args&... args is the "function parameter pack", i,e, all the other values to add.
	//
	// Implement the function recursively as follows:
	//     return first + adder(args...);
	// adder(args...) peels the first value off the list and passes it into "first" in adder().
	// The remaining values are passed into "args" in adder().
	// Thus each recursive call to adder() reduces the function parameter pack by 1 element.

	// TODO:
	// When you've done all that, uncomment the following statements to add some numbers.
	//    long nsum = adder(n1, n2, n3, n4, n5, n6);
	//    std::cout << "Number sum: " << nsum << "\n\n";

	// TODO:
	// Also uncomment the following statements, to add some strings.
	//    std::string s1 = "Andy", s2 = "Jayne", s3 = "Emily", s4 = "Tom";
	//    std::string ssum = adder(s1, s2, s3, s4);
	//    std::cout << "String sum: " << ssum << "\n\n";

}

void ex3()
{
	// TODO:
	// Similar to ex2() above, implement pair_comparer() in myheader.h
	// so that it takes a series of values and returns true if the series is a set of pairs.

	// TODO: 
	// Uncomment the following. It should print "true".
	//    bool result1 = pair_comparer(180, 180, 42, 42, 101, 101);
	//    std::cout << "result1: " << result1 << "\n\n";     

	// TODO: 
	// Uncomment the following. It should print "true".
	//    bool result2 = pair_comparer("mickey", "mickey", "donald", "donald");
	//    std::cout << "result2: " << result2 << "\n\n";

	// TODO: 
	// Uncomment the following. It should print "false".
	//    bool result3 = pair_comparer("mickey", "minnie", "donald", "goofy");
	//    std::cout << "result3: " << result3 << "\n\n";
}

