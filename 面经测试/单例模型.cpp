//#include "head.h"
//
////���Ƽ���д��
//class Singleton
//{
//private://���й��캯������˽���У�ʹ���޷�����
//	Singleton() { cout << "Singleton Construction" << endl; };
//	~Singleton() { cout << "Singleton Delete" << endl; };
//
//	Singleton(const Singleton &s);
//	Singleton& operator=(const Singleton &s);
//
//public:	
//	static Singleton& GetInstance()//����ӿ�
//	{ 
//		static Singleton instance;//ֻ��������ʵ��
//		return instance;
//	};
//	int val;
//};
//
//int main()
//{
//	Singleton::GetInstance().val = 1;//ֻ��ʹ����һ������
//	return 0;
//}
//
////������Թ�������д��
//class Singleton
//{
//private://���й��캯������˽���У�ʹ���޷�����
//	Singleton() { cout << "Singleton Construction" << endl; };
//	~Singleton() { cout << "Singleton Delete" << endl; };
//
//	Singleton(const Singleton &s);
//	Singleton& operator=(const Singleton &s);
//	static Singleton* instance;//ֻ�������ʼ��
//public:
//	static Singleton* GetInstance();//����ӿڣ�����ʵ��
//	int val;
//};
//Singleton* Singleton::instance = nullptr;//�����ʼ��
//Singleton* Singleton::GetInstance()
//{
//	if (instance == nullptr)//��һ������Ҫ
//		instance = new Singleton();
//	return instance;
//}
//
//int main()
//{
//	Singleton* p1 = Singleton::GetInstance();//ֻ�ṹ��һ��,�Ҳ���ʹ��delete
//	Singleton* p2 = Singleton::GetInstance();//p1��p2��ָ��ͬһ����ַ
//	p1->val = 1;
//	p2->val = 2;//p2����p1
//	cout << p1->val << endl;//2
//	cout << p2->val << endl;//2
//	return 0;
//}
