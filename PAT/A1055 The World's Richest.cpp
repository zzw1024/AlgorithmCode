////#include <iostream>
////#include <vector>
////#include <string>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	string name;
////	int age, val;
////}node;
////int N, K;
////bool cmp(Node a, Node b)
////{
////	if (a.val == b.val && a.age == b.age)
////		return a.name < b.name;
////	else if (a.val == b.val)
////		return a.age < b.age;
////	else
////		return a.val > b.val;
////}
////int main()
////{
////	cin >> N >> K;
////	vector<Node>v;
////	vector<vector<Node>>res(K);
////	vector<vector<int>>quer(K, vector<int>(3, 0));
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> node.name >> node.age >> node.val;
////		v.push_back(node);
////	}
////	sort(v.begin(), v.end(), cmp);
////	for (int i = 0; i < K; ++i)
////		cin >> quer[i][0] >> quer[i][1] >> quer[i][2];
////	for (auto a : v)
////		for (int i = 0; i < K; ++i)
////			if (a.age >= quer[i][1] && a.age <= quer[i][2])
////				res[i].push_back(a);
////	for (int i = 0; i < K; ++i)
////	{
////		cout << "Case #" << i + 1 << ":" << endl;
////		if (res[i].size() == 0)
////			cout << "None" << endl;
////		else
////			for (int j = 0; j < quer[i][0] && j < res[i].size(); ++j)
////				cout << res[i][j].name << " " << res[i][j].age << " " << res[i][j].val << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	string name;
//	int age, w;
//};
//int main()
//{
//	int n, k, m, age, a, b, w;
//	int nums[205] = { 0 };//以为输出m<100，故每个年龄多出100人就不要输出
//	string name;
//	cin >> n >> k;
//	vector<Node>v;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> name >> age >> w;
//		nums[age]++;
//		if (nums[age] <= 100)
//			v.push_back({ name,age,w });
//	}
//	sort(v.begin(), v.end(), [](Node v1, Node v2) {
//		if (v1.age == v2.age&& v1.w == v2.w)
//			return v1.name < v2.name;
//		else if (v1.w == v2.w)
//			return v1.age < v2.age;
//		else
//			return v1.w > v2.w; });
//	for (int i = 1; i <= k; ++i)
//	{
//		cin >> m >> a >> b;
//		vector<Node>temp;
//		for (int j = 0; j < n; ++j)
//			if (v[j].age >= a && v[j].age <= b)
//				temp.push_back(v[j]);
//		cout << "Case #" << i << ":";
//		if (temp.size() > 0)
//			for (int j = 0; j < temp.size() && j < m; ++j)
//				cout << temp[j].name << " " << temp[j].age << " " << temp[j].w << endl;
//		else
//			cout << endl << "None";
//	}
//	return 0;
//}