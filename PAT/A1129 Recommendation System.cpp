//////��Ŀ����:���ǹ˿�����֮ǰ�����ݹ˿͵Ĺ�����ʷ������Ʒ�Ƽ�
//////���Թ����һ����Ʒ3��û���Ƽ��ģ���Ϊû�й�����ʷ��¼
//////Ȼ�����ǰ�湺�����ʷ���������д����Ӷൽ�ٽ����Ƽ�������Ƽ���������ͬ�������Ƽ������С�ĵ�//
//////ʹ��set���õ���Ҫ���������vector��������ѯset���Ƿ��Ѿ�����Ԫ��
////#include <iostream>
////#include <set>
////#include <vector>
////using namespace std;
////int n, k;
////struct Node
////{
////	int value, cnt;
////	bool operator < (const Node& a)const//set���������
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
////		if (i != 0)//��һ����Ʒû���Ƽ�
////		{
////			cout << num << ":";
////			int i = 1;
////			for (auto ptr = s.begin(); ptr != s.end() && i <= k; ++ptr, i++)
////				cout << " " << ptr->value;
////			cout << endl;
////		}
////		auto ptr = s.find(Node{ num,v[num] });
////		if (ptr != s.end())//��סset�����޸����ݣ�ֻ�ܲ���������д��
////			s.erase(ptr);
////		v[num]++;
////		s.insert(Node{ num,v[num] });//ʹ���˳�ʼ���б�ԭ��
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
//		if (s.find({ item,v[item] }) != s.end())//���ھ�ɾ�����ٲ���
//			s.erase({ item,v[item] });
//		v[item]++;
//		s.insert({ item,v[item] });
//	}
//	return 0;
//}