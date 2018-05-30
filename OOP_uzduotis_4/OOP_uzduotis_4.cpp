// OOP_uzduotis_4.cpp : Defines the entry point for the console application.
//

#include "Vector.h"
#include "stdafx.h"
using namespace std::chrono;

int main()
{
	/*Vector<int> v1 { 1,2,3 };
	Vector<int> v2(9, 4);
	v1.emplace(v1.begin(), 5);
	v1.insert(v1.begin(), v2.begin(),v2.end());
	
	for (int i = 0; i != v1.size(); ++i)
	{
		std::cout << v1[i] << " ";
	}*/
	//std::cout << std::endl;
	//v1.swap(v2);
	//v1.insert(v1.begin() + 2, 10, 6);
	//for (int i = 0; i != v1.size(); ++i)
	//{
	//	std::cout << v1[i] << " ";
	//}
	//std::cout << std::endl;
	//v1.erase(v1.begin() + 2, v1.end() - 2);
	//for (int i = 0; i != v1.size(); ++i)
	//{
	//	std::cout << v1[i] << " ";
	//}

	//std::cout << std::endl;
	//std::cout << v1.capacity() << std::endl;
	//std::cout << v1.size() << std::endl;

	//Vector<int> v{ 2,2,3 };
	//Vector<int> vv{ 1,2,3 };
	///*v.assign(10, 5);
	//vv.assign(1, 4);*/
	//if (v <= vv)
	//{
	//	std::cout << "maziau" << std::endl;
	//}
	//if (v >= vv)
	//{
	//	std::cout << "daugiau" << std::endl;
	//}


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
			/*for (size_t i = 0; i < 10000; i += 1000)
			{
				std::cout << v1[i] << std::endl;
			}*/
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
			/*for (size_t i = 0; i < 10000; i += 1000)
			{
			std::cout << v1[i] << std::endl;
			}*/
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

