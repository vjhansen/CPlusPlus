#pragma once

#include <memory>
#include <vector>

/*

Smart Pointers - Managing Smart Pointers

- Creating and maintaining a collection of tasks 
- Maintaining circular references between all tasks 

Exercise 1: We've implemented a simple task class, which might
represent a task running in a multithreaded application. Each task will have a unique id,
plus a running flag (you can toggle the state of this flag at any time via
the toggle_status() method). Now take a look at Main.cpp. You'll add a lot of
code in here, as per the comments, to create and manipulate a collection of
tasks.


Exercise 2:  Creating and maintaining a collection of
tasks. 
- Add code to Main.cpp, as indicated by the following comments, to create
and manipulate a collection of tasks: Declare a vector named tasks, to hold
shared_ptrs to all the tasks that will exist in the system. Then create some
tasks and insert them into the vector. Set up another shared_ptr to one of
the tasks, to illustrate the fact we're using shared_ptrs. This will
increment the usage count. Do something with some of the tasks, e.g. toggle
their status. For one of the shared_ptrs, set its internal pointer to null.
This will decrement the usage count. If the usage count is 0, the target
object will be deleted. In this case, you must remove the shared_ptr from the
vector - use erase(). 

Exercise 3:  Maintaining circular references between
all tasks In the application, we want every task object to know about every
other task object. This could be useful in the application, to facilitate inter-task communication perhaps. You can't use
shared_ptrs to achieve this, because there are circular references and this
can't be done with shared_ptrs. Instead, you will use weak_ptrs – this is one
of the main usage scenarios for weak_ptrs. Here's what you need to do: In
task.h, add a data member to hold a collection of weak_ptrs to tasks. In
task.cpp, implement check_all_tasks(). In the method, iterate through all the
weak_ptrs for tasks. For each weak_ptr, try to upgrade it to a shared_ptr,
and then display the underlying task. In Main.cpp, near the start of the
program, hook up each task to all the other tasks. To do this, we suggest you
use nested loops: The outer loop iterates over all the tasks. The inner
iterates over all the tasks again, and adds each of these tasks to
the "current" task in the outer loop (don't add a reference to yourself
though). Still in Main.cpp, near the end of the program, loop through all
tasks. For each task, ask it to check the status of all the other tasks, via
the check_all_tasks() method you implemented just now.

*/


class task
{
public:

	~task();

	void toggle_status();
	void check_all_tasks() const;

	int id = generate_id();
	bool running = true;

	// TODO 2a: 
	// Hold a collection of weak_ptrs to all the tasks.
	std::vector<std::weak_ptr<task>> wpts;


private:
	int generate_id() const;
};

