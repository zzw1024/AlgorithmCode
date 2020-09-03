//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>speak(n + 1), name(n + 1, 0);
//	for (int i = 1; i <= n; ++i)cin >> speak[i];
//	for (int i = 1; i <= n; ++i)//假设i，j是狼人
//	{
//		for (int j = i + 1; j <= n; ++j)
//		{
//			vector<int>lie, v(n + 1, 1);//都是好人
//			v[i] = v[j] = -1;//标记狼人
//			for (int t = 1; t <= n; ++t)
//				if (v[abs(speak[t])] * speak[t] < 0)//说是好人，但实际是狼人，他说谎了
//					lie.push_back(t);
//			if (lie.size() == 2 && v[lie[0]] + v[lie[1]] == 0)//一个好人撒谎，一个坏人撒谎
//			{
//				cout << i << " " << j << endl;
//				return 0;
//			}
//		}
//	}
//	cout << "No Solution" << endl;
//	return 0;
//}

//
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>v(n + 1);
//	for (int i = 1; i <= n; ++i)
//		cin >> v[i];
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = i + 1; j <= n; ++j)
//		{
//			vector<int>human(n + 1, 1), lies;
//			human[i] = human[j] = -1;
//			for (int k = 1; k <= n; ++k)
//				if (v[k] * human[abs(v[k])] < 0)
//					lies.push_back(k);
//			if (lies.size() == 2 && human[lies[0]] + human[lies[1]] == 0)
//			{
//				cout << i << " " << j;
//				return 0;
//			}
//		}
//	}
//	cout << "No Solution" << endl;
//	return 0;
//}