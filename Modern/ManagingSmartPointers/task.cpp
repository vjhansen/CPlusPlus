
#include "task.h"
#include <iostream>

task::~task()
{
	std::cout << "Task " << id << " being destroyed" << "\n";
}

void task::toggle_status()
{
	running = !running;
}


// TODO 2b:
// Iterate through all the weak_ptrs for tasks.
// For each weak_ptr, try to upgrade it to a shared_ptr, 
// and then display the underlying task.
void task::check_all_tasks() const
{
	for (auto&& wp : wpts) 
	{
		auto p = wp.lock();
		if (p)
		{
			std::cout << p->id << ", " << p->running << "\n";
		}
	}	
}



int task::generate_id() const
{
	static int next_id = 100;
	return next_id++;
}
