#pragma once

template <typename T>
class ref
{
public:
	ref(T * obj = 0);
	ref(const ref<T> & existingObj);

	~ref();

	ref<T> & operator=(T * obj);
	ref<T> & operator=(const ref<T> & right);

	T & operator*();
	T * operator->();

	bool operator==(const ref<T> & right) const;
	operator bool() const;

private:
	T * obj;

	void decref();
};

// Construct a ref from a raw object. The reference count will be 1.
template <typename T>
ref<T>::ref(T * obj) : obj(obj)
{}

// Construct a ref from an existing ref. Point to same object and increment count.
template <typename T>
ref<T>::ref(const ref<T> & existingObj)
{
	obj = existingObj.obj;
	if (obj != 0)
	{
		obj->inc_ref_count();
	}
}

// Destructor.
template <typename T>
ref<T>::~ref()
{
	decref();
}

// Assignment operator, assign this reference to a different raw object.
template <typename T>
ref<T> & ref<T>::operator=(T * existingObj)
{
	if (obj == existingObj)
		return *this;

	existingObj->inc_ref_count();

	decref();

	obj = existingObj;

	return *this;
}

// Assignment operator, assign this reference to a different reference.
template <typename T>
ref<T> & ref<T>::operator=(const ref<T> & right)
{
	if (this == &right)
		return *this;

	if (right.obj)
		right.obj->increfCount();

	decref();

	obj = right.obj;

	return *this;
}

// Pointer dereference.
template <typename T>
T & ref<T>::operator*()
{
	if (!obj)
	{
		throw std::logic_error("Attempt to dereference ref to null object");
	}
	return *obj;
}

// Pointer member access.
template <typename T>
T * ref<T>::operator->()
{
	if (!obj)
	{
		throw std::logic_error("Attempt to use ref to access member on null object");
	}
	return obj;
}

// Equality test for ref's means "do we point to same object".
template <typename T>
bool ref<T>::operator==(const ref<T> & right) const
{
	return obj == right.obj;
}

// Operator bool tests if we point to an object.
template <typename T>
ref<T>::operator bool() const
{
	return obj != 0;
}

// Helper function, we call this whenever we unhook a ref from its object.
template <typename T>
void ref<T>::decref()
{
	if (obj && obj->dec_ref_count() == 0)
	{
		delete obj;
		obj = 0;
	}
}
