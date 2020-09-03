////#include <iostream>
////#include <stack>
////#include <string>
////#include <cmath>
////using namespace std;
////int N, num, table[100010], block[316];//数的个数，块中数的个数
////int main()
////{
////	cin >> N;
////	stack<int>s;
////	string str;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> str;
////		if (str == "Pop")
////		{
////			if (s.size() > 0)
////			{
////				cout << s.top() << endl;
////				table[s.top()]--;
////				block[s.top() / 316]--;				
////				s.pop();
////			}
////			else
////				cout << "Invalid" << endl;
////		}
////		else if (str == "Push")
////		{
////			cin >> num;
////			s.push(num);
////			table[num]++;
////			block[num / 316]++;
////		}
////		else
////		{
////			if (s.size() > 0)
////			{
////				int mid = s.size() % 2 == 0 ? s.size() / 2 : (s.size() + 1) / 2;
////				int t = 0, k = 0;
////				while (k + block[t] < mid) k += block[t++];
////				int num = t * 316;
////				while (k + table[num] < mid)k += table[num++];
////				cout << num << endl;
////			}
////			else
////				cout << "Invalid" << endl;
////		}
////	}
////	return 0;	
////}
////
////
////
//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//int nums[100010] = { 0 }, block[317] = { 0 };
//int main()
//{
//	int n, a;
//	cin >> n;
//	string str;
//	stack<int>s;
//	while (n--)
//	{
//		cin >> str;
//		if (str == "Pop")
//		{
//			if (s.empty())
//				cout << "Invalid" << endl;
//			else
//			{
//				cout << s.top() << endl;
//				nums[s.top()]--;
//				block[s.top() / 317]--;
//				s.pop();
//			}
//		}
//		else if (str == "Push")
//		{
//			cin >> a;
//			s.push(a);
//			nums[a]++;
//			block[a / 317]++;
//		}
//		else
//		{
//			if(s.empty())
//				cout << "Invalid" << endl;
//			else
//			{
//				int m = 0, i = 0;
//				while ((m + block[i]) < (s.size() + 1) / 2) m += block[i++];
//				i = i * 317;
//				while (m < (s.size() + 1) / 2)m += nums[i++];
//				cout << i - 1 << endl;
//			}
//		}
//	}
//	return 0;
//}