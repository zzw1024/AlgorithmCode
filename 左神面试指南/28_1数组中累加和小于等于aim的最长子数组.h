#pragma once
#include <iostream>
#include <vector>

using namespace std;

//����Ŀ��
//	����һ������arr��ȫ��������һ������aim�����ۼӺ�С�ڵ�
//	��aim�ģ�������飬Ҫ�����ռ临�Ӷ�O(1)��ʱ��
//	���Ӷ�O(N)
//
//����⡿
//	ʹ�ô��ڣ�
//	˫ָ�룬��sum <= aim����R->, ��sum > aim, L->
//	��¼����R - L����
//
//�����ס�
//	����һ������arr��ֵ�������ɸ�����0��һ������aim�����ۼ�
//	��С�ڵ���aim�ģ�������飬Ҫ��ʱ�临�Ӷ�O(N)
//����⡿
//	֮���Ա�ԭ����ѣ�����Ϊ��������ʹ�����������鿪ʼ�ĺͺܴ󣬵��ӵ�����ʱ������;ͱ�С��
//	������������
//	min_sum[]  //min_sum[i]  ==  ��������i��ͷ���������С�ۻ���
//	min_sum_index[]//    min_sum_index[i]    ==  ����i��ͷ�������С�ۼӺ͵Ĵﵽ�����Ҷ�λ��
//	���ɣ�
//	������ĺ���ǰ�㣺
//	��nλ�õ���С�ۼӺ�Ϊ����ʱ����ôn - 1����С�ۼӺ�һ�����Լ�����n����С�ۼӺͣ������ұ߽���n��ͬ
//	��nλ�õ���С�ۼӺ�Ϊ����ʱ����ôn - 1����С�ۼӺ�һ�����Լ�����Ϊ��������Ҳ�Ǽ�һ�������������ұ߽�����Լ���λ��
//
//	��⣺
//	�ӵ�0������ʼ��Rֱ�ӵ�0λ�õ����ұ߽磬sum + 0λ�õ���С�ۼӺͣ�����sum<aim, ���ټ���Rλ�õ���С�ۼӺͣ�����R�Ƶ�Rλ�õ����ұ߽�
//		ֱ��sum>aim�������֪��������Ƕ�����
//

int theLongestArray(vector<int>v, int aim)
{
	//ʹ������ָ�룬��Ϊ���ڵ����Ҷ�
	int l = -1;
	int r = 0;
	int sum = 0;
	int res = 0;
	for (; r < v.size(); ++r)
	{
		sum += v[r];
		while (sum > aim && l < r)//�����ƶ�����
		{
			++l;
			sum -= v[l];
		}
		res = res > (r - l) ? res : (r - l);
	}
	return res;
}


int theLongestArray_2(vector<int>v, int aim)
{
	int* min_sum = new int[v.size()];//��i��ͷ���������С��
	int* min_sum_index = new int[v.size()];//��i��ͷ���������С�������Ҷ�
	for (int i = v.size()-1; i >= 0; --i)
	{
		if (i + 1 < v.size() && min_sum[i + 1] < 0)//�Ҷ���С��Ϊ��������ɼ����Լ����Լ���С
		{
			min_sum[i] = min_sum[i + 1] + v[i];
			min_sum_index[i] = min_sum_index[i + 1];
		}
		else//�Ҷ�Ϊ�����������Լ����Լ�����ô�����Լ�Ϊ��С�������
		{
			min_sum[i] = v[i];
			min_sum_index[i] = i;
		}
	}
	//���崰�ڵ����ұ߽�
	int l = -1;
	int r = 0;
	int res = 0;
	int sum = 0;
	for (int i=0;i<v.size();++i)
	{
		sum += min_sum[i];
		r = min_sum_index[i];
		while (l<r && sum>aim)
		{
			++l;
			sum -= v[l];
		}
		res = res > (r - l) ? res : (r - l);
	}
	delete[]min_sum;
	delete[]min_sum_index;
	return res;

}
void  Test()
{
	vector<int>v;
	v = {1,2,3,4,5,1,1,1,1,1,1,1,7,8,9};
	cout << theLongestArray(v, 7) << endl;
	v = { 1,2,3,4,5,1,1,-99,1,1,1,1,1,7,8,9,10,11,-99};
	cout << theLongestArray_2(v, 7) << endl;
}