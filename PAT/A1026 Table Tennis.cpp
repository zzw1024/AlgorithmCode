//////#include <iostream>
//////#include <vector>
//////#include <algorithm>
//////#include<cmath>
//////using namespace std;
//////struct Node
//////{
//////	int arrTime, serTime, playTime, popTime = 8 * 3600, Vip;//全部换算成秒
//////};
//////vector<Node>person, tables;
//////vector<int>times;
//////int findVip(int vipId)
//////{
//////	vipId++;
//////	while (vipId < person.size() && times[vipId] < 10000)vipId++;
//////	return vipId;
//////}
//////
//////void alloctable(int i, int index)
//////{
//////	if (person[i].arrTime <= tables[index].popTime)
//////		person[i].serTime = tables[index].popTime;
//////	else
//////		person[i].serTime = person[i].arrTime;
//////	tables[index].popTime = person[i].serTime + person[i].playTime;
//////	times[index]++;
//////}
//////
//////int main()
//////{
//////	int N, K, M;
//////	cin >> N;	
//////	for (int i = 0; i < N; ++i)
//////	{
//////		Node node;
//////		int h, m, s, p;
//////		scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &node.Vip);
//////		node.arrTime = h * 3600 + m * 60 + s;
//////		node.playTime = p > 2 * 60 ? 2 * 60 * 60 : p * 60;//最多两个小时
//////		if (node.arrTime > 21 * 3600)continue;//去除下班来的人
//////		person.push_back(node);
//////	}
//////	sort(person.begin(), person.end(), [](Node a, Node b) {return a.arrTime < b.arrTime; });
//////	cin >> K >> M;//C为VIP桌号
//////	tables.resize(K + 1);
//////	times.resize(K + 1);
//////	for (int i = 0,j; i < M; ++i)
//////	{
//////		cin >> j;
//////		times[j] = 10000;//100为vip标记
//////	}
//////	int i = 0, vipId = findVip(-1);
//////	while (i < person.size())
//////	{
//////		int index = -1, minTime = 999999999;
//////		for (int j = 1; j <= K; ++K)
//////		{
//////			if (tables[i].popTime < minTime)
//////			{
//////				index = i;
//////				minTime = tables[i].popTime;
//////			}
//////		}
//////		if (minTime >= 21 * 3600)break;//下班了
//////		if (person[i].Vip == 1 && i< vipId)//人是vip,但桌不是，那就这个人等着
//////		{
//////			i++;
//////			continue;
//////		}
//////		if (times[index] >= 10000)
//////		{
//////			if (person[i].Vip == 1)
//////			{
//////				alloctable(i, index);
//////				if (vipId == i)
//////					vipId = findVip(vipId);
//////				++i;
//////			}
//////			else
//////			{
//////				if (vipId < person.size() && person[vipId].arrTime <= tables[index].popTime)
//////				{
//////					alloctable(vipId, index);
//////					vipId = findVip(vipId);
//////				}
//////				else
//////				{
//////					alloctable(i, index);
//////					++i;
//////				}				
//////			}
//////		}
//////		else
//////		{
//////			if (person[i].Vip == 0)
//////			{
//////				alloctable(i, index);
//////				++i;
//////			}
//////			else
//////			{
//////				int vipIndex = -1, minVipTime = 999999999;
//////				for (int j = 1; j <= K; ++j)
//////				{
//////					if (times[j] >= 10000 && tables[j].popTime < minVipTime)
//////					{
//////						vipIndex = j;
//////						minVipTime = tables[j].popTime;
//////					}
//////				}
//////				if (vipIndex != -1 && person[i].arrTime >= tables[vipIndex].popTime)
//////				{
//////					alloctable(i, vipIndex);
//////					if (vipId == i)
//////						vipId = findVip(vipId);
//////					++i;
//////				}
//////				else
//////				{
//////					alloctable(i, index);
//////					if (vipId == i)
//////						vipId = findVip(vipId);
//////					++i;
//////				}
//////			}
//////		}
//////	}
//////	sort(person.begin(), person.end(), [](Node a, Node b) {return a.serTime < b.serTime; });
//////	for (i = 0; i < person.size() && person[i].serTime < 21 * 3600; ++i)
//////	{
//////		printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",
//////			person[i].arrTime / 3600, person[i].arrTime % 3600 / 60, person[i].arrTime % 60,
//////			person[i].serTime / 3600, person[i].serTime % 3600 / 60, person[i].serTime % 60,
//////			round(person[i].serTime - person[i].arrTime) / 60.0);
//////	}
//////	for (int i = 1; i <= K; ++i)
//////	{
//////		if (i != 1)printf(" ");
//////		printf("%d", times[i] > 10000 ? times[i] - 10000 : times[i]);
//////	}
//////	return 0;
//////}
////
//////
//////#include <iostream>
//////#include <vector>
//////#include <algorithm>
//////#include <cmath>
//////using namespace std;
//////struct person {
//////	int arrive, start, time;
//////	bool vip;
//////}tempperson;
//////struct tablenode {
//////	int end = 8 * 3600, num;
//////	bool vip;
//////};
//////bool cmp1(person a, person b) {
//////	return a.arrive < b.arrive;
//////}
//////bool cmp2(person a, person b) {
//////	return a.start < b.start;
//////}
//////vector<person> player;
//////vector<tablenode> table;
//////void alloctable(int personid, int tableid) {
//////	if (player[personid].arrive <= table[tableid].end)
//////		player[personid].start = table[tableid].end;
//////	else
//////		player[personid].start = player[personid].arrive;
//////	table[tableid].end = player[personid].start + player[personid].time;
//////	table[tableid].num++;
//////}
//////int findnextvip(int vipid) {
//////	vipid++;
//////	while (vipid < player.size() && player[vipid].vip == false) vipid++;
//////	return vipid;
//////}
//////int main() {
//////	int n, k, m, viptable;
//////	scanf("%d", &n);
//////	for (int i = 0; i < n; i++) {
//////		int h, m, s, temptime, flag;
//////		scanf("%d:%d:%d %d %d", &h, &m, &s, &temptime, &flag);
//////		tempperson.arrive = h * 3600 + m * 60 + s;
//////		tempperson.start = 21 * 3600;
//////		if (tempperson.arrive >= 21 * 3600) continue;
//////		tempperson.time = temptime <= 120 ? temptime * 60 : 7200;
//////		tempperson.vip = ((flag == 1) ? true : false);
//////		player.push_back(tempperson);
//////	}
//////	scanf("%d%d", &k, &m);
//////	table.resize(k + 1);
//////	for (int i = 0; i < m; i++) {
//////		scanf("%d", &viptable);
//////		table[viptable].vip = true;
//////	}
//////	sort(player.begin(), player.end(), cmp1);
//////	int i = 0, vipid = -1;
//////	vipid = findnextvip(vipid);
//////	while (i < player.size()) {
//////		int index = -1, minendtime = 999999999;
//////		for (int j = 1; j <= k; j++) {
//////			if (table[j].end < minendtime) {
//////				minendtime = table[j].end;
//////				index = j;
//////			}
//////		}
//////		if (table[index].end >= 21 * 3600) break;
//////		if (player[i].vip == true && i < vipid) {
//////			i++;
//////			continue;
//////		}
//////		if (table[index].vip == true) {
//////			if (player[i].vip == true) {
//////				alloctable(i, index);
//////				if (vipid == i) vipid = findnextvip(vipid);
//////				i++;
//////			}
//////			else {
//////				if (vipid < player.size() && player[vipid].arrive <= table[index].end) {
//////					alloctable(vipid, index);
//////					vipid = findnextvip(vipid);
//////				}
//////				else {
//////					alloctable(i, index);
//////					i++;
//////				}
//////			}
//////		}
//////		else {
//////			if (player[i].vip == false) {
//////				alloctable(i, index);
//////				i++;
//////			}
//////			else {
//////				int vipindex = -1, minvipendtime = 999999999;
//////				for (int j = 1; j <= k; j++) {
//////					if (table[j].vip == true && table[j].end < minvipendtime) {
//////						minvipendtime = table[j].end;
//////						vipindex = j;
//////					}
//////				}
//////				if (vipindex != -1 && player[i].arrive >= table[vipindex].end) {
//////					alloctable(i, vipindex);
//////					if (vipid == i) vipid = findnextvip(vipid);
//////					i++;
//////				}
//////				else {
//////					alloctable(i, index);
//////					if (vipid == i) vipid = findnextvip(vipid);
//////					i++;
//////				}
//////			}
//////		}
//////	}
//////	sort(player.begin(), player.end(), cmp2);
//////	for (i = 0; i < player.size() && player[i].start < 21 * 3600; i++) {
//////		printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
//////		printf("%02d:%02d:%02d ", player[i].start / 3600, player[i].start % 3600 / 60, player[i].start % 60);
//////		printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
//////	}
//////	for (int i = 1; i <= k; i++) {
//////		if (i != 1) printf(" ");
//////		printf("%d", table[i].num);
//////	}
//////	return 0;
//////}
////
//////#include <iostream>
//////#include <vector>
//////#include <algorithm>
//////using namespace std;
//////int n, k, m;
//////struct Node
//////{
//////	int arriveTime = 0, serveTime = 0, isVip = 0;
//////};
//////void swapVip(vector<Node> &persons, int u, int v)
//////{
//////	Node node = persons[u];
//////	persons[u] = persons[v];
//////	persons[v] = node;
//////}
//////int main()
//////{
//////	cin >> n;
//////	vector<Node>persons;
//////	for (int i = 0; i < n; ++i)
//////	{
//////		int hh, mm, ss, p, f;
//////		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p, &f);
//////		Node node;
//////		node.arriveTime = hh * 3600 + mm * 60 + ss;
//////		node.serveTime = p > 120 ? 120 * 60 : p * 60;//玩耍时间压缩为2个小时
//////		node.isVip = f;
//////		persons.push_back(node/*{ hh * 3600 + mm * 60 + ss,p * 60,f }*/);
//////	}
//////	sort(persons.begin(), persons.end(), [](Node a, Node b) {return a.arriveTime < b.arriveTime; });
//////	cin >> k >> m;
//////	vector<bool>isVip(k + 1, false), isServe(n, false);//没有0
//////	while (m--)
//////	{
//////		int a;
//////		cin >> a;
//////		isVip[a] = true;
//////	}
//////	vector<vector<int>>windows(k+1);//没有0号桌
//////	for (int i = 0; i <= k; ++i)
//////		windows[i].push_back(0);//给每张桌子的排队时间清为0
//////	vector<int>res(k + 1, 0);//每张桌子使用过的人数
//////	int num = 0;
//////	for (int i = 0; i < n; ++i)
//////	{
//////		int Index = 0, minTime = INT32_MAX;
//////		vector<int>ordV, vipV;
//////		for (int j = 1; j <= k; ++j)
//////		{
//////			if (windows[j].back() < minTime)
//////			{
//////				Index = j;
//////				minTime = windows[j].back();
//////			}			
//////			if (persons[i].arriveTime >= windows[j].back())//此时这张桌子子是空的
//////				ordV.push_back(j);
//////			if (isVip[j] == true && persons[i].arriveTime >= windows[j].back())//vip桌子是空
//////				vipV.push_back(j);
//////		}
//////		if (persons[i].isVip == 1 && vipV.size() > 0)//是vip且有vip桌子是空的
//////		{//之所以因为有空桌子，是因为到达时，没有人占桌子，那么你可以直接上
//////			windows[vipV[0]].push_back(persons[i].arriveTime + persons[i].serveTime);
//////			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
//////				persons[i].arriveTime / 3600, persons[i].arriveTime % 3600 / 60, persons[i].arriveTime % 60,
//////				persons[i].arriveTime / 3600, persons[i].arriveTime % 3600 / 60, persons[i].arriveTime % 60, 0);
//////			res[vipV[0]]++;
//////		}
//////		else if (ordV.size() > 0)//没有vip空桌子，那么就使用普通空桌子
//////		{//之所以因为有空桌子，是因为到达时，没有人占桌子，那么你可以直接上
//////			windows[ordV[0]].push_back(persons[i].arriveTime + persons[i].serveTime);
//////			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
//////				persons[i].arriveTime / 3600, persons[i].arriveTime % 3600 / 60, persons[i].arriveTime % 60,
//////				persons[i].arriveTime / 3600, persons[i].arriveTime % 3600 / 60, persons[i].arriveTime % 60, 0);
//////			res[ordV[0]]++;
//////		}
//////		else//所有桌子都满了，那就慢慢排队
//////		{//之所以桌子满了是因为你到的时间太早了，那么你的服务时间就是被人玩完了的时间
//////			if (windows[Index].back() >= 21 * 3600)
//////				break;//关门了，后面的人拉到把
//////			//最难处，找出vip来插队
//////			if (isVip[Index] == true)//这张桌子是vip桌子，允许vip插队
//////			{
//////				for (int t = i; t < n && persons[t].arriveTime <= windows[Index].back(); ++t)//在Index桌子空出来的之前的排队人中找出Vip来插队
//////				{
//////					if (persons[t].isVip == 1)//是Vip
//////					{
//////						swapVip(persons, i, t);//Vip插队
//////						break;
//////					}
//////				}
//////			}
//////			double waitTime = (double)(windows[Index].back()) - (double)(persons[i].arriveTime);
//////			printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",
//////				persons[i].arriveTime / 3600, persons[i].arriveTime % 3600 / 60, persons[i].arriveTime % 60,
//////				windows[Index].back() / 3600, windows[Index].back() % 3600 / 60, windows[Index].back() % 60,
//////				waitTime / 60 + 0.05);
//////			windows[Index].push_back(windows[Index].back() + persons[i].serveTime);			
//////			res[Index]++;
//////		}
//////	}
//////	for (int i = 1; i <= k; ++i)
//////		cout << (i == 1 ? "" : " ") << res[i];
//////	return 0;
//////}
//
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int n, k, m;
////struct Node
////{
////	int arriveTime = 0, palyTime = 0, severTime = 0, isVip = 0;
////	double waitTime = 0.0;
////};
////void swapVip(vector<Node> &persons, int u, int v)
////{
////	Node node = persons[u];
////	persons[u] = persons[v];
////	persons[v] = node;
////}
////int main()
////{
////	cin >> n;
////	vector<Node>persons, sortList;
////	for (int i = 0; i < n; ++i)
////	{
////		int hh, mm, ss, p, f;
////		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p, &f);
////		if (hh * 3600 + mm * 60 + ss >= 21 * 3600)//不要忘了这一步
////			continue;
////		Node node;
////		node.arriveTime = hh * 3600 + mm * 60 + ss;
////		node.palyTime = p > 120 ? 120 * 60 : p * 60;//玩耍时间压缩为2个小时
////		node.isVip = f;
////		node.severTime = 0;
////		node.waitTime = 0.00;
////		persons.push_back(node);
////	}
////	sort(persons.begin(), persons.end(), [](Node a, Node b) {return a.arriveTime < b.arriveTime; });
////	cin >> k >> m;
////	vector<bool>isVip(k + 1, false), isServe(n, false);//没有0
////	while (m--)
////	{
////		int a;
////		cin >> a;
////		isVip[a] = true;
////	}
////	vector<vector<int>>windows(k + 1);//没有0号桌
////	for (int i = 0; i <= k; ++i)
////		windows[i].push_back(0);//给每张桌子的排队时间清为0
////	vector<int>res(k + 1, 0);//每张桌子使用过的人数
////	for (int i = 0; i < persons.size(); ++i)
////	{
////		int Index = 0, minTime = INT32_MAX;
////		vector<int>ordV, vipV;
////		for (int j = 1; j <= k; ++j)
////		{
////			if (windows[j].back() < minTime)
////			{
////				Index = j;
////				minTime = windows[j].back();
////			}
////			if (persons[i].arriveTime >= windows[j].back())//此时这张桌子子是空的
////				ordV.push_back(j);
////			if (isVip[j] == true && persons[i].arriveTime >= windows[j].back())//vip桌子是空
////				vipV.push_back(j);
////		}
////		if (persons[i].isVip == 1 && vipV.size() > 0)//是vip且有vip桌子是空的
////		{//之所以因为有空桌子，是因为到达时，没有人占桌子，那么你可以直接上
////			windows[vipV[0]].push_back(persons[i].arriveTime + persons[i].palyTime);
////			persons[i].severTime = persons[i].arriveTime;
////			persons[i].waitTime = 0.00;
////			sortList.push_back(persons[i]);
////			res[vipV[0]]++;
////		}
////		else if (ordV.size() > 0)//没有vip空桌子，那么就使用普通空桌子
////		{//之所以因为有空桌子，是因为到达时，没有人占桌子，那么你可以直接上
////			windows[ordV[0]].push_back(persons[i].arriveTime + persons[i].palyTime);
////			persons[i].severTime = persons[i].arriveTime;
////			persons[i].waitTime = 0.00;
////			sortList.push_back(persons[i]);
////			res[ordV[0]]++;
////		}
////		else//所有桌子都满了，那就慢慢排队
////		{//之所以桌子满了是因为你到的时间太早了，那么你的服务时间就是被人玩完了的时间
////			if (windows[Index].back() >= 21 * 3600)
////				break;//关门了，后面的人拉到把
////			//最难处，找出vip来插队
////			if (isVip[Index] == true)//这张桌子是vip桌子，允许vip插队
////			{
////				for (int t = i; t < n && persons[t].arriveTime <= windows[Index].back(); ++t)//在Index桌子空出来的之前的排队人中找出Vip来插队
////				{
////					if (persons[t].isVip == 1)//是Vip
////					{
////						swapVip(persons, i, t);//Vip插队
////						break;
////					}
////				}
////			}
////			double waitTime = (double)(windows[Index].back()) - (double)(persons[i].arriveTime);
////			persons[i].severTime = windows[Index].back();
////			persons[i].waitTime = waitTime;
////			sortList.push_back(persons[i]);
////			windows[Index].push_back(windows[Index].back() + persons[i].palyTime);
////			res[Index]++;
////		}
////	}
////	sort(sortList.begin(), sortList.end(), [](Node a, Node b) {
////		if (a.severTime == b.severTime)
////			return a.isVip > b.isVip;
////		else
////			return a.severTime < b.severTime;			
////	});
////	for (auto v : sortList)
////	{
////		printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",
////			v.arriveTime / 3600, v.arriveTime % 3600 / 60, v.arriveTime % 60,
////			v.severTime / 3600, v.severTime % 3600 / 60, v.severTime % 60,
////			v.waitTime / 60 + 0.05);
////	}
////	for (int i = 1; i <= k; ++i)
////		cout << (i == 1 ? "" : " ") << res[i];
////	return 0;
////}
////*****************************
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////struct Node
////{
////	int arrTime, palyTime, serTime, flag;
////};
////int n, m, k;
////vector<Node>v;
////int main()
////{
////	cin >> n;
////	for(int i=0;i<n;++i)
////	{ 
////		int hh, mm, ss, tt, ff;
////		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &tt, &ff);
////		if (hh * 3600 + mm * 60 + ss < 21 * 3600)
////			v.push_back({ hh * 3600 + mm * 60 + ss,tt > 2 * 60 ? 2 * 3600 : tt * 60,0 ,ff });
////	}
////	cin >> m >> k;
////	vector<bool>isVipTable(m + 1, false);
////	vector<vector<int>>window(m + 1);
////	for (int i = 0; i <= m; ++i)
////		window[i].push_back(8 * 3600);	
////	while (k--)
////	{
////		int a;
////		cin >> a;
////		isVipTable[a] = true;
////	}
////	sort(v.begin(), v.end(), [](Node a, Node b) {return a.arrTime < b.arrTime; });
////	int index = 0, preIndex = 0;
////	while (index < v.size())
////	{
////		if (v[index].serTime > 0)//后面的vip提前使用了
////		{
////			++index;
////			continue;
////		}
////		int u = 0, minTime = 24 * 3600;
////		for (int i = 1; i <= m; ++i)//找空闲窗口
////		{
////			if (window[i].back() <= v[index].arrTime)//最先使用小号的桌子
////			{
////				u = i;
////				break;
////			}
////			else if (window[i].back() < minTime)
////			{
////				minTime = window[i].back();
////				u = i;
////			}
////		}
////		if (window[u].back() >= 21 * 3600)
////			break;
////		if (isVipTable[u] == true)//是Vip桌
////		{
////			for (int i = index; v[i].arrTime <= window[u].back() && i < n; ++i)//一定是找在排队中的VIP
////			{
////				if (v[i].flag == 1 && v[i].serTime == 0)//是vip，且没有服务过
////				{
////					preIndex = index;
////					index = i;//把vip前提
////					break;
////				}
////			}
////		}
////		if (v[index].arrTime > window[u].back())//来的很晚
////		{
////			window[u].push_back(v[index].arrTime + v[index].palyTime);
////			v[index].serTime = v[index].arrTime;
////		}
////		else//来早了
////		{
////			v[index].serTime = window[u].back();
////			window[u].push_back(window[u].back() + v[index].palyTime);
////		}
////		if (v[index].flag == 1)//是vip，那么他提前了，所以不能按顺序
////			index = preIndex;
////		else
////			++index;
////	}
////	sort(v.begin(), v.end(), [](Node a, Node b) {if (a.serTime != b.serTime)return a.serTime < b.serTime; else return a.flag > b.flag; });
////	for (int i = 0; i < v.size(); ++i)
////	{
////		double res = (v[i].serTime - v[i].arrTime + 30) / 60;
////		if (v[i].serTime > 0)
////			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
////				v[i].arrTime / 3600, v[i].arrTime % 3600 / 60, v[i].arrTime % 60,
////				v[i].serTime / 3600, v[i].serTime % 3600 / 60, v[i].serTime % 60,(int)res);
////	}
////	for (int i = 1; i <= m; ++i)
////		cout << window[i].size() - 1 << (i == m ? "" : " ");
////	return 0;
////}
////
////
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n, m, k;
//struct Node
//{
//	int arrTime, palyTime, serTime, flag;
//};
//vector<Node>v;
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		int hh, mm, ss, tt, ff;
//		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &tt, &ff);
//		hh = hh * 3600 + mm * 60 + ss;
//		if (hh < 21 * 3600)
//			v.push_back({ hh,tt > 2 * 60 ? 2 * 3600 : tt * 60,0,ff });
//	}
//	cin >> m >> k;
//	vector<bool>isVip(m + 1, false);
//	vector<vector<int>>windows(m + 1);
//	for (int i = 0; i < m + 1; ++i)
//		windows[i].push_back(8 * 3600);
//	for (int i = 0; i < k; ++i)
//	{
//		int a;
//		cin >> a;
//		isVip[a] = true;
//	}
//	sort(v.begin(), v.end(), [](Node a, Node b) {return a.arrTime < b.arrTime; });
//	int index = 0, preIndex = 0;
//	while (index < v.size())
//	{
//		if (v[index].serTime > 0)//已经提前插队过了
//		{
//			++index;
//			continue;
//		}
//		preIndex = index;
//		int u = 1, minTime = windows[1].back();
//		for (int i = 1; i <= m; ++i)//找空桌子
//		{
//			if (windows[i].back() <= v[index].arrTime)//是空闲的，那就从小号开始用
//			{
//				u = i;
//				break;
//			}
//			else if (windows[i].back() < minTime)//不是空闲的，那就找最早空闲的
//			{
//				u = i;
//				minTime = windows[i].back();
//			}
//		}
//		if (v[index].flag == 1 && isVip[u]==false)//是VIP,那就先看看VIP桌是不是空的
//		{
//			for (int i = 1; i <= m; ++i)
//			{
//				if (isVip[i] == true && windows[i].back() <= v[index].arrTime)//是vip桌，而且是空闲的
//				{
//					u = i;
//					break;
//				}
//			}
//		}
//		if (windows[u].back() >= 21 * 3600)//太晚了，下班
//			break;
//		if (isVip[u] == true && v[index].flag==0 && v[index].arrTime < windows[u].back())//如果是vip桌，且处于排队状态，那就得从排队中找出vip来插队
//		{
//			for (int i = index; v[i].arrTime < windows[u].back() && i < v.size(); ++i)//一定的是处于排队的人中挑vip
//			{
//				if (v[i].flag == 1)
//				{
//					index = i;//插队
//					break;
//				}
//			}
//		}
//		if (v[index].arrTime > windows[u].back())//来的很晚
//		{
//			windows[u].push_back(v[index].arrTime + v[index].palyTime);
//			v[index].serTime = v[index].arrTime;
//		}
//		else//来早了
//		{
//			v[index].serTime = windows[u].back();
//			windows[u].push_back(windows[u].back() + v[index].palyTime);
//		}
//		if (v[index].flag == 1)//是vip，那么他提前了，所以按原来的顺序
//			index = preIndex;
//		else
//			++index;
//	}
//	sort(v.begin(), v.end(), [](Node a, Node b) {if (a.serTime != b.serTime)return a.serTime < b.serTime; else return a.flag > b.flag; });
//	for (int i = 0; i < v.size(); ++i)
//	{
//		double res = (v[i].serTime - v[i].arrTime + 30) / 60;
//		if (v[i].serTime > 0)
//			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
//				v[i].arrTime / 3600, v[i].arrTime % 3600 / 60, v[i].arrTime % 60,
//				v[i].serTime / 3600, v[i].serTime % 3600 / 60, v[i].serTime % 60, (int)res);
//	}
//	for (int i = 1; i <= m; ++i)
//		cout << windows[i].size() - 1 << (i == m ? "" : " ");
//	return 0;
//}