#pragma once

#include <iostream>
#include <vector>

using namespace std;

//Problem:
//	   ����һ����¡������
//	   ��һ��ʧ���ʣ�������ɱ��һǧ�����ɷŹ�һ����һ������ʧ���ʵĻ��ơ�
//	   ��ṹ������ʾ��
//		   public class Test
//	   {
//		   public static void main��string[]args��
//		   {
//			   long[]arr = new long[1eee]��//s��eep 
//			   int index = 3eeee��
//			   int intIndex = index / 32��
//			   int bitIndex = index % 32
//			   arr[intIndex] = ��arr[intIndex]I��1 << bitIndex������
//		   }
//	   }
//
//Solution��
//	ʹ��K��hash_map,����ÿ��hash_mapʹ�ò�ͬ�Ĵ洢��ʽ
//	ÿ��hash_map��ͬһ������ռ䣬���磺int a[1000], ���߳�һЩlong int b[100000];
//	Ȼ�������ֵvalue���в�����
//	value / size;    //�ҵ���ֵ����ŵĵ�ַ��a[index]
//	value%size;   //��a[index]�е�modֵ�Ķ���������λ�ý��С�Ĩ�ڡ���0������1������
//	ʹ�ò�ͬ��hash���������ݴ��벻ͬ��K��hash����
//	Ȼ���ѯʱ��ͬ������ÿһ���ռ��Ƿ�Ĩ�ڡ�ֻҪ����һ��������"Ĩ��"�Ŀռ�, ���ʾ��ֵ�����ڱ��С�
//
//	

//������ʹ��һ����������С�Ͳ�¡������

#define N 32

class Blong
{
public:
	void Add(int a);
	void Find(int a);

private:
	int data[N] = {0};
};

void Blong::Add(int a)
{
	int index = a % N;
	int pot = a % N;
	this->data[index] = data[index] | (1 << pot);//��λ
}

void Blong::Find(int a)
{
	int index = a % N;
	int pot = a % N;
	int i = 1;
	i = i << pot;
	if (this->data[index] == i)
		cout << "the num is already existence!" << endl;
	else
		cout << "the num is not existence!" << endl;

}


void Test()
{
	Blong B;
	B.Add(125);
	B.Add(15413);
	B.Add(12345);

	B.Find(123);
	B.Find(1234);
	B.Find(12345);

}
