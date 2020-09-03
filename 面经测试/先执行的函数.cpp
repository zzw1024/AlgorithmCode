//#include "head.h"
//
//int first() {
//	cout << "first\n";
//	return 0;
//}
//
//int b = first();
//
//int main()
//{
//	cout << "i am main()\n";
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//template <typename T>
//
//class SmartPtr
//
//{
//
//private:
//
//	T *ptr;    //�ײ���ʵ��ָ��
//
//	int *use_count;//���浱ǰ���󱻶���ָ�����ü���
//
//public:
//
//	SmartPtr(T *p); //SmartPtr<int>p(new int(2));
//
//	SmartPtr(const SmartPtr<T>&orig);//SmartPtr<int>q(p);
//
//	SmartPtr<T>&operator=(const SmartPtr<T> &rhs);//q=p
//
//	~SmartPtr();
//
//	T operator*();  //Ϊ���ܰ�����ָ�뵱����ָͨ�������������ò���
//
//	T*operator->();  //����ȡ��Ա����
//
//	T* operator+(int i);//����ָ���һ������
//
//	T* operator-(SmartPtr<T>&t1, SmartPtr<T>&t2);//��������ָ�����
//
//	void getcount() { return *use_count }
//}; 
//
//template <typename T> int SmartPtr<T>:: operator-(SmartPtr<T> &t1, SmartPtr<T> &t2) 
//{ 
//	return t1.ptr - t2.ptr; 
//} 
//template <typename T> SmartPtr<T>::SmartPtr(T *p) {
//	ptr = p; try { use_count = new int(1); }
//	catch (...) {
//		delete ptr;    //����ʧ���ͷ���ʵָ������ü������ڴ�
//
//		ptr = nullptr; delete use_count; use_count = nullptr;
//	}
//}
//
//template <typename T>
//SmartPtr<T>::SmartPtr(const SmartPtr<T> &orig) //���ƹ��캯��
//
//{
//
//	use_count = orig.use_count;//���ü���������һ���ڴ棬���е�SmarPtr��������ü�����ָ������
//
//	this->ptr = orig.ptr;
//
//	++(*use_count);//��ǰ��������ü�����1
//
//
//}
//template <typename T> SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs) {
//	//����=�����������SmartPtr<int>p,q; p=q;�������У����ȸ�qָ��Ķ�������ü�����1����Ϊp����ָ����q��ָ�Ķ�������p��Ҫ�ȸ�ԭ���Ķ�������ü�����1�������һ��Ϊ0�����ͷŵ�pԭ��ָ����ڴ棬Ȼ��qָ��Ķ�������ü�����1��ֵ��p
//
//	++*(rhs.use_count);
//	if ((--*(use_count)) == 0) {
//		delete ptr; ptr = nullptr; delete use_count; use_count = nullptr;
//	}
//	ptr = rhs.ptr;
//	*use_count = *(rhs.use_count);
//	return *this;
//}
//
//template <typename T> SmartPtr<T>::~SmartPtr() {
//	getcount();
//	if (--(*use_count) == 0)  //SmartPtr�Ķ���������������ڽ�����ʱ����������������������������м�⵱ǰ��������ü����ǲ���ֻ�����ڽ����������ڵ����SmartPtr���ã�����ǣ����ͷŵ���������ǣ��ͻ���������SmartPtr���õ�ǰ���󣬾͵ȴ�������SmartPtr���������������ڽ�����ʱ��������������ͷŵ�
//	{
//		getcount();
//		delete ptr;
//		ptr = nullptr;
//		delete use_count;
//		use_count = nullptr;
//	}
//}
//
//template <typename T>
//T SmartPtr<T>::operator*()
//{
//	return *ptr;
//}
//
//template <typename T>
//T*  SmartPtr<T>::operator->()
//{
//	return ptr;
//}
//
//template <typename T>
//T* SmartPtr<T>::operator+(int i)
//{
//	T *temp = ptr + i;
//	return temp;
//}
//
