////#include <iostream>
////#include <vector>
////#include <string>
////#include <algorithm>
////using namespace std;
////vector<int>graph[10005];//ͼ
////bool boy[10005];//�±�ΪID��Ԫ�ر�ʾ��ID�Ƿ�����
////int N, M, K, vstart, vend;
////int main() 
////{
////	scanf("%d%d", &N, &M);
////	for (int i = 0; i < M; ++i) 
////	{//��ȡ�ߵ�����
////		string a, b;
////		cin >> a >> b;
////		int ia = abs(stoi(a)), ib = abs(stoi(b));//���ַ�����Ϊ������
////		graph[ia].push_back(ib);//��ͼ�м����
////		graph[ib].push_back(ia);//��ͼ�м����
////		boy[ia] = (a[0] != '-');//��ʾ�����Ա�
////		boy[ib] = (b[0] != '-');//��ʾ�����Ա�
////	}
////	scanf("%d", &K);
////	while (K--)
////	{
////		scanf("%d%d", &vstart, &vend);//��ȡ��β���
////		vector<pair<int, int>>result;//�洢������ĿҪ����������
////		for (int i : graph[abs(vstart)])//�����׽ڵ������
////			if (i != abs(vend) && i != abs(vstart) && boy[i] == boy[abs(vstart)])//�ҵ�����β��������׽ڵ��Ա���ͬ��������Ϊ��һ���ڵ�
////				for (int j : graph[i])//������һ���ڵ������
////					if (j != abs(vend) && j != abs(vstart) && boy[j] == boy[abs(vend)])//�ҵ�����β�������β�ڵ��Ա���ͬ��������Ϊ�ڶ����ڵ�
////						for (int k : graph[j])//�����ڶ����ڵ������
////							if (k == abs(vend))//β����ǵڶ����ڵ������
////								result.push_back({ i,j });//i,j�����ڵ����Ҫ��
////		printf("%d\n", result.size());
////		sort(result.begin(), result.end());//����
////		for (auto&i : result)//���
////			printf("%04d %04d\n", i.first, i.second);
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int n, m;
//bool friends[10005][10005] = { false };
//bool isMan[10005] = { false };
//int main()
//{
//	cin >> n >> m;
//	int a, b, c, d;
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> a >> b;
//		isMan[abs(a)] = a > 0;
//		isMan[abs(b)] = b > 0;
//		friends[abs(a)][abs(b)] = friends[abs(b)][abs(a)] = true;
//	}
//	cin >> m;
//	while (m--)
//	{
//		cin >> a >> b;
//		vector<pair<int, int>>res;
//		for (c = 0; c < 10005; ++c)
//			if (c!=abs(b) && friends[abs(a)][c] && isMan[abs(a)] == isMan[c])//��������ͬ��
//				for (d = 0; d < 10005; ++d)
//					if (d!=abs(a) && friends[d][c] && friends[d][abs(b)] && isMan[abs(b)] == isMan[d])
//						res.push_back(make_pair(c, d));
//		sort(res.begin(), res.end(), [](pair<int, int>p1, pair<int, int>p2) {
//			if (p1.first == p2.first)return p1.second < p2.second;
//			else return p1.first < p2.first; });
//		cout << res.size() << endl;
//		for (auto v : res)
//			cout << v.first << " " << v.second << endl;
//	}
//	return 0;
//}
//
