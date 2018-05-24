#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <limits>


template<typename T>

class Vector
{
private:
	size_t cp;
	size_t sz;
	T* elem;
public:
	//Default constructors
	Vector() : sz(0), cp(0), elem(new T[sz]) {}
	Vector(size_t s) {
		cp = s;
		sz = s;
		elem = new T[s];
	}
	Vector(size_t s, T val) {
		cp = s;
		sz = s;
		elem = new T[s];
		std::fill_n(elem, s, val);
	}
	~Vector() { delete[] elem; }

	//Copy constructor
	Vector(const Vector& v) : elem{ new T[v.cp] }, cp{ v.cp } {
		for (size_t i = 0; i != sz; ++i) elem[i] = v.elem[i];
	}

	//Move constructor
	Vector(const Vector&& v) : elem{ v.elem }, cp{ v.cp } {
		v.elem = nullptr;
		v.sz = 0;
	}



	//getters
	size_t capacity() { return cp; }
	size_t size() { return sz; }
	T at(size_t i) { return elem[i]; }
	T front() { return elem[0]; }
	T back() { return elem[sz - 1]; }
	T* data() { return &elem[0];  }
	T& operator[](size_t i) { return elem[i]; }

	//push_back apibrezimas
	void push_back(T item);


	//Copy assignment operator
	Vector& operator=(const Vector& v) {
		if (&v == this) return *this;
		T* p = new T[v.cp];
		for (size_t i = 0; i != v.cp; ++i)
			p[i] = v.elem[i];
		delete[] elem;
		elem = p;
		cp = v.cp;
		return *this;
	}

	//Move assignment operator
	Vector& operator=(Vector&& v) {
		if (&v == this) return *this;
		delete[] elem;
		cp = v.cp;
		v.elem = nullptr;
		v.cp = 0;
		return *this;
	}


	//Iterators
	T* begin() { return &elem[0]; }
	T* end() { return &elem[sz]; }
	T* rbegin() { return &elem[sz - 1]; }
	T* rend() { return &(elem[-1]); }

	//Funkcijos darbui su capacity
	bool empty() {
		if (sz == 0) return true;
		else return false;
	}
	size_t max_size() { return std::numeric_limits<size_t>::max(); }

	void reserve(size_t size) {
		if (size > cp) {
			elem = (T*)realloc(elem, size * sizeof(T));
			cp = size;
		}
	}
	void resize(size_t size) {
		elem = (T*)realloc(elem, size * sizeof(T));
		cp = size;
	}
	void shrink_to_fit() {
		elem = (T*)realloc(elem, sz * sizeof(T));
		cp = sz;
	}

	//void erase(T*, T*);
	T* Vector<T>::insert(const T* pos, T value);
};

template <typename T>

void Vector<T>::push_back(T item) {
	if (sz == 0)
	{
		++cp;
		elem = (T*)realloc(elem, cp * sizeof(T));
		++sz;
		elem[sz - 1] = item;
	}
	else if (sz == cp)
	{
		cp *= 2;
		++cp;
		elem = (T*)realloc(elem, cp * sizeof(T));
		++sz;
		elem[sz - 1] = item;
	}
	else
	{
		++sz;
		elem[sz - 1] = item;
	}
}

//template <typename T>
//
//void Vector::erase(T* begin, T* end)
//{
//
//}

template <typename T>

T* Vector<T>::insert(const T* pos, T value)
{
	if (sz == cp) {
	cp = cp * 2;
	elem = (T*)realloc(elem, cp * sizeof(T));
	}
	++sz;
	std::iterator it
	for (size_t i = sz; i != pos; --i) {
		elem[i + 1] = elem[i];
	}
	*pos = value;
	return pos
}