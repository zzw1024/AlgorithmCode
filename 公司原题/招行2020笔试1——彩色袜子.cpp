//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int T, n;
//	cin >> T;
//	while (T--)
//	{
//		cin >> n;
//		vector<int>color(n);
//		int res = 0;
//		bool flag = false;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> color[i];
//			if (color[i] > 0)//开始每种袜子选一只
//				++res;
//			if (color[i] >= 2)//至少一种颜色能配一双
//				flag = true;
//		}
//		++res;//再从剩下的袜子中多加一只就能凑成一对
//		if (flag)
//			cout << res << endl;
//		else
//			cout << -1 << endl;
//	}
//	return 0;
//}