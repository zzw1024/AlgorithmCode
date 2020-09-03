////#include <iostream>
////#include <vector>
////#include <string>
////#include <unordered_map>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	string ID;
////	bool flag;//1是进，0是出
////	int time;
////	Node(string s, bool f, int t) :ID(s), flag(f), time(t) {}
////};
////vector<Node>Cars;
////unordered_map<string, vector<Node>>map;//一辆车不止一个记录
////vector<string>res;
////int N, K, maxTime = 0;
////int main()
////{
////	cin >> N >> K;
////	string ID, flag;
////	int h, m, s;
////	while (N--)
////	{	
////		cin >> ID;
////		scanf("%d:%d:%d", &h, &m, &s);
////		cin >> flag;
////		map[ID].push_back(Node(ID, flag == "in", h * 3600 + m * 60 + s));
////	}
////	for (auto ptr = map.begin(); ptr != map.end(); ++ptr)
////	{
////		sort(ptr->second.begin(), ptr->second.end(), [](Node a, Node b) {return a.time < b.time; });
////		int t = 0;
////		for (int i = 0; i < ptr->second.size()-1; ++i)
////		{
////			if (ptr->second[i].flag == 1 && ptr->second[i + 1].flag == 0)//一进一出
////			{
////				Cars.push_back(ptr->second[i]);//记录合法时间
////				Cars.push_back(ptr->second[i + 1]);//记录合法时间
////				t += ptr->second[i + 1].time - ptr->second[i].time;//累加停车时间
////			}
////		}
////		if (t > maxTime)
////		{
////			maxTime = t;
////			res.clear();
////			res.push_back(ptr->first);
////		}
////		else if(t==maxTime)
////			res.push_back(ptr->first);
////	}
////	sort(Cars.begin(), Cars.end(), [](Node a, Node b) {return a.time < b.time; });
////	int num = 0, i = 0;
////	while (K--)
////	{
////		scanf("%d:%d:%d", &h, &m, &s);
////		int time = h * 3600 + m * 60 + s;
////		for (; i < Cars.size() && Cars[i].time <= time; ++i)
////			num += Cars[i].flag ? 1 : -1;//使用用-1表示该车开出去了
////		cout << num << endl;
////	}
////	sort(res.begin(), res.end());
////	for (auto v : res)
////		cout << v << " ";
////	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
////	return 0;
////}
////
////
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	string id, flag;
//	int times, in, out;
//};
//int main()
//{
//	int n, m, maxTime = 0, hh, mm, ss;
//	cin >> n >> m;
//	string id, flag;
//	vector<Node>v, cars;
//	vector<string>res;
//	unordered_map<string, int>map;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> id;
//		scanf("%d:%d:%d", &hh, &mm, &ss);
//		cin >> flag;
//		v.push_back({ id,flag,hh * 3600 + mm * 60 + ss,0,0 });
//	}
//	sort(v.begin(), v.end(), [](Node a, Node b) {
//		if (a.id == b.id)
//			return a.times < b.times;
//		else
//			return a.id < b.id; });
//	for (int i = 0; i < n - 1; ++i)
//	{
//		if (v[i].id == v[i + 1].id && v[i].flag == "in"&&v[i + 1].flag == "out")
//		{
//			int times = v[i + 1].times - v[i].times;
//			cars.push_back({ v[i].id,"true",times,v[i].times,v[i + 1].times });
//			map[v[i].id] += times;
//			if (map[v[i].id] > maxTime)
//			{
//				maxTime = map[v[i].id];
//				res.clear();
//				res.push_back(v[i].id);
//			}
//			else if (map[v[i].id] == maxTime)
//				res.push_back(v[i].id);
//		}
//	}
//	sort(cars.begin(), cars.end(), [](Node a, Node b) {return a.in < b.in; });
//	int k = 0, nums = 0, times;
//	while (m--)
//	{		
//		scanf("%d:%d:%d", &hh, &mm, &ss);
//		times = hh * 3600 + mm * 60 + ss;
//		for (; k < cars.size(); ++k)
//		{
//			if (cars[k].in <= times && cars[k].out > times)
//				nums++;
//			if (cars[k].in > times)
//				break;
//		}
//		cout << nums << endl;
//	}
//	sort(res.begin(), res.end(), [](string a, string b) {return a < b; });
//	for (auto t : res)
//		cout << t << " ";
//	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
//	return 0;
//}