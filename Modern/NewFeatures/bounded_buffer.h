#pragma once

#include <stdexcept>

template<typename T, int SIZE>
class bounded_buffer
{
public:  // Nested iterator type definition

	class iter
	{
	public:
		iter(const bounded_buffer * p_vec, int pos)
			: _p_vec(p_vec), _pos(pos)
		{}

		bool operator!=(const iter& other) const
		{
			return _pos != other._pos;
		}

		T operator* () const
		{
			return _p_vec->get(_pos);
		}

		const iter& operator++()
		{
			++_pos;
			return *this;
		}

	private:
		int _pos;
		const bounded_buffer *_p_vec;
	};

public:  // Public methods of bounded_buffer.
	bounded_buffer()
	{}

	iter begin() const
	{
		return iter(this, 0);
	}

	iter end() const
	{
		return iter(this, SIZE);
	}

	T get(int idx) const
	{
		if (idx < 0 || idx >= SIZE)
			throw std::out_of_range("get() index out of range");
		return _data[idx];
	}

	void set(int idx, T value)
	{
		if (idx < 0 || idx >= SIZE)
			throw std::out_of_range("set() index out of range");
		_data[idx] = value;
	}

private:  // Private state.
	T _data[SIZE];
};

