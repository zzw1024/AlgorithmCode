#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

//����Ŀ��
//	����һ������arr����һ������aim������arr�У��ۼӺ͵���num���������ĳ���
//	���ӣ�
//	arr = { 7,3,2,1,1,7,7,7 } aim = 7
//	�����кܶ���������ۼӺ͵���7�����������������{ 3,2,1,1 }�����Է����䳤��4
//
//�����⡿
//	ʹ��map,  �������һ������ʼ�ۼ�,  ��¼�ۼӺ͵�ĳ��ֵ�ĵ�һ��λ��
//	map��ʼ�������Ϊ<0, -1>��Ϊû��һ�������ۼӵĺ�����Ϊ0��������λ��Ϊ����� - 1λ�á�������δ��ʼ������
//	map<sum, index>, ��sum����ʱ��map�����£�����
//	ע�⣺
//	����Ҫ�ҵ���sum - aim = index == key��map��������ֵ�λ�ã������м�¼
//	���磺7   3    2   1   1   7 - 6 - 1   7          num == 7
//	���ۻ���0������ 7��sum = 7, sum - aim = 0�� map�д���key = 0��λ�ã�������ֵ� λ��Ϊ - 1�� 
//	˵�������һ�������飬ʹ���ۼӺ�Ϊaim�����鳤��Ϊ0 - �� - 1�� = 1
//	Ȼ�����������������������4������1ʱ��
//	map��¼Ϊ{ <0,-1><7,0><10,1><12,2><13,3><14,4> }��
//	��ʱsumΪ14�� sum - aim = 14 - 7 = 7, key = 7����map�У�������ֵ�λ��Ϊ0��
//	˵�������һ�������飬ʹ���ۼӺ�Ϊaim�����鳤��Ϊ4 - ��0�� = 4



int mostLongSubArray(vector<int>v, int aim)
{
	int res = 0;//��¼���¼
	map<int, int>m;//��¼�ۼӺ�
	m[0] = -1;//�ʼ��λ��sumΪ0
	int sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
		if (m.find(sum) == m.end())//�ۼӺͲ�����
			m[sum] = i;
		auto ptr = m.find(sum - aim);
		if (ptr != m.end())//��¼����
			res = res > (i - (ptr->second)) ? res : (i - (ptr->second));//�������������¼
	}
	return res;
}

void Test()
{
	vector<int>v;
	v = { 7,3,2,1,1,7,7,7 };
	cout << mostLongSubArray(v, 7) << endl;
	v = { 7,3,2,1,1,7,-6,-1,7 };
	cout << mostLongSubArray(v, 7) << endl;
	v = { 7,5,2,4,3,1,1,1,1,1,1,1,1,7 };
	cout << mostLongSubArray(v, 7) << endl;
}