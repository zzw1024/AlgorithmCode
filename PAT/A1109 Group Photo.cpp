////#include <iostream>
////#include <string>
////#include <vector>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	string name;
////	int height;
////}node;
////bool cmp(Node a, Node b)
////{
////	if (a.height == b.height)
////		return a.name < b.name;
////	else
////		return a.height > b.height;
////}
////int main()
////{
////	int n, m, k;
////	cin >> n >> k;
////	m = n / k;
////	vector<string>*v = new vector<string>[k];
////	vector<Node>people;
////	for (int i = 0; i < k; ++i)
////	{
////		if (i == 0 && n%k != 0)
////			v[0].resize(m + n % k);
////		else
////			v[i].resize(m);
////	}
////	while (n--)
////	{
////		cin >> node.name >> node.height;
////		people.push_back(node);
////	}
////	sort(people.begin(), people.end(), cmp);
////	int t = 0;
////	for (int i = 0; i < k; ++i)
////	{
////		m = v[i].size();
////		int mid = m / 2, left = mid - 1, right = mid + 1;
////		v[i][mid] = people[t++].name;
////		while (left >= 0 || right < m)
////		{
////			if (left >= 0)
////				v[i][left--] = people[t++].name;
////			if (right < m)
////				v[i][right++] = people[t++].name;
////		}
////	}
////	for (int i = 0; i < k; ++i)
////	{
////		for (int j = 0; j < v[i].size(); ++j)
////			cout << v[i][j] << (j == v[i].size() - 1 ? "" : " ");
////		cout << endl;
////	}
////	return 0;
////}
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	string name;
//	int tall;
//};
//int main()
//{
//	int n, k, t = 0;
//	cin >> n >> k;
//	vector<Node>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i].name >> v[i].tall;
//	sort(v.begin(), v.end(), [](Node a, Node b) {if (a.tall == b.tall)return a.name < b.name; else return a.tall > b.tall; });
//	for (int i = 0; i < k; ++i)
//	{
//		vector<Node>temp;
//		if (i == 0)
//			temp.resize(n / k + n % k);
//		else
//			temp.resize(n / k);
//		int m = (temp.size() / 2);
//		int L = m - 1, R = m + 1;
//		temp[m] = v[t++];
//		while (L >= 0 || R < temp.size())
//		{
//			if (L >= 0)
//				temp[L--] = v[t++];
//			if (R < temp.size())
//				temp[R++] = v[t++];
//		}
//		for (int j = 0; j < temp.size(); ++j)
//			cout << (j == 0 ? "" : " ") << temp[j].name;
//		cout << endl;
//	}
//	return 0;
//}
