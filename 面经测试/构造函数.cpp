//#include "head.h"
//
//class Person {
//public:
//	Person() {//�޲ι���
//		cout << "no param constructor!" << endl;
//		mAge = 0;
//	}
//
//	Person(int age) {//�вι��캯��
//		cout << "1 param constructor!" << endl;
//		mAge = age;
//	}
//
//	Person(const Person& person) {//�������캯��(���ƹ��캯��) ʹ����һ�������ʼ��������
//		cout << "copy constructor!" << endl;
//		mAge = person.mAge;
//	}
//private:
//	int mAge;
//};
//
//void test() {	
//	Person person1;//�����޲ι��캯��
//	Person person2();//��������޲ι��캯����ʵ�ʵ����вι���,person2������
//	
//	Person person3(100);//�����вι���
//	Person person4(person1);//���ÿ������캯��
//	
//	//ע��: ʹ�����������ʼ���жϵ�����һ�����캯���� Ҫ����������Ĳ�������
//	Person(200); //��������(��ʾ�����вι��캯������û�ж���)
//	Person person5 = Person(300);//�����вι��캯��
//	Person person6(Person(400));//�����вι��캯��
//		
//	Person person7 = 100; //�����вι��캯��
//	Person person8 = person7; //���ÿ�������
//}
//int main()
//{
//	test();
//	return 0;;
//}
