////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <string>
////using namespace std;
////int N;
////struct Node
////{
////	string name, gender, ID;
////	int grade;
////}node;
////int main()
////{
////	cin >> N;
////	vector<Node>male, female;
////
////	//此代码是将数据保存下来排序，还可以直接在输入时就得到最高分和最低分，这样就大大节省了空间和时间
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> node.name >> node.gender >> node.ID >> node.grade;
////		if (node.gender == "M")
////			male.push_back(node);
////		else
////			female.push_back(node);
////	}
////	sort(male.begin(), male.end(), [](Node a, Node b) {return a.grade < b.grade; });
////	sort(female.begin(), female.end(), [](Node a, Node b) {return a.grade > b.grade; });
////	if (female.size() == 0)
////		cout << "Absent" << endl;
////	else
////		cout << female[0].name << " " << female[0].ID << endl;
////	if (male.size() == 0)
////		cout << "Absent" << endl;
////	else
////		cout << male[0].name << " " << male[0].ID << endl;
////	if (female.size() == 0 || male.size() == 0)
////		cout << "NA" << endl;
////	else
////		cout << female[0].grade - male[0].grade << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
//struct  Node
//{
//	string name, id;
//	int score;
//};
//int main()
//{
//	int n;
//	cin >> n;
//	vector<Node>F, M;
//	string name, flag, id;
//	int score;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> name >> flag >> id >> score;
//		if (flag == "M")
//			M.push_back({ name, id,score });
//		else
//			F.push_back({ name, id,score });
//	}
//	sort(M.begin(), M.end(), [](Node a, Node b) {return a.score < b.score; });
//	sort(F.begin(), F.end(), [](Node a, Node b) {return a.score > b.score; });
//	if (F.size() == 0)
//		printf("Absent\n");
//	else
//		cout << F[0].name << " " << F[0].id << endl;
//	if (M.size() == 0)
//		printf("Absent\n");
//	else
//		cout << M[0].name << " " << M[0].id << endl;
//	if (F.size() == 0 || M.size() == 0)
//		printf("NA\n");
//	else
//		printf("%d\n", abs(M[0].score - F[0].score));
//	return 0;
//}