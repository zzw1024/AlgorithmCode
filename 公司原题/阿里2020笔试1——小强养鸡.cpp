#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//int n, m, k;
//vector<int>v;
//
//void downAdjust(int L, int R)
//{
//	int i = L, j = 2 * L + 1;;
//	while (j <= R)
//	{
//		if (j + 1 <= R && v[j + 1] > v[j])++j;
//		if (v[j] <= v[i])break;
//		swap(v[i], v[j]);
//		i = j;
//		j = 2 * i + 1;
//	}
//}
//
//void creatTree()
//{
//	for (int i = n / 2; i >= 0; --i)
//		downAdjust(i, n - 1);
//}
//
//void moveNode()
//{
//	int value = v[0], index = 0;;
//	int L = 1, R = 2;
//	while (L < n)
//	{
//		if (value >= v[L] && value >= v[R])break;
//		index = v[L] >= v[R] ? L : R;
//		L = 2 * index + 1;
//		R = L + 1;
//	}
//}
//
//
//int main()
//{	
//	cin >> n >> m >> k;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	creatTree();
//	while (m--)
//	{
//		for (int i = 0; i < n; ++i)
//			v[i] += k;
//		v[0] /= 2;
//		downAdjust(0,n-1);
//	}
//	long long int res = 0;
//	for (int i = 0; i < n; ++i)
//		res += v[i];
//	cout << res << endl;
//	return 0;
//}
//
//
//int main()
//{
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<int>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
//	while (m--)
//	{
//		int index = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			v[i] += k;
//			if (v[index] < v[i])
//				index = i;
//		}
//		v[index] /= 2;
//	}
//	long long int res = 0;
//	for (int i = 0; i < n; ++i)
//		res += v[i];
//	cout << res << endl;
//	return 0;
//}
