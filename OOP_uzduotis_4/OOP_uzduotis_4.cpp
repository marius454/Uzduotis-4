// OOP_uzduotis_4.cpp : Defines the entry point for the console application.
//

#include "Vector.h"
#include "stdafx.h"
using namespace std::chrono;

int main()
{
	//Mano Vector
	size_t sk = 10000;
	std::cout << "Mano Vector:" << std::endl;
	for (size_t i = 0; i < 5; ++i)
	{
		double vid = 0;
		for (size_t j = 0; j < 5; ++j)
		{
			auto start = high_resolution_clock::now();
			Vector<int> v1;
			for (size_t k = 0; k < sk; ++k)
			{
				v1.push_back(k);
			}
			auto end = high_resolution_clock::now();
			auto dur = duration<double>(end - start).count();
			vid = vid + dur;
		}
		vid = vid / 5;
		std::cout << std::setw(12) << std::left << sk << " vidutiniskai uztruko: " << vid << "s\n";
		sk *= 10;
	}
	
	//std::vector
	size_t sk1 = 10000;
	std::cout << "std::vector" << std::endl;
	for (size_t i = 0; i < 5; ++i)
	{
		double vid = 0;
		for (size_t j = 0; j < 5; ++j)
		{
			auto start = high_resolution_clock::now();
			std::vector<int> v2;
			for (size_t k = 0; k < sk1; ++k)
			{
				v2.push_back(k);
			}
			auto end = high_resolution_clock::now();
			auto dur = duration<double>(end - start).count();
			vid = vid + dur;
		}
		vid = vid / 5;
		std::cout << std::setw(12) << std::left << sk1 << " vidutiniskai uztruko: " << vid << "s\n";
		sk1 *= 10;
	}

	return 0;
}

