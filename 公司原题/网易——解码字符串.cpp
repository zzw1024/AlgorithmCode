#if 0
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{	
	vector<string>Ans;
	for (int n = 0; n < 2; ++n)//输入数据组数
	{
		stack<char>res;
		string str;
		cin >> str;//输入测试数组
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == ']')//栈出
			{
				string tempstr = "";
				while (res.top() != '[')
				{
					tempstr += res.top();//获取循环字符串
					res.pop();
				}
				res.pop();//弹出‘[’
				int i = 1, num = 0;
				while (res.top() >= '0'&&res.top() <= '9')//防止是两位数字
				{
					num += num + (res.top()-'0')*i;
					i = 10 * i;
					res.pop();
				}
				while (num--)
				{
					for (int j = tempstr.size() - 1; j >= 0; --j)//循环再次入栈
						res.push(tempstr[j]);
				}
				tempstr = "";//清空临时字符
			}

			else
				res.push(str[i]);//入栈
		}
		string restr;
		restr.resize(res.size());
		int i = res.size();
		while (i--)
		{
			restr[i] = res.top();//反向出栈存储
			res.pop();
		}
		Ans.push_back(restr);	
	}
	//输出
	for (auto a : Ans)
		cout << a << endl;

	system("pause");
	return 0;
}
#endif