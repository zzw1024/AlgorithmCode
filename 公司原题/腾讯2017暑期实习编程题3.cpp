#if 0
#include<iostream>
#include<map>

using namespace std;

//СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬�����С���ж��ٶ��أ��������أ�
//
//
//�������� :
//
//�����������������ݡ�
//
//����ÿ��������ݣ�
//
//N - �������������n����
//
//a1, a2...an - ��Ҫ���������
//
//��֤ :
//
//1 <= N <= 100000, 0 <= ai <= INT_MAX.
//
//
//
//������� :
//
//����ÿ�����ݣ��������������һ������ʾ����С�Ķ������ڶ�������ʾ�����Ķ�����
//
//
//��������1 :
//6
//45 12 45 32 5 6
//
//�������1 :
//1 2



int main()
{
	int nums;
	while (cin >> nums)
	{
		int a;
		map<int, int>numbers;
		for (int i = 0; i < nums; ++i)//ʹ��map�����ݣ����Զ�����
		{
			cin >> a;
			numbers[a]++;
		}
		int zerosN = 0;
		map<int, int>oneN;
		for (auto it = numbers.begin(); it != numbers.end(); ++it)
		{
			if (it->second > 1)//������ͬ��ĸ������С��Ϊ0������Ϊ������ͬ���ֵ����
				zerosN += (it->second)*(it->second - 1) / 2;//������ϸ���Ϊ����
			auto ptr = it;
			if (++ptr != numbers.end())//��û����ͬ���֣����ж��ٶ���С���Ϊ������
				oneN[ptr->first - it->first]++;//��map����֪����С��Ϊ��һ��
		}
		if (zerosN == 0)
			cout << oneN.begin()->second << ' ' << (numbers.begin()->second * (--numbers.end())->second) << endl;
		else
			cout << zerosN << ' ' << (numbers.begin()->second * (--numbers.end())->second) << endl;
	}



	system("pause");
	return 0;
}


#endif