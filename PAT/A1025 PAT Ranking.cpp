////#include <iostream>
////#include <vector>
////#include <string>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	string No;
////	int score, final_rank, location_num, local_rank;
////};
////
////bool cmp(Node* a, Node* b)
////{
////	return (a->score == b->score) ? (a->No < b->No) : (a->score > b->score);
////}
////int N, K;
////vector<Node*>allPerson;
////int main()
////{
////	cin >> N;
////	for (int i = 1; i <= N; ++i)
////	{
////		cin >> K;
////		vector<Node*>temp;
////		for (int j = 0; j < K; ++j)
////		{
////			Node* node = new Node;
////			cin >> node->No >> node->score;
////			node->location_num = i;
////			temp.push_back(node);
////		}
////		sort(temp.begin(), temp.end(), cmp);
////		for (int j = 0; j < temp.size(); ++j)
////		{
////			if (j > 0 && temp[j]->score == temp[j - 1]->score)
////				temp[j]->local_rank = temp[j - 1]->local_rank;
////			else
////				temp[j]->local_rank = j + 1;
////		}
////		allPerson.insert(allPerson.end(), temp.begin(), temp.end());
////	}
////	sort(allPerson.begin(), allPerson.end(), cmp);
////	cout << allPerson.size() << endl;
////	for (int j = 0; j < allPerson.size(); ++j)
////	{
////		if (j>0 && allPerson[j]->score == allPerson[j - 1]->score)
////			allPerson[j]->final_rank = allPerson[j - 1]->final_rank;
////		else
////			allPerson[j]->final_rank = j + 1;
////		cout << allPerson[j]->No << " " << allPerson[j]->final_rank << " " <<
////			allPerson[j]->location_num << " " << allPerson[j]->local_rank << endl;
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
//	string id;
//	int  final, number, local, score;
//};
//bool cmp(Node a, Node b)
//{
//	if (a.score == b.score)
//		return a.id < b.id;
//	else
//		return a.score > b.score;
//}
//int main()
//{
//	string id;
//	int n, k, score;
//	vector<Node> res;
//	cin >> n;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> k;
//		vector<Node>v;
//		while (k--)
//		{
//			cin >> id >> score;
//			v.push_back({ id,1,i,1,score });
//		}
//		sort(v.begin(), v.end(), [](Node a, Node b) {return a.score > b.score; });
//		res.push_back(v[0]);
//		for (int i = 1; i < v.size(); ++i)
//		{
//			if (v[i].score == v[i - 1].score)
//				v[i].local = v[i - 1].local;
//			else
//				v[i].local = i + 1;
//			res.push_back(v[i]);
//		}
//	}
//	sort(res.begin(), res.end(), cmp);
//	cout << res.size() << endl;
//	for (int i = 0; i < res.size(); ++i)
//	{
//		if (i > 0)
//		{
//			if (res[i].score == res[i - 1].score)
//				res[i].final = res[i - 1].final;
//			else
//				res[i].final = i + 1;
//		}
//		cout << res[i].id << " " << res[i].final << " " << res[i].number << " " << res[i].local << endl;
//	}
//	return 0;	
//}