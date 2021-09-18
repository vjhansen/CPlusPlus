#pragma once

#include <functional>

// This class is already complete.
class command
{
public:
	command()
	{}

	command(std::function<void()> func)
		: func(func)
	{}

	template <typename T>
	void set_function(T func)
	{
		this->func = func;
	}

	void execute()
	{
		if (func)
		{
			func();
		}
	}

private:
	std::function<void()> func;
};
