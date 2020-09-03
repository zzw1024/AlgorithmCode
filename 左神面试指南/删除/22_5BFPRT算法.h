#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Problem:
//	�ҵ�δ���������е�k�����
//	������1-500�����������У�
//	�ҵ���15�����
//
//Solution��
//	ʹ��BFPRT�㷨�����п�������
int BFPRT(vector<int>& v, int left, int right, const int k);

//�������򣬷�����λ�����½Ǳ�
int InsertSort(vector<int>& v, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
			int temp = v[i];
			int j = i - 1;
			while (j >= left && v[j] > temp)
			{
				v[j + 1] = v[j];
				--j;
			}
			v[j + 1] = temp;
	}
	return left + (right - left) >> 1;//������λ��
}

//������λ������λ�����½Ǳ�
int GetMidIndex(vector<int>& v, int left, int right)
{
	if (right - left < 5)
		return InsertSort(v, left, right);//���һ���������
	int subRight = left - 1;
	for (int i = left; i + 4 <= right; i + 5)//�����������
	{
		int index = InsertSort(v, i, i + 4);
		swap(v[++subRight], v[index]);//����λ���������
	}
	return BFPRT(v, left, subRight, (subRight - left + 1) >> 1 + 1);
}

//������λ������λ�����½Ǳ���л��֣����ر߽����±�
int Partition(vector<int>&v, int left, int right, int midIndex)
{
	swap(v[midIndex], v[right]);//����λ���ĵ���λ��������ĩβ

	int divideIndex = left;//���ٻ��ַֽ���
	for (int i = left; i < right; ++i)//��λ������λ����v[right]��
		if (v[i] < v[right])
			swap(v[divideIndex++], v[i]);//����λ������λ��С�ķ������

	swap(v[midIndex], v[right]);//������
	return divideIndex;
}


int BFPRT(vector<int>& v, int left, int right, const int k )
{
	int midIndex = GetMidIndex(v, left, right);//�õ���λ������λ�����±�
	int divideIndex = Partition(v, left, right, midIndex);//���л��֣����ػ��ֱ߽�
	int num = divideIndex - left + 1;
	if (num == k)
		return divideIndex;
	else if (num > k)
		return BFPRT(v, left, divideIndex - 1, k);
	else
		return BFPRT(v, divideIndex + 1, right, k - num);
}

void Test()
{
	vector<int>v;
	v = { 1,1,2,3,1,5,-1,7,8,-10 };

	int k = 5;
	cout << "ԭ����:" << endl;
	for (auto a : v)
		cout << a << "  ";
	cout << endl;

	cout << "��" << k << "СֵΪ��" << v[BFPRT(v, 0, v.size() - 1, k)] << endl;
	
	cout << "�仯�������:" << endl;
	for (auto a : v)
		cout << a << "  ";
	cout << endl;


}





