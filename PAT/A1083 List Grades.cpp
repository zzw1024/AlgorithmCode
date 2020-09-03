////#include <iostream>
////#include <string>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	string name, id;
////	int grade;
////};
////int main()
////{
////	int N, grade1, grade2;
////	cin >> N;
////	Node* data = new Node[N];
////	for (int i = 0; i < N; ++i)
////		cin >> data[i].name >> data[i].id >> data[i].grade;
////	cin >> grade1 >> grade2;
////	sort(data, data + N, [](Node a, Node b) {return a.grade > b.grade; });
////	int flag = 1;
////	for (int i = 0; i < N; ++i)
////	{
////		if (data[i].grade < grade1)
////			break;
////		if (data[i].grade >= grade1 && data[i].grade <= grade2)
////		{
////			cout << data[i].name << " " << data[i].id << endl;
////			flag = 0;
////		}
////	}
////	if (flag == 1)
////		cout << "NONE" << endl;
////	delete[]data;
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
//	string name, id;
//	int score;
//};
//int main()
//{
//	int n, g1, g2;
//	cin >> n;
//	vector<Node>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i].name >> v[i].id >> v[i].score;
//	cin >> g1 >> g2;
//	sort(v.begin(), v.end(), [](Node a, Node b) {return a.score > b.score; });
//	bool flag = true;
//	for (auto a : v)
//		if (a.score >= g1 && a.score <= g2)
//		{
//			flag = false;
//			cout << a.name << " " << a.id << endl;
//		}
//	if (flag)
//		cout << "NONE";
//	return 0;
//}