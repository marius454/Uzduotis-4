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

	void assign(size_t s, T val) {
		cp = s;
		sz = s;
		elem = new T[s];
		std::fill_n(elem, s, val);
	}
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
	T* data() { return &elem[0]; }
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

	void clear() {
		elem = new T[cp];
	}

	//insert
	T* insert(T* pos, T val);
	T* insert(T* pos, T* start, T* end);
	T* insert(T* pos, size_t count, T val);

	//erase ir pop_back
	T* erase(T* pos);
	T* erase(T* start, T* end);
	void pop_back(){
		--sz;
		T* temp = new T[sz];
		temp = std::move(elem);
		elem = std::move(temp);
	}
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


//Insert realizacijos
template <typename T>

T* Vector<T>::insert(T* pos, T val)
{
	size_t x = std::distance(&elem[0], pos);
	if (sz == cp) {
		cp = cp * 2;
		elem = (T*)realloc(elem, cp * sizeof(T));
	}
	for (size_t i = sz; i > x; --i) {
		elem[i + 1] = elem[i];
	}
	elem[x] = val;
	++sz;
	return pos;
}

template <typename T>
T* Vector<T>::insert(T* pos, T* start, T* end)
{
	size_t x = std::distance(&elem[0], pos);
	while (sz == cp || cp <= sz + std::distance(start, end)) {
		cp = cp * 2;
		elem = (T*)realloc(elem, cp * sizeof(T));
	}
	for (size_t i = sz; i >= x; --i) {
		elem[i + std::distance(start, end)] = elem[i];

	}
	size_t j = 0;
	for (T* i = start; i != end; ++i) {
		//elem[i + std::distance(start, end)] = elem[i];
		elem[x + j] = std::move(*i);
		++j;
		++sz;
	}
	return pos;
}

template<typename T>
T* Vector<T>::insert(T* pos, size_t count, T val)
{
	size_t x = std::distance(&elem[0], pos);
	while (sz == cp || cp <= sz + count+1) {
		cp = cp * 2;
		elem = (T*)realloc(elem, cp * sizeof(T));
	}
	for (size_t i = sz; i >= x; --i) {
		elem[i + count+1] = elem[i];

	}
	size_t j = 0;
	for (T* i = pos; i != pos+count+1; ++i) {
		elem[x + j] = val;
		++j;
		++sz;
	}
	return pos;
}


//erase realizacijos
template<typename T>

T* Vector<T>::erase(T* pos)
{
	T* temp = new T[cp];
	size_t i = 0;
	for (T* it = &elem[0]; it != pos; ++it) {
		temp[i] = std::move(*it);
		i++;
	}
	for (auto j = pos; j != &elem[sz]; ++j) {
		temp[i] = std::move(*(j + 1));
		i++;
	}
	delete[] elem;
	elem = std::move(temp);
	sz--;
	return pos;
}
template<typename T>
T* Vector<T>::erase(T* start, T* end)
{
	T* temp = new T[cp];
	size_t x = std::distance(start,end);
	size_t i = 0;
	for (T* it = &elem[0]; it != start; ++it) {
		temp[i] = std::move(*it);
		i++;
	}
	for (T* j = end-1; j != &elem[sz]; ++j) {
		temp[i] = std::move(*j);
		i++;
	}
	delete[] elem;
	elem = std::move(temp);
	sz -= x;
	return end;
}

//template<typename T>
