#include <iostream>
#include <string>

using namespace std;

//ʹ��manacher�㷨Ѱ���ַ�����Ļ����Ӵ�

int Manacher(string str)
{
	//�ַ���Ԥ����
	string newStr = "#";
	for (auto c : str)
		newStr = newStr + c + "#";
	//���İ뾶��¼����
	int* rIndex = new int[newStr.length()];
	int c = -1;//��������
	int R = -1;//�����ұ߽� Rλ�ڻ��ĶԳ��ұ߽���ұ�һ����ĸ
	int maxL = INT_MIN;//��¼������ֳ�
	for (int i = 0; i < newStr.length(); ++i)
	{
		//��һ��ֱ��ȡ�ÿ��ܵ���̵Ļ��İ뾶����i>Rʱ����̵Ļ��İ뾶��1��
		//��֮����̵Ļ��İ뾶������i��Ӧ��i'�Ļ��İ뾶����i��R�ľ���
		if (R > i)
			rIndex[i] = rIndex[2 * c - i] < R - i ? rIndex[2 * c - i] : R - i;
		else
			rIndex[i] = 1;
		//ȡ��Сֵ��ʼ�ӱ߽籩��ƥ�䣬ƥ��ʧ�ܾ�ֱ���˳�
		while (i + rIndex[i] < newStr.length() && i - rIndex[i] > -1)
		{
			if (newStr[i + rIndex[i]] == newStr[i - rIndex[i]])//��������չ���һ�����ĸ
				rIndex[i]++;
			else
				break;
		}
		//�۲��ʱR��C�Ƿ��ܹ�����
		if (i + rIndex[i] > R)
		{
			R = i + rIndex[i];
			c = i;
		}
		//���������İ뾶��ֵ
		maxL = maxL > rIndex[i] ? maxL : rIndex[i];
	}
	delete[] rIndex;
	//�������һ��Ϊʲô����ֵ��maxn-1����Ϊmanacherstring�ĳ��Ⱥ�ԭ�ַ�����ͬ��
	//��������õ��������İ뾶��ʵ��ԭ�ַ������������Ӵ����ȼ�1��
	//����Ȥ�Ŀ����Լ���֤����,-1��Ϊ�˽�����ġ�#��ȥ��
	return maxL - 1;	
	
}

void Test()
{
	string str = "abc1234321ab";
	cout << Manacher(str) << endl;
}