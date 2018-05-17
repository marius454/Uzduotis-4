// OOP_uzduotis_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std::chrono;

int main()
{
	/*Vector v1(10, 5);
	Vector v2;
	v2 = v1;
	for (int i = 0; i != v2.size(); ++i)
		{
			std::cout << v2.getElem(i) << std::endl;
		}*/

	//Mano Vector
	auto start = high_resolution_clock::now();
	Vector<double> v1;
	for (int i = 0; i<10000000; ++i)
	{
		v1.push_back(i);
	}
	for (int i = 0; i < 10000000; i += 1000000)
	{
		std::cout << v1.getElem(i) << std::endl;
	}
	std::cout << v1.capacity() << std::endl;
	std::cout << "Mano Vector uztruko:";
	auto end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";


	//std::vector
	start = high_resolution_clock::now();
	std::vector<double> v2;
	for (int i = 0; i<10000000; ++i)
	{
		v2.push_back(i);
	}
	for (int i = 0; i < 10000000; i += 1000000)
	{
		std::cout << v2.at(i) << std::endl;
	}
	std::cout << v2.capacity() << std::endl;
	std::cout << "std::vector uztruko:";
	end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";

	return 0;
}

