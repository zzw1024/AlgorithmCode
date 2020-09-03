//////#include <iostream>
//////#include <unordered_map>
//////#include <string>
//////#include <algorithm>
//////#include <vector>
//////#include <map>
//////using namespace std;
//////
////////完了，英文不好会死人呀，看了别人的解释才知道，是找出每个学生在A,C,M,E中的最好排名
////////如果在A、C、M、E排序过程中遇到同样的分数，需要有相同的排名，
////////比如在A这一科上5个人的成绩分别是100,90,90,88,87的话，排名应该是1,2,2,4,5，
////////这一点需要格外留意，不然没有办法通过所有测试。
//////
//////struct Data
//////{
//////	string No;
//////	int num;
//////	int rank;
//////};
//////
//////int main()
//////{
//////	int N, M;
//////	cin >> N >> M;
//////	vector<Data>nums[4];//A C M E
//////	unordered_map <string, int>name;//用于学号查找
//////	for (int i = 0; i < N; ++i)
//////	{
//////		string No;
//////		int c, m, e;
//////		cin >> No >> c >> m >> e;
//////		name[No]++;
//////		nums[0].push_back({ No,(c + m + e) / 3,1 });
//////		nums[1].push_back({ No,c,1 });
//////		nums[2].push_back({ No,m,1 });
//////		nums[3].push_back({ No,e,1 });
//////	}
//////	for (int i = 0; i < 4; ++i)
//////	{
//////		sort(nums[i].begin(), nums[i].end(), [](Data d1, Data d2) {return d1.num > d2.num; });
//////		for (int j = 1; j < nums[i].size(); ++j)
//////		{
//////			if (nums[i][j].num == nums[i][j - 1].num)//处理相同分数
//////				nums[i][j].rank = nums[i][j - 1].rank;
//////			else
//////				nums[i][j].rank = j + 1;//要跳过相同排名
//////		}
//////	}
//////	
//////	for (int j = 0; j < M; ++j)
//////	{
//////		string No;
//////		cin >> No;
//////		int a, c, m, e;
//////		if (name[No] == 0)
//////			cout << "N/A" << endl;
//////		else
//////		{
//////			for (int i = 0; i < name.size(); ++i)
//////			{
//////				if (nums[0][i].No == No)	a = nums[0][i].rank;
//////				if (nums[1][i].No == No)	c = nums[1][i].rank;
//////				if (nums[2][i].No == No)	m = nums[2][i].rank;
//////				if (nums[3][i].No == No)	e = nums[3][i].rank;
//////			}			
//////			if (a <= c && a <= m && a <= e)				cout << a << " " << "A" << endl;
//////			else if (c <= a && c <= m && c <= e)		cout << c << " " << "C" << endl;
//////			else if (m <= a && m <= c && m <= e)		cout << m << " " << "M" << endl;
//////			else	cout << e << " " << "E" << endl;		
//////		}
//////	}
//////	return 0;
//////}
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <map>
////using namespace std;
////struct Node
////{
////	int ID, num, rank;
////};
////int n, m;
////int main()
////{
////	cin >> n >> m;
////	vector<Node>v[4];
////	map<int, int>mp;
////	int id, a, b, c;
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> id >> a >> b >> c;
////		mp[id]++;
////		v[0].push_back({ id,a + b + c,1 });
////		v[1].push_back({ id,a,1 });
////		v[2].push_back({ id,b,1 });
////		v[3].push_back({ id,c,1 });		
////	}
////	for (int i = 0; i < 4; ++i)
////	{
////		sort(v[i].begin(), v[i].end(), [](Node a, Node b) {return a.num > b.num; });
////		for (int j = 1; j < v[i].size(); ++j)
////		{
////			if (v[i][j].num == v[i][j - 1].num)
////				v[i][j].rank = v[i][j - 1].rank;
////			else
////				v[i][j].rank = j + 1;
////		}
////	}
////	while (m--)
////	{
////		cin >> id;
////		if (mp[id] != 1)
////		{
////			cout << "N/A" << endl;
////			continue;
////		}
////		map<int, int>res;
////		char c[4] = { 'A','C','M','E' };
////		for (int j = 0; j < v[0].size(); ++j)
////		{
////			if (v[0][j].ID == id) res.insert(make_pair(v[0][j].rank, 0));
////			if (v[1][j].ID == id) res.insert(make_pair(v[1][j].rank, 1));
////			if (v[2][j].ID == id) res.insert(make_pair(v[2][j].rank, 2));
////			if (v[3][j].ID == id) res.insert(make_pair(v[3][j].rank, 3));
////		}
////		printf("%d %c\n", res.begin()->first, c[res.begin()->second]);		
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//struct Node
//{
//	int id, C, M, E, A, rankC, rankM, rankE, rankA;
//};
//void print(Node a)
//{
//	int rank[4] = { a.rankA,a.rankC,a.rankM,a.rankE };
//	char c[4] = { 'A','C','M','E' };
//	int min = rank[0], index = 0;
//	for (int i = 1; i < 4; ++i)
//	{
//		if (min > rank[i])
//		{
//			min = rank[i];
//			index = i;
//		}
//	}
//	cout << min << " " << c[index] << endl;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	unordered_map<int, Node>students;
//	vector<Node>v;
//	for (int i = 0; i < n; ++i)
//	{
//		int id, C, M, E;
//		cin >> id >> C >> M >> E;
//		v.push_back({ id, C, M, E, C + M + E, 0, 0, 0, 0 });
//	}
//	sort(v.begin(), v.end(), [](Node a, Node b) {return a.A > b.A; });
//	for (int i = 0; i < n; ++i)
//		if (i > 0 && v[i].A == v[i - 1].A)
//			v[i].rankA = v[i - 1].rankA;
//		else
//			v[i].rankA = i + 1;
//
//	sort(v.begin(), v.end(), [](Node a, Node b) {return a.C > b.C; });
//	for (int i = 0; i < n; ++i)
//		if (i > 0 && v[i].C == v[i - 1].C)
//			v[i].rankC = v[i - 1].rankC;
//		else
//			v[i].rankC = i + 1;
//
//	sort(v.begin(), v.end(), [](Node a, Node b) {return a.M > b.M; });
//	for (int i = 0; i < n; ++i)
//		if (i > 0 && v[i].M == v[i - 1].M)
//			v[i].rankM = v[i - 1].rankM;
//		else
//			v[i].rankM = i + 1;
//
//	sort(v.begin(), v.end(), [](Node a, Node b) {return a.E > b.E; });
//	for (int i = 0; i < n; ++i)
//		if (i > 0 && v[i].E == v[i - 1].E)
//			v[i].rankE = v[i - 1].rankE;
//		else
//			v[i].rankE = i + 1;
//	for (auto a : v)
//		students[a.id] = a;
//
//	for(int i=0;i<m;++i)
//	{
//		int id;
//		cin >> id;
//		if (students.find(id) != students.end())
//			print(students[id]);
//		else
//			cout << "N/A" << endl;
//	}
//	return 0;
//}
