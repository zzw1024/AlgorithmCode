#if 0
#include<iostream>
#include <string>


using namespace std;

//СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
//���ܰ��СQ��
//
//
//�������� :
//
//���������ж��飬ÿ�����һ���ַ���s���ұ�֤:1 <= s.length <= 1000.
//
//
//
//������� :
//
//����ÿ�����ݣ������λ����ַ�����
//
//
//��������1 :
//AkleBiCeilD
//
//�������1 :
//kleieilABCD

int main()
{
	string s;
	while (cin >> s)
	{
		size_t n = s.size();
		int uper = 0;
		for (auto a : s)//ͳ�ƴ�д��ĸ������
			if (a <= 'Z'&&a >= 'A')
				uper++;
		for(int i = 0;i<n;)
		{
			if (s[i] <= 'Z'&&s[i] >= 'A')//����д��ĸ���Ų
			{
				char c = s[i];
				for (int j = i; j < n - 1; ++j)
					s[j] = s[j + 1];
				s[n - 1] = c;
				if (--uper == 0)
					break;
			}
			else
				i++;
			
		}
		cout << s << endl;
	}
	system("pause");
	return 0;
}


#endif