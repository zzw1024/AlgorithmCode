////#include <iostream>
////#include <numeric>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int hobby[1005], father[1005];
////int findFather(int x) 
////{//���Ҹ��׽�㲢����·��ѹ��
////	if (x == father[x])
////		return x;
////	int temp = findFather(father[x]);
////	father[x] = temp;
////	return temp;
////}
////void unionSet(int a, int b) 
////{//�ϲ���������
////	int ua = findFather(a), ub = findFather(b);
////	if (ua != ub)
////		father[ua] = ub;//�����ǹؼ���������λ�õ�father��Ϊ����й�ͬ���õ���
////}
////int main() {
////	int n, m, a;
////	cin >> n;
////	for (int i = 0; i <= n; ++i)father[i] = i;//��ʼ��
////	for (int i = 1; i <= n; ++i) 
////	{
////		scanf("%d:", &m);
////		while (m--) 
////		{
////			cin >> a;
////			if (hobby[a] == 0)//û�����е�ǰ�������
////				hobby[a] = i;//i��Ϊ��һ���иð��õ���
////			else//����ϲ���ð���
////				unionSet(hobby[a], i);//����ͬ�����õ������˺ϲ�Ϊһ������
////		}
////	}
////	vector<int>result(n + 1, 0);//����ÿ�����ϵ�����
////	for (int i = 1; i < n + 1; ++i)
////		++result[findFather(i)];//��ǰѰ��father
////	sort(result.begin(), result.end(), [](int a, int b) {return a > b; });
////	int cnt = 0;
////	for (auto t : result)
////		if (t != 0)
////			cnt++;
////	cout << cnt << endl;
////	for (int i = 0; i < cnt; ++i)//���resultǰcnt��Ԫ��(result�Ѿ��Ӵ�С��������Ķ��Ǽ��ϸ�����Ϊ0��)
////		printf("%s%d", i > 0 ? " " : "", result[i]);
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n, father[1010], hobby[1010] = { 0 }, resNum[1010] = { 0 };
//int findFather(int x)
//{
//	if (x == father[x])
//		return x;
//	int temp = findFather(father[x]);
//	father[x] = temp;
//	return temp;
//}
//void Union(int a, int b)
//{
//	int aF = findFather(a), bF = findFather(b);
//	if (aF != bF)
//		father[aF] = bF;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i <= n; ++i)
//		father[i] = i;
//	for (int i = 1; i <= n; ++i)
//	{
//		int k, a;
//		scanf("%d:", &k);
//		while (k--)
//		{
//			cin >> a;
//			if (hobby[a] == 0)
//				hobby[a] = i;
//			else
//				Union(hobby[a], i);
//		}
//	}
//	for (int i = 0; i <= n; ++i)
//		++resNum[findFather(i)];
//	vector<int>res;
//	for (int i = 1; i <= n; ++i)
//		if (resNum[i] > 0)
//			res.push_back(resNum[i]);
//	sort(res.begin(), res.end(), [](int a, int b) {return a > b; });
//	cout << res.size() << endl;
//	for (int i = 0; i < res.size(); ++i)
//		cout << (i == 0 ? "" : " ") << res[i];
//	return 0;
//}