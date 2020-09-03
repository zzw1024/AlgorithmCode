#pragma once
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//
//Problem��
//	��������arr������num���������ж��ٸ��������������������
//	max(arr[i..j]) - min(arr[i..j]) <= num
//	max(arr[i..j])��ʾ������arr[i..j]�е����ֵ��min(arr[i..j])��ʾ������arr[i..j]
//	�е���Сֵ��
//	��Ҫ��
//	������鳤��ΪN����ʵ��ʱ�临�Ӷ�ΪO(N)�Ľⷨ��
//
//
//Solution��
//	һ�����������Ҫ��������������е������鶼����Ҫ��
//	���һ��С���鲻����Ҫ�����ٽ�����������Ҳ�ǲ�����Ҫ��ġ�
//	���½�һ�����ڣ��������У�һ��ά�����ֵ��һ��ά����Сֵ��
//	��R�Ƶ�Nλ��������������N + 1λ�ò�������������ֹͣ������Ŀǰ����n + 1������������Ҫ��
//	Ȼ��L�ƶ�һ��λ�ã������������У�Ȼ��R�����ƶ���ֱ��Mλ������Ҫ��M + 1������Ҫ��������������M + 1 - 1��
//	Ȼ��һֱ��R��������������
//	���帴�Ӷ�ΪO(N)
//


int getSubArray(vector<int>v, const int num)
{
	deque<int>maxList;//�洢���ֵ
	deque<int>minList;//�洢��Сֵ
	int res = 0;
	int i, j;
	i = j = 0;
	for (int i = 0, j = 0; i < v.size(); ++i)
	{
		while (!maxList.empty() && v[i] >= v[maxList.back()])
			maxList.pop_back();
		maxList.push_back(i);

		while (!minList.empty() && v[i] <= v[minList.back()])
			minList.pop_back();
		minList.push_back(i);

		if ((v[maxList.front()] - v[minList.front()]) <= num )//����Ҫ���������ջ
			continue;
		//��ʱ������Ҫ��,����ǰ������Ҫ���������
		res = res + i - j;

		while ((v[maxList.front()] - v[minList.front()]) > num)
		{
			if (maxList.front() == j)
				maxList.pop_front();
			if (minList.front() == j)
				minList.pop_front();
			++j;
		}

	}
	//res = res + i - j;
	return res;
}

int getSubArray00(vector<int>v, const int num)
{
	deque<int>maxList;//�洢���ֵ
	deque<int>minList;//�洢��Сֵ
	int res = 0;
	int i, j;
	i = j = 0;
	while (j < v.size())
	{
		while (i < v.size())
		{
			while (!maxList.empty() && v[i] >= v[maxList.back()])
				maxList.pop_back();
			maxList.push_back(i);

			while (!minList.empty() && v[i] <= v[minList.back()])
				minList.pop_back();
			minList.push_back(i);

			if ((v[maxList.front()] - v[minList.front()]) > num)//������Ҫ��������
				break;
			++i;
		}
		if (maxList.front() == j)
			maxList.pop_front();
		if (minList.front() == j)
			minList.pop_front();

		res += i - j;
		++j;
	}
	
	return res;
}

void Test()
{
	vector<int>v;
	v = { 1,2,3,4,5 };
	cout << getSubArray(v, 0) << endl;
	cout << getSubArray00(v, 0) << endl;
}