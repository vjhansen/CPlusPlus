
#include <memory>
#include <vector>
#include <iostream>
#include "task.h"

int main()
{
	// TODO 1a:
	// Declare a vector named "tasks", to hold shared_ptrs to all the tasks that will exist in the system.
	// Then create some tasks and insert them into the vector.

	std::vector<std::shared_ptr<task>> tasks;
	for (auto i = 0; i < 5; ++i)
	{
		tasks.push_back(std::make_shared<task>());
	}

	// TODO 2c:
	// Hook up each task to all the other tasks. Must use weak_ptrs due to circular references.
	for (auto pt : tasks)
	{
		for (auto i : tasks)
		{
			i->wpts.push_back(std::weak_ptr<task>(pt));
		}
	}

	// TODO 1b:
	// Set up another shared_ptr to one of the tasks, to illustrate the fact we're using shared_ptrs.

	//std::shared_ptr<task> t(tasks.at(3));
	
	// TODO 1c:
	// Do something with some of the tasks, e.g. toggle their status.
	tasks.at(0)->toggle_status();
	tasks.at(1)->toggle_status();

	
	
	// TODO 1d:
	// For one of the shared_ptrs, set its internal pointer to null. This will decrement the usage count. 
	// If usage count is 0, the target object will be deleted. In this case, you must remove shared_ptr from the vector - use erase().
	tasks.at(4) = nullptr;
	if (tasks.at(4).use_count() == 0)
	{
	 	tasks.erase(tasks.begin()+4);
	}

	// TODO 2d:
	// Loop through all tasks. For each task, ask it to check the status of all the other tasks.
	for (auto t : tasks)
	{
		t->check_all_tasks();
	}

    return 0;
}

