#if 0
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{	
	vector<string>Ans;
	for (int n = 0; n < 2; ++n)//������������
	{
		stack<char>res;
		string str;
		cin >> str;//�����������
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == ']')//ջ��
			{
				string tempstr = "";
				while (res.top() != '[')
				{
					tempstr += res.top();//��ȡѭ���ַ���
					res.pop();
				}
				res.pop();//������[��
				int i = 1, num = 0;
				while (res.top() >= '0'&&res.top() <= '9')//��ֹ����λ����
				{
					num += num + (res.top()-'0')*i;
					i = 10 * i;
					res.pop();
				}
				while (num--)
				{
					for (int j = tempstr.size() - 1; j >= 0; --j)//ѭ���ٴ���ջ
						res.push(tempstr[j]);
				}
				tempstr = "";//�����ʱ�ַ�
			}

			else
				res.push(str[i]);//��ջ
		}
		string restr;
		restr.resize(res.size());
		int i = res.size();
		while (i--)
		{
			restr[i] = res.top();//�����ջ�洢
			res.pop();
		}
		Ans.push_back(restr);	
	}
	//���
	for (auto a : Ans)
		cout << a << endl;

	system("pause");
	return 0;
}
#endif