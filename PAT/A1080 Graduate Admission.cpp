////#include <iostream>
////#include <vector>
////#include <algorithm>
//////录取规则，排名靠前的人优先选择学校
////using namespace std;
////int N, M, K;
////struct Node
////{
////	int id, Ge, Gt, G, rank, choice[6];
////}node;
////struct Sch
////{
////	int quto;
////	vector<pair<int,int>>admin;//录取的学生id，rank
////}sch;
////vector<Sch>school;
////vector<Node>applicant;
////bool cmp(Node a, Node b)
////{
////	if (a.G != b.G)
////		return a.G > b.G;
////	else
////		return a.Ge > b.Ge;
////}
////int main()
////{
////	cin >> N >> M >> K;
////	for (int i = 0; i < M; ++i)
////	{
////		cin >> sch.quto;
////		school.push_back(sch);
////	}
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> node.Ge >> node.Gt;
////		node.G = node.Ge + node.Gt;
////		node.id = i;
////		for (int j = 0; j < K; ++j)
////		{
////			int t;
////			cin >> t;
////			node.choice[j] = t;//志愿学校
////		}
////		applicant.push_back(node);
////	}
////	sort(applicant.begin(), applicant.end(), cmp);
////	applicant[0].rank = 1;
////	for (int i = 1; i < N; ++i)//排名
////	{
////		if (applicant[i].G == applicant[i - 1].G && applicant[i].Ge == applicant[i - 1].Ge)
////			applicant[i].rank = applicant[i - 1].rank;
////		else
////			applicant[i].rank = i + 1;
////	}
////	for (int i = 0; i < N; ++i)//按学生选学校
////	{
////		for (int j = 0; j < K; ++j)
////		{
////			int t = applicant[i].choice[j];
////			if (school[t].quto == 0 && (school[t].admin.end() - 1)->second == applicant[i].rank)//排名相同可以超额
////			{
////				school[t].admin.push_back(make_pair(applicant[i].id, applicant[i].rank));//超额录取
////				break;
////			}
////			else if (school[t].quto == 0)
////				continue;//面试下一所学校，该学校满额
////			else
////			{
////				school[t].admin.push_back(make_pair(applicant[i].id, applicant[i].rank));//正常录取
////				school[t].quto--;//名额减少
////				break;
////			}
////		}
////	}
////	for (int i = 0; i < M; ++i)
////	{
////		sort(school[i].admin.begin(), school[i].admin.end());
////		for (int j = 0; j < school[i].admin.size(); ++j)
////			cout << school[i].admin[j].first << (j == school[i].admin.size() - 1 ? "" : " ");
////		cout << endl;
////	}	
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int id, Ge, Gi, fianl, rank;
//	bool isAdmiss = false;
//	vector<int>choice;
//};
//int main()
//{
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<Node>student(n);
//	vector<int>school(m, 0);
//	vector<vector<Node>>res(m);
//	for (int i = 0; i < m; ++i)
//		cin >> school[i];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> student[i].Ge >> student[i].Gi;
//		student[i].fianl = student[i].Ge + student[i].Gi;
//		student[i].isAdmiss = false;
//		student[i].id = i;
//		int a;
//		for (int j = 0; j < k; ++j)
//		{
//			cin >> a;
//			student[i].choice.push_back(a);
//		}
//	}
//	sort(student.begin(), student.end(), [](Node a, Node b) {
//		if (a.fianl == b.fianl)
//			return a.Ge > b.Ge;
//		else
//			return a.fianl > b.fianl; });
//	for (int i = 0; i < n; ++i)
//		if (i > 0 && student[i].fianl == student[i - 1].fianl && student[i].Ge == student[i - 1].Ge)
//			student[i].rank = student[i - 1].rank;
//		else
//			student[i].rank = i + 1;
//	for (int i = 0; i < n; ++i)//按排名
//	{
//		if (student[i].isAdmiss == true)continue;//被录取了
//		for (int j = 0; j < k; ++j)
//		{
//			int choice = student[i].choice[j];
//			if (res[choice].size() < school[choice] || student[i].rank == res[choice].back().rank)//未招满
//			{
//				res[choice].push_back(student[i]);//录取
//				student[j].isAdmiss = true;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		sort(res[i].begin(), res[i].end(), [](Node a, Node b) {return a.id < b.id; });
//		for (int j = 0; j < res[i].size(); ++j)
//			cout << (j == 0 ? "" : " ") << res[i][j].id;
//		cout << endl;
//	}
//	return 0;
//}
