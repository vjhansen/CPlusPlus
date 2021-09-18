// Main.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <list>

std::list<int> find_factors(int from, int to)
{
	std::list<int> primes;

	for (int number = from; number <= to; number++) 
	{
		// TODO 2:
		// Introduce an artificial delay of 50ms per iteration, to slow things about for illustrative purposes.
		bool isprime = true;
		for (int i = 2; i < number; i++) 
		{
			if (number % i == 0) 
			{
				isprime = false;
				break;
			}
		}
		if (isprime) 
		{
			primes.push_back(number);
		}
	}
	return primes;
}


int main()
{
	std::cout << "Starting an async operation to find all the prime numbers between 1 and 100" << std::endl;

	// TODO 3a:
	// Start an async operation to find all the prime numbers between 1 and 100.


	// TODO 3b:
	// Wait until the result is ready.
	// Display a "heartbeat" message (e.g. every 1 second) to indicate we're doing something useful in the meantime.


	// TODO 3c:
	// When the results are finally available, get them and display on the console.

	return 0;
}

