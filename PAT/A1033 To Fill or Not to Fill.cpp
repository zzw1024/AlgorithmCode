////#include <iostream>
////#include <algorithm>
////#include <vector>
////using namespace std;
////
//////解题思路：
//////步骤1：把终点视为单位油价为0、离起点距离为D的加油站，然后将所有加油站按离起点的距离从小到大进行排序。排序完毕后，如果离起点最近的加油站的距离不是0，则表示汽车无法出发（初始时刻油量为0），输出“The maximum travel distance = 0.00”；如果离起点最近的加油站的距离是0（即加油站就在起点），则进入步骤2。
//////步骤2：假设当前所处的加油站编号为now，接下来将从满油状态下能到达的所有加油站中选出下一个前往的加油站，策略如下：
//////①寻找距离当前加油站最近的油价低于当前油价的加油站（记为k），加恰好能够到达加油站k的油，然后前往加油站k（即优先前往更低油价的加油站）。
//////②如果找不到油价低于当前油价的加油站，则寻找油价最低的加油站，在当前加油站加满油，然后前往加油站k（即在没有更低油价的加油站时，前往油价尽可能低的加油站）。
//////③如果在满油状态下都找不到能到达的加油站，则最远能到达的距离为当前加油站的距离加上满油状态下能前进的距离，结束算法（即没有加油站可以到达时结束算法）。
//////上面的策略当满足条件③、或者到达加油站n（即终点）时结束。其中①和②的证明如下。策略①的证明：假设三个加油站的顺序为a、b、c（当前在加油站a），且油价大小为a > b（与c的油价大小无关），则先从a加能到达b的油，然后在b加能到达c的油，要比直接从a加能到达c的油要节省（因为a的油价比b高）。因此，在所有能到达的加油站中，总是优先选择最近的油价低于当前油价的加油站。
//////策略②的证明：假设三个加油站的顺序为a、b、c（当前在加油站a），且油价大小为a <
//////	b < c，显然应该先在a加满油（因为b、c油价高），然后前往b、c中油价较低的加油站b（如果一定要去c，也应该是先到油价相对便宜的b，然后去c才更划算（从c出发买油价格高，还不如在b先买好））。
//////
////
////int main()
////{
////
////	int N;
////	double  C, D, Dav, dis, price;
////	cin >> C >> D >> Dav >> N;
////	vector<pair<double, double>>station;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> price >> dis;
////		station.push_back(make_pair(dis, price));
////	}
////	station.push_back(make_pair(D, 0));//将终点也视为一个加油目的地
////	sort(station.begin(), station.end(), [](pair<int, double>a, pair<int, double>b) {return a.first < b.first; });
////	if (station[0].first != 0)//起始点没有加油站
////		printf("The maximum travel distance = 0.00\n");
////	else
////	{
////		int start = 0;//出发点
////		double res = 0.0, nowTank = 0.0;
////		while (start < station.size())
////		{
////			int next = -1;
////			double minPrice = 10000;
////			for (int i = start + 1; i < station.size() && station[i].first - station[start].first <= C * Dav; ++i)//找到下一家最便宜的加油站
////			{
////				if (minPrice > station[i].second)//没有比当前更便宜的加油站，那就找中途最便宜的加油站
////				{
////					minPrice = station[i].second;
////					next = i;
////					if (station[i].second < station[start].second)//找到比当前便宜点的加油站
////						break;
////				}
////	
////			}
////			if (next == -1)//加油站太远，到不到
////				break;
////			double need = (station[next].first - station[start].first) / Dav;//需要耗油量
////			if (minPrice < station[start].second)//比当前油价还便宜，那就不用加满油箱
////			{
////				if (nowTank < need)//油不够
////				{
////					res += station[start].second *(need - nowTank);
////					nowTank = 0;//油刚好到下一站，到达下一站即没有油了
////				}
////				else
////					nowTank -= need;//油还够，那就不用加了
////			}
////			else//中间的加油价比现在的要贵，那就在这里加满
////			{
////				res += station[start].second * (C - nowTank);
////				nowTank = C - need;
////			}
////			start = next;
////		}
////		if (start == N)//到达终点
////			printf("%.2f\n", res);
////		else
////			printf("The maximum travel distance = %.2f\n", station[start].first + C * Dav);
////	}
////	return 0;
////}
//
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	double p, dis;
////};
////int main()
////{
////	int N;
////	double C, D, Da, money = 0.0, passWay = 0.0;
////	cin >> C >> D >> Da >> N;
////	vector<Node>v;
////	for (int i = 0; i < N; ++i)
////	{
////		double p, d;
////		cin >> p >> d;
////		v.push_back({ p,d });
////	}
////	v.push_back({ 0.00,D });//将终点设置为一个加油站，精华
////	sort(v.begin(), v.end(), [](Node a, Node b) {return a.dis < b.dis; });
////	if (v[0].dis > 0)//起点都加不了油
////	{
////		printf("The maximum travel distance = 0.00\n");
////		return 0;
////	}
////	int pot = 0;//目前准备加油的加油站
////	double oil = 0.0;//油箱中的油
////	while (pot < N)//未到终点
////	{
////		int nextPot = -1, flag = 0;
////		double minP = 999999999, maxDis = v[pot].dis + C * Da;//能到达的最远地方
////		for (int i = pot + 1; i <= N && v[i].dis <= maxDis; ++i)//包括终点
////		{
////			if (v[i].p <= v[pot].p)//只要前面的价钱便宜，那么就去前面加油
////			{
////				nextPot = i;
////				passWay = v[nextPot].dis;
////				double needOil = (v[nextPot].dis - v[pot].dis) / Da;
////				money += (needOil - oil)*v[pot].p;
////				oil = 0;//耗尽油去加便宜的油
////				pot = nextPot;
////				flag = 1;
////				break;
////			}
////			if (v[i].p <= minP)//没有低价的，那么就找到最远的最低的加油站去加油
////			{
////				nextPot = i;//因为上面break了，所以不用担心nextPot会替换了
////				minP = v[i].p;
////			}
////		}
////		if (flag == 1)//加了油了
////			continue;
////		if (nextPot == -1)//找不到下一个加油站了
////		{
////			passWay += C * Da;//既然到不到远方，那就加满油，使劲冲
////			break;
////		}
////		if (v[nextPot].p > v[pot].p)//中间的加油站很贵，但你不得不加，那么就在现在便宜的加油站加满了
////		{
////			passWay = v[nextPot].dis;
////			money += (C - oil)*v[pot].p;//加满油箱			
////			oil = C - (v[nextPot].dis - v[pot].dis) / Da;//剩余油量
////			pot = nextPot;
////		}
////	}
////	if (pot == N)
////		printf("%.2f\n", money);
////	else
////		printf("The maximum travel distance = %.2f\n", passWay);
////	return 0;
////}
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct  Node
//{
//	double p, d;
//};
//int main()
//{
//	int n;
//	double tank, dis, avg;
//	cin >> tank >> dis >> avg >> n;
//	vector<Node>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i].p >> v[i].d;
//	v.push_back({ 0.00,dis });//把终点当成最后一个加油站
//	sort(v.begin(), v.end(), [](Node a, Node b) {return a.d < b.d; });
//	if (v[0].d != 0)//没有起点加油
//	{
//		printf("The maximum travel distance = 0.00\n");
//		return 0;
//	}
//	int pot = 0;
//	double money = 0.0, lastOil = 0.00;
//	while (pot != n)//没有到终点
//	{
//		int nextPot = -1, flag = 0;
//		double minP = 99999999, maxDis = v[pot].d + tank * avg;
//		for (int i = pot + 1; i <= n && v[i].d <= maxDis; ++i)
//		{
//			if (v[i].p <= v[pot].p)//一旦有更便宜的价格，就立即前往
//			{
//				double needOil = (v[i].d - v[pot].d) / avg;
//				money += (needOil - lastOil) * v[pot].p;
//				lastOil = 0;//油量就刚好够到加油站
//				pot = i;
//				flag = 1;
//				break;
//			}
//			if (minP >= v[i].p)//没有更便宜的，那就找越远但相对中途所有加油站来讲是最便宜的
//			{
//				minP = v[i].p;
//				nextPot = i;
//			}
//		}
//		if (flag == 1)//计算过
//			continue;
//		if (nextPot == -1)//没有加油站了
//		{
//			printf("The maximum travel distance = %0.2f\n", v[pot].d + tank * avg);//加满油向前冲
//			break;
//		}
//		//由于现在的加油站是比pot贵的加油站，那么我们就在pot加满油
//		double needOil = (v[nextPot].d - v[pot].d) / avg;
//		money += (tank - lastOil) * v[pot].p;//加满
//		lastOil = tank - needOil;//到达nextPot的剩余油量
//		pot = nextPot;
//	}
//	if (pot == n)
//		printf("%.2f\n", money);
//	return 0;
//}
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	double price, dis;
//};
//double C, Dis, Avg;
//int N;
//vector<Node>v;
//int main()
//{
//	cin >> C >> Dis >> Avg >> N;
//	for (int i = 0; i < N; ++i)
//	{
//		double p, d;
//		cin >> p >> d;
//		v.push_back({ p,d });
//	}
//	v.push_back({0.0,Dis });
//	sort(v.begin(), v.end(), [](Node a, Node b) {if (a.dis == b.dis)return a.price < b.price; else  return a.dis < b.dis; });
//	int index = 0;
//	double tank = 0.0, resMoney = 0.0;
//	while (index<v.size())
//	{
//		int u = -1;
//		double minPrice = INT32_MAX;
//		for (int i = index + 1; i < v.size() && (v[i].dis-v[index].dis) <= C * Avg; ++i)
//		{
//			if (v[i].price < v[index].price)//找到便宜一点的下一个站
//			{
//				u = i;
//				break;
//			}
//			if (v[i].price < minPrice)//都很贵的话就找其中最便宜的
//			{
//				minPrice = v[i].price;
//				u = i;
//			}
//		}
//		if (u == -1)break;
//		if (v[u].price < v[index].price)//下一站的油价比我现在的还要便宜，那就去下一站加
//		{
//			resMoney += v[index].price*((v[u].dis - v[index].dis) / Avg - tank);
//			tank = 0;
//		}
//		else//现在的油价最便宜
//		{
//			resMoney += (C - tank) * v[index].price;
//			tank = C - (v[u].dis - v[index].dis) / Avg;
//		}	
//		index = u;
//	}
//	if (index == v.size() - 1)
//		printf("%0.2f", resMoney);
//	else
//		printf("The maximum travel distance = %0.2f", v[index].dis + C * Avg);
//	return 0;
//}
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	double cap, dis, km;
//	int n;
//	cin >> cap >> dis >> km >> n;
//	vector <pair<double, double>>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i].second >> v[i].first;
//	v.push_back(make_pair(dis, 0.0));
//	sort(v.begin(), v.end(), [](pair<double, double>a, pair<double, double>b) {return a.first < b.first; });
//	if (v[0].first != 0)return 0;
//	int index = 0;
//	double tank = 0.0, money = 0.0;
//	while (index < n + 1)
//	{
//		double minPirce = INT32_MAX;
//		int nextI = -1;
//		for (int i = index + 1; i < n + 1 && (v[i].first - v[index].first) <= cap * km; ++i)
//		{//找下一家
//			if (v[i].second <= v[index].second)//有更便宜的
//			{
//				nextI = i;
//				break;
//			}
//			if (minPirce > v[i].second)//没有更便宜的，就找最便宜的
//			{
//				nextI = i;
//				minPirce = v[i].second;
//			}
//		}
//		if (nextI == -1)break;
//		double needOil = (v[nextI].first - v[index].first) / km;
//		if (v[nextI].second <= v[index].second)
//		{
//			money += v[index].second * (needOil - tank);
//			tank = 0;
//		}
//		else
//		{
//			money += v[index].second *(cap - tank);
//			tank = cap - needOil;			
//		}
//		index = nextI;
//	}
//	if (v[index].first != dis)
//		printf("The maximum travel distance = %.2f", v[index].first + cap * km);
//	else
//		printf("%.2f", money);
//	return 0;
//}