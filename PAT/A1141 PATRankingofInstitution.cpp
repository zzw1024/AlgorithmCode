//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	string id, school;
//	double tws;//切记，一定是double，每次PAT就是在这里下套
//	int score, nums, rank;
//};
//int main()
//{
//	int n;
//	cin >> n;
//	vector<Node>v(n);
//	unordered_map<string, vector<int>>map;//记录相同学校的是哪些人
//	for (int i = 0; i < n; ++i)
//	{
//		string name, school;
//		int score;
//		cin >> name >> score >> school;
//		for (int j = 0; j < school.size(); ++j)
//			school[j] = tolower(school[j]);
//		v[i] = { name,school,0.0,score,1,0 };
//		map[school].push_back(i);
//	}
//	vector<Node>res;
//	for (auto ptr = map.begin(); ptr != map.end(); ++ptr)
//	{
//		vector<int>p = ptr->second;
//		res.push_back({ "", v[p[0]].school, 0.0, 0, (int)p.size(), 1 });//将相同学校的分数相加
//		for (auto a : p)
//		{
//			if (v[a].id[0] == 'A')
//				res.back().tws += v[a].score;
//			else if (v[a].id[0] == 'B')
//				res.back().tws += v[a].score / 1.5;
//			else
//				res.back().tws += v[a].score * 1.5;
//		}
//	}
//	sort(res.begin(), res.end(), [](Node a, Node b) {//排名
//		if ((int(a.tws)) == (int(b.tws)) && a.nums == b.nums)
//			return a.school < b.school;
//		else if ((int(a.tws)) == (int(b.tws)))
//			return a.nums < b.nums;
//		else
//			return a.tws > b.tws;
//		});
//	cout << res.size() << endl;
//	for (int i = 0; i < res.size(); ++i)
//	{
//		if (i > 0 && ((int)res[i].tws) == ((int)res[i-1].tws))
//			res[i].rank = res[i - 1].rank;
//		else
//			res[i].rank = i + 1;
//		cout << res[i].rank << " " << res[i].school << " " << (int)res[i].tws << " " << res[i].nums << endl;
//	}
//	return 0;
//}