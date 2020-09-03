//////#include <iostream>
//////#include <vector>
//////#include <map>
//////#include <string>
//////using namespace std;
//////int N;
//////vector<int>cost(25);
//////
//////double calMoney(string str, int& time)
//////{
//////	int d, h, m;
//////	double money = 0;
//////	d = (str[3] - '0') * 10 + str[4] - '0';
//////	h = (str[6] - '0') * 10 + str[7] - '0';
//////	m = (str[9] - '0') * 10 + str[10] - '0';
//////	money += cost[24] * 60 * d + cost[h] * m;
//////	for (int i = 0; i < h; ++i)
//////		money += cost[i] * 60;
//////	time = 24 * 60 * d + h * 60 + m;
//////	return money;
//////}
//////int main()
//////{	
//////	for (int i = 0; i < 24; ++i)
//////	{
//////		cin >> cost[i];
//////		cost[24] += cost[i];
//////	}
//////	cin >> N;
//////	map<string, map<string, string>,less<string>>data;
//////	//外部用名字排序,名字是用降序排序，内部用时间排序,时间时用默认升序排序
//////	for (int i = 0; i < N; ++i)
//////	{
//////		string name, time, type;
//////		cin >> name >> time >> type;
//////		data[name][time] = type;
//////	}
//////	for (auto ptr = data.begin(); ptr != data.end(); ++ptr)
//////	{
//////		int f = 1, st = 0, et = 0;
//////		double s = 0, sum = 0;
//////		string sl,el;
//////		for (auto it = ptr->second.begin(); it != ptr->second.end(); ++it)
//////		{
//////			if (it == ptr->second.begin())	continue;
//////			auto pt = it;
//////			if (it->second == "off-line" && (--pt)->second == "on-line")
//////			{
//////				if (f==1)
//////				{
//////					cout << ptr->first << " " << it->first[0] << it->first[1] << endl;
//////					f = 0;
//////				}
//////				s = calMoney(it->first, et) - calMoney(pt->first, st);
//////				sl.assign(pt->first.begin() + 3, pt->first.end());
//////				el.assign(it->first.begin() + 3, it->first.end());
//////				cout << sl << " " << el << " " << (et - st) << " ";
//////				printf("$%0.2f\n", s/100);
//////				sum += s;
//////			}
//////		}
//////		if(f==0)
//////			printf("Total amount: $%0.2f\n", sum/100);
//////	}
//////	return 0;
//////}
//////
////
////
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <string>
////#include <map>
////using namespace std;
////struct Node
////{
////	string ID;
////	int type, mm, dd, hh, ms, time;
////};
////
////struct  nodeV
////{
////	string ID, type;
////	int mm, time;
////};
////int price[24], n, oneDayFee = 0;
////double cal(Node temp)
////{
////	double fee = price[temp.hh] * temp.ms + oneDayFee * temp.dd * 60;
////	for (int i = 0; i < temp.hh; ++i)
////		fee += price[i] * 60;
////	return fee / 100.00;
////}
////int main()
////{
////	for (int i = 0; i < 24; ++i)
////	{
////		cin >> price[i];
////		oneDayFee += price[i];
////	}
////	cin >> n;
////	vector<Node>v(n);
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> v[i].ID;
////		scanf("%d:%d:%d:%d", &v[i].mm, &v[i].dd, &v[i].hh, &v[i].ms);
////		string temp;
////		cin >> temp;
////		v[i].type = temp == "on-line" ? 1 : 0;
////		v[i].time = v[i].dd * 24 * 60 + v[i].hh * 60 + v[i].ms;
////	}
////	sort(v.begin(), v.end(), [](Node a, Node b) {
////		if (a.ID == b.ID)
////			return a.time < b.time;
////		else
////			return a.ID < b.ID;//切记先名字排在一起
////	});
////	map<string, vector<Node>>res;//一定要用map，因为map会维持字母顺序的
////	for (int i = 1; i < n; ++i)
////	{
////		if (v[i].ID == v[i - 1].ID && v[i].type == 0 && v[i - 1].type == 1)
////		{
////			res[v[i].ID].push_back(v[i - 1]);
////			res[v[i].ID].push_back(v[i]);
////		}
////	}
////	for (auto ptr : res)
////	{
////		vector<Node>temp = ptr.second;
////		cout << ptr.first;
////		printf(" %02d\n", temp[0].mm);
////		double fee = 0.0;
////		for (int i = 1; i < temp.size(); i+=2)
////		{
////			double t = cal(temp[i]) - cal(temp[i - 1]);
////			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].dd, temp[i - 1].hh, temp[i - 1].ms,
////				temp[i].dd, temp[i].hh, temp[i].ms, temp[i].time - temp[i - 1].time, t);
////			fee += t;
////		}
////		printf("Total amount: $%.2f\n", fee);
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
//	int month, time, flag;
//};
//int main()
//{
//	int n, cost[25] = { 0 };
//	for (int i = 1; i <= 24; ++i)
//	{
//		cin >> cost[i];
//		cost[i] += cost[i - 1];
//	}
//	cin >> n;
//	vector<Node>v;
//	for(int i=0;i<n;++i)
//	{
//		string name, flag;
//		int mu, dd, hh, mm;
//		cin >> name;
//		scanf("%d:%d:%d:%d", &mu, &dd, &hh, &mm);
//		cin >> flag;
//		v.push_back({ name,mu,dd * 24 * 60 + hh * 60 + mm,flag == "on-line" ? 1 : 0 });
//	}
//	sort(v.begin(), v.end(), [](Node a, Node b) {
//		if (a.name == b.name)
//			return a.time < b.time;
//		else
//			return a.name < b.name;
//		});
//	double total = 0.0;
//	bool flag = true;
//	for (int i = 0; i < n - 1; ++i)
//	{
//		if (v[i].name == v[i + 1].name)
//		{
//			if (v[i].flag == 1 && v[i + 1].flag == 0)
//			{
//				if (flag)
//				{
//					cout << v[i].name << " ";
//					printf("%02d\n", v[i].month);
//					flag = false;
//				}
//				double money = 0.0;
//				int dd1, dd2, hh1, hh2, mm1, mm2;
//				dd1 = v[i].time / (24 * 60);
//				hh1 = v[i].time % (24 * 60) / 60;
//				mm1 = v[i].time % 60;
//				dd2 = v[i + 1].time / (24 * 60);
//				hh2 = v[i + 1].time % (24 * 60) / 60;
//				mm2 = v[i + 1].time % 60;
//				money = (dd2*cost[24] * 60 + cost[hh2] * 60 + (cost[hh2 + 1] - cost[hh2]) * mm2) -
//					(dd1 * cost[24] * 60 + cost[hh1] * 60 + (cost[hh1 + 1] - cost[hh1]) * mm1);
//				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", dd1, hh1, mm1, dd2, hh2, mm2,
//					v[i + 1].time - v[i].time, money / 100);
//				total += money;
//			}
//			if ((i + 1 == n - 1 || v[i+1].name != v[i + 2].name) && flag==false)
//			{
//				flag = true;
//				printf("Total amount: $%.2f\n", total / 100);
//				total = 0.0;
//			}
//		}
//	}
//	return 0;	
//}
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int month, time, flag;
//};
//int main()
//{
//	int hours[24], oneDay = 0;
//	int n;
//	unordered_map<string, vector<Node>>map;
//	vector<string>names;
//	for (int i = 0; i < 24; ++i)
//	{
//		cin >> hours[i];
//		oneDay += hours[i];
//	}
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		string name, flag;
//		int mon, dd, hh, mm;
//		cin >> name;
//		scanf("%d:%d:%d:%d", &mon, &dd, &hh, &mm);
//		cin >> flag;
//		map[name].push_back({ mon,dd * 24 * 60 + hh * 60 + mm,flag == "on-line" ? 1 : 0 });
//	}
//	for (auto ptr = map.begin(); ptr != map.end(); ++ptr)
//	{
//		sort(ptr->second.begin(), ptr->second.end(), [](Node a, Node b) {return a.time < b.time; });
//		names.push_back(ptr->first);
//	}
//	sort(names.begin(), names.end(), [](string a, string b) {return a < b; });
//	for (auto name : names)
//	{
//		bool flag = true;
//		double totalMoney = 0;
//		vector<Node>v = map[name];
//		for (int i=0;i<v.size()-1;++i)
//		{
//			if (v[i].flag == 1 && v[i+1].flag == 0)
//			{
//				double money1 = 0, money2 = 0;
//				int dd1 = v[i].time / 24 / 60, hh1 = v[i].time % (24 * 60) / 60, mm1 = v[i].time % 60;
//				int dd2 = v[i + 1].time / 24 / 60, hh2 = v[i + 1].time % (24 * 60) / 60, mm2 = v[i + 1].time % 60;
//				money1 += dd1 * oneDay * 60 + hours[hh1] * mm1;
//				money2 += dd2 * oneDay * 60 + hours[hh2] * mm2;
//				for (int j = 0; j < hh1; ++j)
//					money1 += hours[j] * 60;
//				for (int j = 0; j < hh2; ++j)
//					money2 += hours[j] * 60;
//				money2 = money2 - money1;
//				totalMoney = money2;
//				if (flag)
//				{
//					cout << name << " ";
//					printf("%02d\n", v[0].month);
//					flag = false;
//				}
//				printf("%02d:%02d:%02d %02d:%02d:%02d %02d $%.2f\n", dd1, hh1, mm1, dd2, hh2, mm2, v[i + 1].time - v[i].time, money2/100.0);
//			}
//		}
//		if (!flag)
//			printf("Total amount: $%.2f\n", totalMoney/100.0);
//	}
//	return 0;	
//}