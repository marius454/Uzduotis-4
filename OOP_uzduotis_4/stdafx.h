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

class Vector
{
private:
	int sz;
	int cp;
	double* elem;
public:
	Vector() : sz(0),cp(0), elem(new double[sz]) {}
	Vector(int s) {
		sz = s;
		elem = new double[s];
	}
	Vector(int s, double val) {
		sz = s;
		elem = new double[s];
		std::fill_n(elem, s, val);
	}
	~Vector() { delete[] elem; }

	Vector(const Vector& v) :elem{ new double[v.sz] }, sz{ v.sz } {
		for (int i = 0; i != sz; ++i) elem[i] = v.elem[i];
	}
	void setSize(int size) { sz = size; }
	int capacity() { return sz; }
	int size() { return cp; }
	double getElem(int i) { return elem[i]; }

	void push_back(int item);

	double& operator[](int i) { return elem[i]; }
	Vector& operator=(const Vector& v) {
		if (&v == this) return *this;
		double* p = new double[v.sz];
		for (int i = 0; i != v.sz; ++i)
			p[i] = v.elem[i];
		delete[] elem;
		elem = p;
		sz = v.sz;
		return *this;
	}

	
};



// TODO: reference additional headers your program requires here
