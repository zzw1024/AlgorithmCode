#if 0

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	int A;
	int k;
	string str;
	vector<int>res;
	stringstream ss;
	for(int t = 0;t<1;++t)//�������ݴ�С
	{
		cin >> A >> k;		
		ss << A;
		ss >> str;	//ת��Ϊ�ַ���������
		if (k >= str.size())//ɾ����λ�������������ֵ�λ��
		{
			A = 0;
			res.push_back(A);
			continue;
		}		
		while (k--)
		{
			int flag = 1;//�����Ƿ�Ϊ�������
			for (int i = 1; i < str.size(); ++i)
				if (str[i-1] > str[i])//ɾ���ϴ������
				{
					str.erase(i-1,1);
					flag = 0;
					break;
				}
			if (flag)//ʣ�µ�Ϊ������ֱ��ɾ����������־���
			{
				str.assign(str, 0, str.size() - k-1);
				break;
			}
		}
		ss.str("");
		ss.clear();
		ss << str;
		ss >> A;//���ַ�ת��Ϊ����
		res.push_back(A);
		ss.str("");
		ss.clear();
		
	}
	for (auto a : res)
		cout << a << endl;
	system("pause");
	return 0;
}
#endif