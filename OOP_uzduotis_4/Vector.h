#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <limits>
#include <memory>
#include <iomanip>

template<typename T>
class Vector
{
private:
	std::allocator<T> alloc;
	size_t cp;
	size_t sz;
	T* elem;
public:

	typedef templ* iterator;
	typedef const templ* const_iterator;

	//Constructors
	Vector() : sz(0), cp(0), elem(new T[cp]) {}
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
	Vector(std::initializer_list<T> list) : elem(new T[list.size()]), sz(list.size()), cp(list.size())
	{
		std::move(list.begin(), list.end(), elem);
	}
	//Destructor
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
	std::allocator<T> get_allocator() { return alloc; }


	//push_back apibrezimas
	void push_back(T item);
	template<class... Args>
	void emplace_back(Args&&... item);


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
	Vector& operator=(std::initializer_list<T> list) {
		cp = list.size();
		sz = list.size();

		elem = new T[cp];
		//elem = (T*)realloc(elem, cp * sizeof(T));

		std::copy(list.begin(), list.end(), elem);
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

	//clear
	void clear() {
		elem = new T[cp];
	}

	//insert
	T* insert(T* pos, T&& val);
	T* insert(T* pos, T* start, T* end);
	T* insert(T* pos, size_t count, T val);
	T* insert(T* pos, const T& val);
	template<class... Args>
	T* emplace(T* pos, Args&&... args);

	//erase ir pop_back
	T* erase(T* pos);
	T* erase(T* start, T* end);
	void pop_back() {
		--sz;
		T* temp = new T[sz];
		temp = std::move(elem);
		elem = std::move(temp);
	}

	//swap
	void swap(Vector& v);

	//operators
	bool operator==(Vector& v) {
		size_t test = 0;
		if (sz != v.sz) return false;
		else for (size_t i = 0; i < sz; ++i)
		{
			if (elem[i] = v.elem[i]) ++test;
		}
		if (test == sz) return true;
	}
	bool operator>(Vector& v) {
		size_t size;
		if (sz > v.sz) size = v.sz;
		else size = sz;
		size_t i = 0;
		if (sz != 0 && v.sz == 0) return true;
		if (sz == 0 && v.sz == 0) return false;
		while (elem[i] == v.elem[i])
		{
			++i;
			if (i == size) {
				if (sz > v.sz) return true;
				else if (sz <= v.sz) return false;
				break;
			}
		}
		if (elem[i] > v.elem[i]) return true;
		else return false;
	}
	bool operator<(Vector& v) {
		size_t size;
		if (sz < v.sz) size = v.sz;
		else size = sz;
		size_t i = 0;
		if (sz == 0 && v.sz != 0) return true;
		if (sz == 0 && v.sz == 0) return false;
		while (elem[i] == v.elem[i])
		{
			++i;
			if (i == size) {
				if (sz >= v.sz) return false;
				else if (sz < v.sz) return true;
				break;
			}
		}
		if (elem[i] > v.elem[i]) return false;
		else return true;
	}
	bool operator!=(Vector& v) { return !operator==(v); }
	bool operator>=(Vector& v) { return !operator<(v); }
	bool operator<=(Vector& v) { return !operator>(v); }
	T& operator[](size_t i) { return elem[i]; }
};

//push_back ir emplace_back realizacijos
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
template<typename T>
template<class... Args>
void Vector<T>::emplace_back(Args&&... args) {
	if (sz == 0)
	{
		++cp;
		elem = (T*)realloc(elem, cp * sizeof(T));
		++sz;
		alloc.construct(&elem[sz - 1], args...);
	}
	else if (sz == cp)
	{
		cp *= 2;
		++cp;
		elem = (T*)realloc(elem, cp * sizeof(T));
		++sz;
		alloc.construct(&elem[sz - 1], args...);
	}
	else
	{
		++sz;
		alloc.construct(&elem[sz - 1], args...);
	}
}


//Insert realizacijos
template <typename T>
T* Vector<T>::insert(T* pos, T&& val)
{
	size_t x = std::distance(&elem[0], pos);
	if (sz == cp) {
		cp = cp * 2;
		elem = (T*)realloc(elem, cp * sizeof(T));
	}
	for (size_t i = sz - 1; i >= x; --i) {
		elem[i + 1] = elem[i];
		if (i == 0) break;
	}
	elem[x] = std::move(val);
	++sz;
	return pos;
}

template <typename T>
T* Vector<T>::insert(T* pos, const T& val)
{
	size_t x = std::distance(&elem[0], pos);
	if (sz == cp) {
		cp = cp * 2;
		elem = (T*)realloc(elem, cp * sizeof(T));
	}
	for (size_t i = sz - 1 ; i >= x; --i) {
		elem[i + 1] = elem[i];
		if (i == 0) break;
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
	for (size_t i = sz-1; i >= x; --i) {
		elem[i + std::distance(start, end)] = elem[i];
		if (i == 0) break;
	}
	size_t j = 0;
	for (T* i = start; i != end; ++i) {
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
	while (sz == cp || cp <= sz + count + 1) {
		cp = cp * 2;
		elem = (T*)realloc(elem, cp * sizeof(T));
	}
	for (size_t i = sz-1; i >= x; --i) {
		elem[i + count + 1] = elem[i];
		if (i == 0) break;
	}
	size_t j = 0;
	for (T* i = pos; i != pos + count + 1; ++i) {
		elem[x + j] = val;
		++j;
		++sz;
	}
	return pos;
}

//emplace
template<typename T>
template<class... Args>
T* Vector<T>::emplace(T* pos, Args&&... args)
{
	size_t x = std::distance(&elem[0], pos);
	if (sz == cp) {
		cp = cp * 2;
		elem = (T*)realloc(elem, cp * sizeof(T));
	}
	for (size_t i = sz-1; i >= x; --i) {
		elem[i + 1] = elem[i];
		if (i == 0) break;
	}
	alloc.construct(&elem[x], args...);
	++sz;
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
	size_t x = std::distance(start, end);
	size_t i = 0;
	for (T* it = &elem[0]; it != start; ++it) {
		temp[i] = std::move(*it);
		i++;
	}
	for (T* j = end - 1; j != &elem[sz]; ++j) {
		temp[i] = std::move(*j);
		i++;
	}
	delete[] elem;
	elem = std::move(temp);
	sz -= x;
	return end;
}

//swap realizacija
template<typename T>
void Vector<T>::swap(Vector& v)
{
	if (v.cp > cp)
	{
		cp = v.cp;
		elem = (T*)realloc(elem, cp * sizeof(T));
	}
	size_t tempsz = v.sz;
	v.sz = sz;
	sz = tempsz;

	T* temp = new T[cp];
	temp = v.elem;
	v.elem = elem;
	elem = temp;
}

