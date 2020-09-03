////#include <iostream>
////#include <vector>
////#include <unordered_map>
////#include <string>
////#include <algorithm>
////#include <cmath>
////using namespace std;
////struct Node
////{
////	string name;
////	int Gp = -1, Gmid = -1, Gfinal = -1, G;//之所以不给-1，方便后面相加不用判断
////};
////int p, m, n;
////unordered_map<string, int>nameID;
////vector<Node>students;
////int main()
////{
////	int score;
////	string name;
////	cin >> p >> m >> n;
////	while (p--)
////	{
////		cin >> name >> score;
////		if (score < 200)//小于200的不要
////			continue;
////		nameID[name] = students.size();
////		students.push_back(Node{ name,score,-1,-1,0 });
////	}
////	while (m--)
////	{
////		cin >> name >> score;
////		if (nameID.find(name) != nameID.end())//无记录的不要			
////			students[nameID[name]].Gmid = score;
////	}
////	while (n--)
////	{
////		cin >> name >> score;
////		if (nameID.find(name) != nameID.end())//无记录的不要			
////			students[nameID[name]].Gfinal = score;
////	}
////	for (int i = 0; i < students.size(); ++i)
////	{
////		if (students[i].Gfinal > students[i].Gmid)
////			students[i].G = students[i].Gfinal;
////		else
////			students[i].G = round(students[i].Gmid*0.4 + students[i].Gfinal*0.6);
////	}
////	sort(students.begin(), students.end(), [](Node a, Node b)
////	{
////		if (a.G == b.G)
////			return a.name < b.name;
////		else
////			return a.G > b.G;
////	});
////	for (auto v : students)
////		if (v.Gp >= 200 && v.G >= 60)
////			cout << v.name << " " << v.Gp << " " << v.Gmid << " " << v.Gfinal << " " << v.G << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	string name;
//	int P = -1, Gm = -1, Gf = -1, G = -1;
//};
//int main()
//{
//	int n, m, k, score;
//	cin >> n >> m >> k;
//	unordered_map<string, Node>map;
//	vector<Node>res;
//	string name;
//	while (n--)
//	{
//		cin >> name >> score;
//		map[name].name = name;
//		map[name].P = score;
//	}
//	while (m--)
//	{
//		cin >> name >> score;
//		map[name].name = name;
//		map[name].Gm = score;
//	}
//	while (k--)
//	{
//		cin >> name >> score;
//		map[name].name = name;
//		map[name].Gf = score;
//	}
//	for (auto ptr = map.begin(); ptr != map.end(); ++ptr)
//	{
//		ptr->second.G = ((ptr->second.Gf == -1) ? -1 : (ptr->second.Gm > ptr->second.Gf) ? (ptr->second.Gm*0.4 + ptr->second.Gf*0.6+0.5) : ptr->second.Gf);
//		if (ptr->second.P >= 200 && ptr->second.G >= 60)
//			res.push_back(ptr->second);
//	}
//	sort(res.begin(), res.end(), [](Node a, Node b) {if (a.G == b.G)return a.name < b.name; else return a.G > b.G; });
//	for (auto a : res)
//		cout << a.name << " " << a.P << " " << a.Gm << " " << a.Gf << " " << a.G << endl;
//	return 0;
//}
