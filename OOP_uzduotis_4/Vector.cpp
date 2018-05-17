// stdafx.cpp : source file that includes just the standard includes
// OOP_uzduotis_4.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"


void Vector::push_back(int item) {
	if (sz == 0)
	{
		++sz;
		elem = (double*)realloc(elem, sz * sizeof(double));
		++cp;
		elem[cp - 1] = item;
	}
	else if (sz == cp)
	{
		sz *= 2;
		elem = (double*)realloc(elem, sz * sizeof(double));
		++cp;
		elem[cp - 1] = item;
	}
	else
	{
		++cp;
		elem[cp - 1] = item;
	}
}
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
