////#include <iostream>
////#include <algorithm>
////using namespace std;
////struct Result {
////	int id = 0, score[6] = { -2,-2,-2,-2,-2,-2 }, rank = 1, num = 0, totalScore = 0;//id、每题分数、排名、满分的题目个数、总分
////	bool flag = false;//标志是否有通过编译的代码，即是否要进行输出
////};
////bool cmp(const Result&r1, const Result&r2) {//比较函数
////	if (r1.totalScore != r2.totalScore)
////		return r1.totalScore > r2.totalScore;
////	else if (r1.num != r2.num)
////		return r1.num > r2.num;
////	else
////		return r1.id < r2.id;
////}
////Result m[(int)(1e5 + 5)];//Result的数组
////int main() {
////	int N, K, M;
////	scanf("%d%d%d", &N, &K, &M);
////	int *P = new int[K + 1];//存储每题的满分
////	for (int i = 1; i <= K; ++i)
////		scanf("%d", &P[i]);
////	while (M--) {
////		int a, b, c;
////		scanf("%d%d%d", &a, &b, &c);
////		m[a].id = a;
////		if (c > -1)//有通过编译的代码
////			m[a].flag = true;//置flag为true
////		else if (c == -1)//不能通过编译
////			c = 0;//置得分为0
////		m[a].score[b] = max(m[a].score[b], c);//更新该题得分为最高分
////	}
////	for (int i = 1; i <= N; ++i)//遍历数组result
////		if (m[i].flag)//需要进行输出
////			for (int j = 1; j <= K; ++j) {//遍历考试的所有题目
////				if (m[i].score[j] == P[j])//有拿满分的题目
////					++m[i].num;//递增满分题目数
////				m[i].totalScore += m[i].score[j] < 0 ? 0 : m[i].score[j];//更新总分
////			}
////	sort(m + 1, m + N + 1, cmp);//排序
////	for (int i = 2; i <= N; ++i)//得出排名
////		m[i].rank = m[i].totalScore != m[i - 1].totalScore ? i : m[i - 1].rank;
////	for (int i = 1; i <= N; ++i)//遍历数组result
////		if (m[i].flag) {//输出
////			printf("%d %05d %d", m[i].rank, m[i].id, m[i].totalScore);
////			for (int j = 1; j <= K; ++j)
////				if (m[i].score[j] < 0)//该题没有通过编译或没有提交
////					printf(" -");//输出-
////				else
////					printf(" %d", m[i].score[j]);
////			printf("\n");
////		}
////	return 0;
////}
//
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//struct Node
//{
//	int id, score[6], rank, total, solve;
//	bool flag;
//};
//int main()
//{
//	int n, k, m, score[6];
//	cin >> n >> k >> m;
//	for (int i = 1; i <= k; ++i)
//		cin >> score[i];
//	unordered_map<int, Node>map;
//	vector<Node>res;
//	while (m--)
//	{
//		int id, index, s;
//		cin >> id >> index >> s;
//		if (map.find(id) == map.end())
//		{
//			map[id].id = id;
//			map[id].rank = 1;
//			map[id].total = 0;
//			map[id].solve = 0;
//			map[id].flag = false;
//			fill(map[id].score, map[id].score + 6, -1);
//		}
//		if (s >= map[id].score[index])
//			map[id].score[index] = s == -1 ? 0 : s;
//		if (s > -1)
//			map[id].flag = true;
//	}
//	for (auto ptr = map.begin(); ptr != map.end(); ++ptr)
//	{
//		if (ptr->second.flag == false)continue;
//		for(int i=1;i<=k;++i)
//			if (ptr->second.score[i] > -1)
//			{			
//				ptr->second.total += ptr->second.score[i];
//				if (ptr->second.score[i] == score[i])
//					ptr->second.solve++;
//			}
//		res.push_back(ptr->second);
//	}
//	sort(res.begin(), res.end(), [](Node a, Node b) {
//		if (a.total == b.total && a.solve == b.solve)
//			return a.id < b.id;
//		else if (a.total == b.total)
//			return a.solve > b.solve;
//		else
//			return a.total > b.total;
//	});
//	for (int i = 0; i < res.size(); ++i)
//	{
//		if (i > 0 && res[i].total == res[i - 1].total)
//			res[i].rank = res[i - 1].rank;
//		else
//			res[i].rank = i + 1;
//		printf("%d %05d %d", res[i].rank, res[i].id, res[i].total);
//		for (int j = 1; j <= k; ++j)
//		{
//			cout << " ";
//			res[i].score[j] == -1 ? (cout << "-") : (cout << res[i].score[j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}