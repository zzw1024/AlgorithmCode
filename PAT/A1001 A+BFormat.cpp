//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <sstream>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//	int a, b,sum;
//	string str;
//	scanf("%d %d", &a, &b);
//	sum = a + b;
//	stringstream ss;
//	ss << sum;
//	ss >> str;
//
//	///此处可以通过sum/1000，然后转为字符串
//	stack<string>res;
//	int k;
//	string s;
//	for (k = str.length(); k > 3;k-=3)
//	{	
//		s.assign(str.begin() + k - 3, str.begin() + k);
//		res.push(s);
//		res.push(",");
//	}
//	s.assign(str.begin(), str.begin() + k);
//	if (s == "-")
//		res.pop();
//	res.push(s);
//	while (!res.empty())
//	{
//		cout << res.top();
//		res.pop();
//	}
//	return 0;
//}


