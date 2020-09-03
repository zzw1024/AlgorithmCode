#if 0
#include<iostream>
#include <string>


using namespace std;

//小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
//你能帮帮小Q吗？
//
//
//输入描述 :
//
//输入数据有多组，每组包含一个字符串s，且保证:1 <= s.length <= 1000.
//
//
//
//输出描述 :
//
//对于每组数据，输出移位后的字符串。
//
//
//输入例子1 :
//AkleBiCeilD
//
//输出例子1 :
//kleieilABCD

int main()
{
	string s;
	while (cin >> s)
	{
		size_t n = s.size();
		int uper = 0;
		for (auto a : s)//统计大写字母个数，
			if (a <= 'Z'&&a >= 'A')
				uper++;
		for(int i = 0;i<n;)
		{
			if (s[i] <= 'Z'&&s[i] >= 'A')//将大写字母向后挪
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