// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>


template<typename T>

class Vector
{
private:
	size_t sz;
	size_t cp;
	T* elem;
public:
	Vector() : sz(0),cp(0), elem(new T[sz]) {}
	Vector(size_t s) {
		sz = s;
		elem = new T[s];
	}
	Vector(size_t s, T val) {
		sz = s;
		elem = new T[s];
		std::fill_n(elem, s, val);
	}
	~Vector() { delete[] elem; }

	Vector(const Vector& v) :elem{ new T[v.sz] }, sz{ v.sz } {
		for (size_t i = 0; i != sz; ++i) elem[i] = v.elem[i];
	}
	void setSize(size_t size) { sz = size; }
	size_t capacity() { return sz; }
	size_t size() { return cp; }
	T getElem(size_t i) { return elem[i]; }

	void push_back(T item);

	T& operator[](size_t i) { return elem[i]; }
	Vector& operator=(const Vector& v) {
		if (&v == this) return *this;
		T* p = new T[v.sz];
		for (size_t i = 0; i != v.sz; ++i)
			p[i] = v.elem[i];
		delete[] elem;
		elem = p;
		sz = v.sz;
		return *this;
	}

	
};

template <typename T>

void Vector<T>::push_back(T item) {
	if (sz == 0)
	{
		++sz;
		elem = (T*)realloc(elem, sz * sizeof(T));
		++cp;
		elem[cp - 1] = item;
	}
	else if (sz == cp)
	{
		sz *= 1.5;
		++sz;
		elem = (T*)realloc(elem, sz * sizeof(T));
		++cp;
		elem[cp - 1] = item;
	}
	else
	{
		++cp;
		elem[cp - 1] = item;
	}
}



// TODO: reference additional headers your program requires here
