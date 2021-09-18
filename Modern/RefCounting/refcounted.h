#pragma once

class refcounted
{
public:
	refcounted() : count(1)
	{}

	void inc_ref_count()
	{
		count++;
	}

	int dec_ref_count()
	{
		return --count;
	}

private:
	int count;
};
