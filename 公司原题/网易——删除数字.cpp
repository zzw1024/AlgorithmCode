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
	for(int t = 0;t<1;++t)//输入数据大小
	{
		cin >> A >> k;		
		ss << A;
		ss >> str;	//转换为字符串更方便
		if (k >= str.size())//删除的位数超过输入数字的位数
		{
			A = 0;
			res.push_back(A);
			continue;
		}		
		while (k--)
		{
			int flag = 1;//数组是否为递增标记
			for (int i = 1; i < str.size(); ++i)
				if (str[i-1] > str[i])//删除较大的数字
				{
					str.erase(i-1,1);
					flag = 0;
					break;
				}
			if (flag)//剩下的为递增，直接删除后面的数字就行
			{
				str.assign(str, 0, str.size() - k-1);
				break;
			}
		}
		ss.str("");
		ss.clear();
		ss << str;
		ss >> A;//将字符转换为数字
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