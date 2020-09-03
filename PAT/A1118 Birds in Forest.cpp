////#include <iostream>
////using namespace std;
////int a, b, n, k, q, father[10005], birdNums = 0, treeNums = 0;
////int findFather(int x)
////{
////	if (father[x] == x)
////		return x;
////	int temp = findFather(father[x]);
////	father[x] = temp;
////	return temp;
////}
////void Unit(int a, int b)
////{
////	int ax = findFather(a), bx = findFather(b);
////	if (ax != bx)
////		father[ax] = bx;
////}
////int main()
////{
////	cin >> n;
////	for (int i = 0; i < 10005; ++i)
////		father[i] = i;
////	while(n--)
////	{
////		cin >> k;
////		if (k--)
////		{
////			cin >> a;
////			birdNums = birdNums > a ? birdNums : a;//因为鸟的序号是连续的，故数量即使最大序列号
////		}
////		while (k--)
////		{
////			cin >> b;			
////			Unit(a,b);//合并合集
////			birdNums = birdNums > b ? birdNums : b;
////		}
////	}
////	for (int i = 1; i <= birdNums; ++i)
////		if (findFather(i) == i)
////			++treeNums;
////	printf("%d %d\n", treeNums, birdNums);
////	cin >> q;
////	while (q--)
////	{
////		cin >> a >> b;
////		if (findFather(a) == findFather(b))
////			cout << "Yes" << endl;
////		else
////			cout << "No" << endl;
////	}
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//int n, nums = -1, father[10010], brids[10010] = { 0 };
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
//	for (int i = 0; i < 10010; ++i)
//		father[i] = i;
//	int k, a, b;
//	for (int i =1; i <= n; ++i)
//	{
//		cin >> k;
//		while (k--)
//		{
//			cin >> a;
//			nums = a > nums ? a : nums;
//			if (brids[i] == 0)
//				brids[i] = a;
//			else
//				Union(brids[i], a);
//		}
//	}
//	unordered_map<int, int>tree;
//	for (int i = 1; i <= nums; ++i)
//		tree[findFather(i)]++;
//	cout << tree.size() << " " << nums << endl;
//	cin >> n;
//	while (n--)
//	{
//		cin >>a >> b;
//		if (findFather(a) == findFather(b))
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}