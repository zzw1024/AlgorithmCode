////#include <iostream>
////#include<string>
////#include <vector>
////#include<map>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	int ID, grade;
////	string name;
////};
////typedef bool(*funptr)(Node a, Node b);
////bool cmp1(Node a, Node b)
////{
////	return a.ID < b.ID;
////}
////bool cmp2(Node a, Node b)
////{
////	return (a.name == b.name) ? a.ID < b.ID : a.name < b.name;
////}
////bool cmp3(Node a, Node b)
////{
////	return (a.grade == b.grade) ? a.ID < b.ID : a.grade < b.grade;
////}
////
////int main()
////{
////	int N, C;
////	cin >> N >> C;
////	vector<Node>v;
////	funptr ptr[3] = { &cmp1,&cmp2,&cmp3 };
////	for (int i = 0; i < N; ++i)
////	{
////		Node node;
////		cin >> node.ID >> node.name >> node.grade;
////		v.push_back(node);
////	}
////	//使用函数指针
////	//sort(v.begin(), v.end(), *(ptr[C - 1]));
////
////	//使用普通方法
////	if (C == 1)
////		sort(v.begin(), v.end(), [](Node a, Node b) {return a.ID < b.ID; });
////	else if (C == 2)
////		sort(v.begin(), v.end(), [](Node a, Node b) {return (a.name == b.name) ? a.ID < b.ID : a.name < b.name; });
////	else
////		sort(v.begin(), v.end(), [](Node a, Node b) {return (a.grade == b.grade) ? a.ID < b.ID : a.grade < b.grade; });
////	for (auto a : v)
////		cout << a.ID << " " << a.name << " " << a.grade << endl;
////	return 0;
////}
////
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int ID;
//	string name;
//	int score;
//};
//int main()
//{
//	int n, m, id, score;
//	string name;
//	vector<Node>v;
//	cin >> n >> m;
//	while (n--)
//	{
//		cin >> id >> name >> score;
//		v.push_back({ id,name,score });		
//	}
//	switch (m)
//	{
//	case 1:
//		sort(v.begin(), v.end(), [](Node a, Node b) {return a.ID < b.ID; });
//		break;
//	case 2:
//		sort(v.begin(), v.end(), [](Node a, Node b) {if (a.name == b.name)return a.ID < b.ID; else return a.name < b.name; });
//		break;
//	case 3:
//		sort(v.begin(), v.end(), [](Node a, Node b) {if (a.score == b.score)return a.ID < b.ID; else return a.score < b.score; });
//		break;
//	default:
//		break;
//	}
//	for (auto a : v)
//		printf("%06d %s %d\n", a.ID, a.name.c_str(), a.score);
//	return 0;
//}