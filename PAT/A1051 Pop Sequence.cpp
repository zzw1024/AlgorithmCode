////#include <iostream>
////#include <stack>
////using namespace std;
////int M, N, K;
////int main()
////{
////	cin >> M >> N >> K;	
////	for (int i = 0; i < K; ++i)
////	{
////		stack<int>s;
////		int a, b = 1, flag = 1;
////		for (int j = 0; j < N; ++j)
////		{
////			cin >> a;
////			while (s.size() < M && (s.empty() || s.top() != a))
////				s.push(b++);
////			if (s.top() == a)
////				s.pop();
////			else
////				flag = 0;
////		}
////		if (flag == 1)
////			cout << "Yes" << endl;
////		else
////			cout << "No" << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <stack>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, m, k;
//	cin >> n >> m >> k;	
//	for (int i = 0; i < k; ++i)
//	{
//		stack<int>s;
//		int a, num = 1, flag = 1;
//		for (int j = 0; j < m; ++j)
//		{
//			cin >> a;
//			while (s.size()<n && (s.empty() || s.top() != a))
//				s.push(num++);
//			if (s.top() == a)
//				s.pop();
//			else
//				flag = 0;			
//		}			
//		if (flag==1)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}