// OOP_uzduotis_4.cpp : Defines the entry point for the console application.
//

#include "Vector.h"
#include "stdafx.h"
using namespace std::chrono;

int main()
{
	Vector<int> v1 { 1,2,3 };
	//Foo test(2,2);
	/*test.x = 2;
	test.n = 12;*/
	Vector<int> v2(9, 4);
	v1.emplace(v1.begin(), 5);
	v1.insert(v1.begin(), v2.begin(),v2.end());
	
	for (int i = 0; i != v1.size(); ++i)
	{
		std::cout << v1[i] << " ";
	}
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

	//auto start = high_resolution_clock::now();
	//Vector<int> v1;

	//for (size_t i = 0; i<10000; ++i)
	//{
	//	v1.push_back(i);
	//}
	//for (size_t i = 0; i < 10000; i += 1000)
	//{
	//	std::cout << v1[i] << std::endl;
	//}
	//v1.shrink_to_fit();
	//std::cout << v1.capacity() << std::endl;
	//std::cout << "Mano Vector uztruko:";
	//auto end = high_resolution_clock::now();
	//std::cout << duration<double>(end - start).count() << "s\n";

	////std::vector
	//start = high_resolution_clock::now();
	//std::vector<int> v2;
	//for (size_t i = 0; i<10000; ++i)
	//{
	//	v2.push_back(i);
	//}
	//for (size_t i = 0; i < 10000; i += 1000)
	//{
	//	std::cout << v2[i] << std::endl;
	//}
	//v2.shrink_to_fit();
	//std::cout << v2.capacity() << std::endl;
	//std::cout << "std::vector uztruko:";
	//end = high_resolution_clock::now();
	//std::cout << duration<double>(end - start).count() << "s\n";

	return 0;
}

