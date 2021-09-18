// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "Buffer.h"
#include "Ref.h"

typedef buffer<int, 100000> bigintbuf_t;

int main()
{
	// Create a reference-counted Buffer. The ref count is now 1.
	ref<bigintbuf_t> ref1 = new bigintbuf_t();

	// Create additional references to same Buffer. This increments the ref count to 4.
	ref<bigintbuf_t> ref2 = ref1;
	ref<bigintbuf_t> ref3 = ref1;
	ref<bigintbuf_t> ref4 = ref1;

	// Access underlying object. All references will see this change.
	ref1->zeroize();
	(*ref1)[0] = 42;
	std::cout << "Initial values in [0] for ref1, ref2, ref3, ref4" << std::endl;
	std::cout << (*ref1)[0] << std::endl;
	std::cout << (*ref2)[0] << std::endl;
	std::cout << (*ref3)[0] << std::endl;
	std::cout << (*ref4)[0] << std::endl;

	// Reassign a reference to point to a different Buffer. ref4 now snaps away to its own Buffer
	ref4 = new bigintbuf_t();
	ref4->zeroize();
	std::cout << "Values now in [0] for ref1, ref2, ref3, ref4" << std::endl;
	std::cout << (*ref1)[0] << std::endl;
	std::cout << (*ref2)[0] << std::endl;
	std::cout << (*ref3)[0] << std::endl;
	std::cout << (*ref4)[0] << std::endl;

	return 0;
}

