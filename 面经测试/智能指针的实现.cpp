//#include "head.h"
//class Object;
//class SmartPointer;
//
//class Counter
//{
//	friend class SmartPointer;
//public:
//	Counter() 
//	{
//		ptr = NULL;
//		cnt = 0;
//	}
//	//Ö¸Õë¿½±´
//	Counter(Object* p)
//	{
//		ptr = p;
//		cnt = 1;
//	}
//	~Counter(){
//		delete ptr;
//	}
//
//private:
//	Object* ptr;
//	int cnt;
//};
//
//
//class SmartPointer
//{
//public:
//	SmartPointer(Object* p)
//	{
//		ptr_counter = new Counter(p);
//	}
//	SmartPointer(const SmartPointer &sp)
//	{
//		ptr_counter = sp.ptr_counter;
//		++ptr_counter->cnt;
//		++sp.ptr_counter->cnt;
//		--ptr_counter->cnt;
//		if (ptr_counter->cnt == 0)
//			delete ptr_counter;
//
//		ptr_counter = sp.ptr_counter;
//		--ptr_counter->cnt;
//	}
//
//	SmartPointer& operator=(const SmartPointer)
//	{
//
//	}
//	~SmartPointer()
//	{
//		if (ptr_counter->cnt == 0)
//			delete ptr_counter;
//	}
//
//private:
//	Counter* ptr_counter;
//
//};
//
//int main()
//{
//
//}