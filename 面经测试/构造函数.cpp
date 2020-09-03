//#include "head.h"
//
//class Person {
//public:
//	Person() {//无参构造
//		cout << "no param constructor!" << endl;
//		mAge = 0;
//	}
//
//	Person(int age) {//有参构造函数
//		cout << "1 param constructor!" << endl;
//		mAge = age;
//	}
//
//	Person(const Person& person) {//拷贝构造函数(复制构造函数) 使用另一个对象初始化本对象
//		cout << "copy constructor!" << endl;
//		mAge = person.mAge;
//	}
//private:
//	int mAge;
//};
//
//void test() {	
//	Person person1;//调用无参构造函数
//	Person person2();//错误调用无参构造函数，实际调用有参构造,person2不存在
//	
//	Person person3(100);//调用有参构造
//	Person person4(person1);//调用拷贝构造函数
//	
//	//注意: 使用匿名对象初始化判断调用哪一个构造函数， 要看匿名对象的参数类型
//	Person(200); //匿名对象(显示调用有参构造函数，但没有对象)
//	Person person5 = Person(300);//调用有参构造函数
//	Person person6(Person(400));//调用有参构造函数
//		
//	Person person7 = 100; //调用有参构造函数
//	Person person8 = person7; //调用拷贝构造
//}
//int main()
//{
//	test();
//	return 0;;
//}
