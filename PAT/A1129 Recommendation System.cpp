//////题目大意:就是顾客买东西之前，根据顾客的购买历史进行商品推荐
//////所以购买第一件商品3是没有推荐的，因为没有购买历史记录
//////然后根据前面购买的历史次数，进行次数从多到少进行推荐，最多推荐三个，相同次数的推荐标号最小的的//
//////使用set来得到按要求的排序规格，vector来辅助查询set中是否已经存在元素
////#include <iostream>
////#include <set>
////#include <vector>
////using namespace std;
////int n, k;
////struct Node
////{
////	int value, cnt;
////	bool operator < (const Node& a)const//set的排序规则
////	{
////		return (cnt != a.cnt) ? cnt > a.cnt:value < a.value;
////	}
////};
////int main()
////{
////	int n, k, num;
////	scanf("%d %d", &n, &k);
////	set<Node>s;
////	vector<int>v(n + 1, 0);
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> num;
////		if (i != 0)//第一件商品没有推荐
////		{
////			cout << num << ":";
////			int i = 1;
////			for (auto ptr = s.begin(); ptr != s.end() && i <= k; ++ptr, i++)
////				cout << " " << ptr->value;
////			cout << endl;
////		}
////		auto ptr = s.find(Node{ num,v[num] });
////		if (ptr != s.end())//记住set不能修改内容，只能擦除后重新写入
////			s.erase(ptr);
////		v[num]++;
////		s.insert(Node{ num,v[num] });//使用了初始化列表原则
////	}
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <set>
//using namespace std;
//struct Node
//{
//	int id, nums;
//	bool operator < (const Node &a)const
//	{
//		return (nums == a.nums ? id<a.id : nums>a.nums);
//	}
//};
//int main()
//{
//	int n, k, item;
//	cin >> n >> k;
//	set<Node>s;
//	int v[50005] = { 0 };
//	for (int i = 0; i < n; ++i)
//	{		
//		cin >> item;
//		if (i > 0)
//		{
//			printf("%d:", item);
//			int j = 0;
//			for (auto ptr = s.begin(); ptr != s.end() && j < k; ++ptr, ++j)
//				printf(" %d", *ptr);
//			printf("\n");
//		}		
//		if (s.find({ item,v[item] }) != s.end())//存在就删除后再插入
//			s.erase({ item,v[item] });
//		v[item]++;
//		s.insert({ item,v[item] });
//	}
//	return 0;
//}