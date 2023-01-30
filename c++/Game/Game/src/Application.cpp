#include <iostream>
//#include<chrono>
#include<algorithm>
#include <functional>
#include <vector>

class Base
{
public:
	Base() { std::cout << "Base.Constructor\n"; }
	virtual ~Base() { std::cout << "Base.Destructor\n"; }
};
class Destroy:public Base
{
public:
	Destroy() { m_array = new int[5]; std::cout << "Destory.Constructor\n"; }
	~Destroy() { delete[] m_array; std::cout << "Destory.Destructor\n"; }
private:
	int* m_array;
};
int main()
{
	Base* a = new Base();
	delete a;
	std::cout << "--------\n";
	Destroy* b = new Destroy();
	delete b;
	Base* c = new Destroy();
	delete c;
	Base* d = new Base();
	Destroy* e = dynamic_cast<Destroy*>(d);
	std::cin.get();
}
//struct Timer
//{
//	std::chrono::time_point<std::chrono::steady_clock> start, end;
//	std::chrono::duration<float> duration;
//	Timer()
//	{
//		start = std::chrono::high_resolution_clock::now();
//	}
//	~Timer()
//	{
//		end = std::chrono::high_resolution_clock::now();
//		duration = end - start;
//		float ms = duration.count()*1000.0f;
//		std::cout << ms << std::endl;
//	}
//};

//void data1()
//{
//	Timer time;
//	int* data = new int[500 * 500];
//	for (int x = 0; x < 500; x++)
//	{
//		for (int y = 0; y < 500; y++)
//			data[y + x * 500] = 2;
//	}
//}
//
//void data2()
//{
//	Timer time;
//	int** data = new int*[500];
//	for (int i = 0; i < 500; i++)
//		data[i] = new int[500];
//	for (int i = 0; i < 500; i++)
//	{
//		for (int j = 0; j < 500; j++)
//		{
//			data[i][j] = 2;
//		}
//	}
//}
//struct vector
//{
//	float x, y;
//};
//struct vector1
//{
//	union
//	{
//		struct
//		{
//			float x, y, z, w;
//		};
//		struct
//		{
//			vector a, b;
//		};
//	};
//};
//void print(vector& vv)
//{
//	std::cout << vv.x << "," << vv.y << std::endl;
//}
//struct Union
//{
//	union
//	{
//		int a;
//		int b;
//	};
//
//};
//int main()
//{
//	vector1 ff = { 1.0f,2.0f,3.0f,4.0f };
//	print(ff.a);
//	print(ff.b);
//	ff.z = 500.0f;
//	print(ff.a);
//	print(ff.b);
//	std::cin.get();
//	Union u;
//	u.a = 2.0f;
//	std::cout << u.a << "," << u.b << std::endl;
//
//	std::vector<int> data = { 1,2,4,5,6,3 };
//	std::sort(data.begin(), data.end(), [](int a, int b) {
//		if (a == 1)
//			return false;
//		if (b == 1)
//			return true;
//		return a > b;
//	});
//		for (int value : data)
//			std::cout << value << std::endl;
//	std::cin.get();
//}





//#include<iostream>
//#include<string>
//#include<thread>
//#include<chrono>
//
////static bool value = false;
////using namespace std::literals::chrono_literals;
//
////void Print()
////{
////	while (!value)
////	{
////		std::cout << "working..." << std::endl;
////		std::this_thread::sleep_for(1s);
////	}
////}
////void stop()
////{
////	std::cin.get();
////	value = true;
////}	using namespace std::literals::chrono_literals;
//struct Timer
//{
//
//	std::chrono::time_point<std::chrono::steady_clock> start, end;
//	std::chrono::duration<float> duration;
//	Timer()
//	{
//		start = std::chrono::high_resolution_clock::now();
//	}
//	~Timer()
//	{
//		end = std::chrono::high_resolution_clock::now();
//		duration = end - start;
//		float ms = duration.count() * 1000.0f;
//		std::cout << ms << "ms" ;
//	}
//};
//void Function()
//{
//	Timer timer;
//	for (int i = 0; i < 100; i++)
//	{
//		std::cout << "hello\n";
//	}
//}
//int main()
//{
//	Function();
	//std::thread worker(Print);
	//std::thread worker1(stop);
	////std::cin.get();
	////value = true;
	//
	//while (!value)
	//{
	//	std::cout << "finshed" << std::endl;
	//	std::this_thread::sleep_for(1s);
	//}
	//worker.join();
	////worker1.join();
	//using namespace std::literals::chrono_literals;

	//auto start = std::chrono::high_resolution_clock::now();
	//std::this_thread::sleep_for(1s);
	//auto end = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<float> durantion = end - start;
	//std::cout << durantion.count() << std::endl;

//	std::cin.get();
//
//
//}


//
//namespace apple
//{
//	void print(const std::string& name)
//	{
//		std::cout << name << std::endl;
//	}
//}
//
//namespace orange
//{
//	void print(const char* name)
//	{
//		std::string friut = name;
//		std::reverse(friut.begin(), friut.end());
//		std::cout << friut << std::endl;
//	}
//}
//using namespace apple;
//using namespace orange;
//
//int main()
//{
//	print("zbc");
//	apple::print("zbc");
//	std::cin.get();
//	
//}



//#include <iostream>
//#include "engine.h"
//
//
//int main()
//{
//	engine::PrintScreen();
//	std::cin.get();
//}
//
//#include <iostream>
//#include <array>
//
//template<int N>
//
//void PrintArray(std::array<int, N>& vv)
//{
//	for (int i = 0; i < vv.size(); i++)
//		std::cout << vv[i] << std::endl;
//}
//
//int main()
//{
//	std::array<int, 5> kj;
//	kj[0] = 1;
//	kj[2] = 3;
//	PrintArray(kj);
//	std::cin.get();
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<functional>
//void PrintHelloWorld(int value)
//{
//	std::cout << "Value is : " << value << std::endl;
//}

//void GetValue(const std::vector<int>& values, void(*fuc)(int))
//{
//	for (int value : values)
//		fuc(value);
//}
//
//int main()
//{
//	std::vector<int> ff = { 1,2,8,4,5,6,7 };
//	auto f = std::find_if(ff.begin(), ff.end(), [](int value) {return value > 3; });
//	std::cout << *f << std::endl;
//
//	GetValue(ff, [](int value)
//	{
//		std::cout << "the value is : " << value << std::endl;
//	
//	});
//	std::cin.get();
//}
//
//void PrintHello(int value)
//{
//	std::cout << "hello world" <<value<< std::endl;
//}
//int main()
//{
//	typedef void(*fuction)(int);
//	fuction ff = PrintHello;
//	ff(1);
//	ff(5);
//	std::cin.get();
//}
//
//#define MAIN int main()\
//{\
//std::cout << "fff" << std::endl;\
//std::cin.get();\
//}
//
//MAIN
//
//template<typename T, int N>
//
//class Array
//{
//private:
//	T m_Array[N];
//public:
//	int function() const
//	{
//		return N;
//	}
//};
//#if 0
//#define PR_DEBUG 0
//
//#if PR_DEBUG == 1
//#define Log(x) std::cout << x<<std::endl
//#elif defined(PR_RELEASE)
//#define Log(x)
//#endif
//
//#endif
//int main()
//{
//	Array<int,6> fff;
//	Log("zbv");
//	Log(5);
//
//	std::cin.get();
//}