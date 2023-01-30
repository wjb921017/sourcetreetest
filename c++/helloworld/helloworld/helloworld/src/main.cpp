#include <iostream>
#include <string>
#include <vector>
#include "GLFW\glfw3.h"
struct Vetcte
{
	float x, y, z;
	Vetcte(float x, float y, float z)
		:x(x),y(y),z(z)
	{

	}
	Vetcte(const Vetcte& vc)
		:x(vc.x), y(vc.y), z(vc.z)
	{
		std::cout << "copy" << std::endl;
	}
};

std::ostream& operator<< (std::ostream& stream, const Vetcte& ve)
{
	stream << ve.x << "," << ve.y << "," << ve.z ;
	return stream;
}
void Function(const std::vector<Vetcte>& fh)
{

}
int main()
{
	int a = glfwInit();
	std::cout << a << std::endl;
	std::vector<Vetcte> vecte;
	vecte.reserve(3);
	Function(vecte);
	vecte.emplace_back(1,2,3);
	vecte.emplace_back(4, 5, 6);
	vecte.emplace_back(7,8,9);
	//vecte.erase(vecte.begin() + 1);
	//for (Vetcte v : vecte)
	//	std::cout << v << std::endl;
	std::cin.get();
}




//#include <iostream>
//
//
//class Entity
//{
//private:
//	int x;
//public:
//	Entity()
//	{
//		std::cout << "create class" << std::endl;
//
//	}
//	~Entity()
//	{
//		std::cout << "destroy class" << std::endl;
//	}
//};
//class ScopedPtr
//{
//private:
//	Entity* m_Ptr;
//public:
//	ScopedPtr(Entity* ptr)
//		:m_Ptr(ptr)
//	{
//
//	}
//	~ScopedPtr()
//	{
//		delete m_Ptr;
//	}
//};
//
//int main()
//{
//	{
//		//Entity e;
//		//Entity* test = new Entity();
//		//ScopedPtr test = new Entity();
//		//std::unique_ptr<Entity> entity = std::make_unique<Entity>();
//		std::shared_ptr<Entity> shardedEntity;
//		{
//			std::shared_ptr<Entity> e = std::make_shared<Entity>();
//			shardedEntity = e;
//		}
//	}
//	std::cin.get();
//}





//#include <iostream>
//#include <string>
//
//
//
//class String
//{
//private:
//	char* m_Buffer;
//	unsigned int m_Size;
//public:
//	String(const char* string)
//	{
//		m_Size = strlen(string);
//		m_Buffer = new char[m_Size+1];
//		memcpy(m_Buffer, string, m_Size);
//		m_Buffer[m_Size] = 0;
//	}
//	String(const String& other): m_Size(other.m_Size)
//	{
//		std::cout << "copy string" << std::endl;
//		m_Buffer = new char[m_Size + 1];
//		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
//		m_Buffer[m_Size] = 0;
//	}
//
//	char& operator[](unsigned int index)
//	{
//		return m_Buffer[index];
//	}
//	friend std::ostream& operator<<(std::ostream& stream, const String& string);
//	~String()
//	{
//		delete[] m_Buffer;
//	}
//};
//
//std::ostream& operator<<(std::ostream& stream, const String& string)
//{
//	stream << string.m_Buffer;
//	return stream;
//}
//
//void PrintString(const String& string)
//{
//	std::cout << string << std::endl;
//
//}
//
//int main()
//{
//	String test("test");
//	String test1 = test;
//	test1[2] = 'r';
//	PrintString(test);
//	PrintString(test1);
//	//std::cout << test1 << std::endl;
//	//std::cout << test << std::endl;
//	std::cin.get();
//
//}

























//#include<iostream>
//
//
//class Singleton
//{
//
//public:
//	static Singleton& Get()
//	{
//		static Singleton s_Instance;
//		return s_Instance;
//	}
//	void Hello(){}
//};
//
//
//
//void log(const char* message);
//void increans(int& value)
//{
//	value++;
//}
// int kuai = 4;
//int main()
//{
//	Singleton::Get().Hello();
//	//std::cout << kuai << std::endl;
//	//int a = 8;
//	//int* var = &a;
//	//*var = 10;
//	//char* ptr = new char[8];
//	//memset(ptr, 0, 8);
//	//char** ptr1 = &ptr;
//	//increans(a);
//	//std::cout << a << std::endl;
//	//log("hello world!");
//	////for (int i = 0; i < 5; i++)
//	////{
//	////	if (i % 3== 0)
//	////		continue;
//	////	log("zbc");
//	////}
//
//	std::cin.get();
//
//}