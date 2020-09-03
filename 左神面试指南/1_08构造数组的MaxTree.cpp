//#include <iostream>
//#include <vector>
//#include <deque>
//#include <sstream>
//
//using namespace std;
//
////
////Problem:
////	����Ŀ����һ��û���ظ����ֵ������е����ݹ���һ��������
////	ÿ���ڵ㶼�Ǹ����������ֵ
////	��Ҫ��
////	ʱ�临�Ӷ�ΪO(N)
////Solution:
////	ʹ�õ���ջ,ջ��˳����ά�ִӴ�С����
////	ͨ��ʹ�õ���ջ�����������������������ұ����������¼����
////	��ĳ����������߱���������������ұ߱���������������Ϊȫ����󣬽�����Ϊ�������ĸ�
////	Ȼ��ĳ��ֻ�������������������ұ���������������ֱ�ӹ��ڱ�������������棬
////	��ĳ�������������������������ұ����������������������н�С�������档
////	Ȼ��ֱ�ӹ���һ������
////
//
//
//struct Node
//{
//	int val;
//	Node* lchild;
//	Node* rchild;
//	Node(int a) :val(a), lchild(nullptr), rchild(nullptr) {}
//};
//
//void creatMaxTree(Node*& root, vector<int>v)
//{//���´��붼����������½Ǳ�Ϊ����
//	vector<Node*>node;
//	vector<pair<int, int>>res;//�洢ÿ���������Ҵ�С����
//	res.resize(v.size());
//	deque<int>d;//����ջ
//	for (int i = 0; i < v.size(); ++i)
//	{
//		Node* p = new Node(v[i]);
//		node.push_back(p);//��������صĽڵ�
//		while (!d.empty() && v[i] > v[d.back()])
//		{
//			int index = d.back();
//			d.pop_back();
//			if (d.empty())//���Ҵ�ֵ�������ֵ
//				res[index] = pair<int, int>(-1, i);
//			else//���Ҵ�ֵ�����ֵ
//				res[index] = pair<int, int>(d.back(), i);
//		}
//		d.push_back(i);
//	}
//	while (!d.empty())
//	{
//		int index = d.back();
//		d.pop_back();
//		if (d.empty())//�����Ҵ�ֵ���������ֵ
//			res[index] = pair<int, int>(-1, -1);
//		else//���Ҵ�ֵ�����ֵ
//			res[index] = pair<int, int>(d.back(), -1);
//	}
//	for (int i = 0; i < res.size(); ++i)
//	{
//		int a, b;
//		a = res[i].first;
//		b = res[i].second;
//		if (a == -1 && b == -1)//�����Ҵ�ֵ���������ֵΪ���ڵ�
//			root = node[i];
//		else if (a == -1 && b != -1)
//			node[b]->rchild = node[i];
//		else if (a != -1 && b == -1)
//			node[a]->lchild = node[i];
//		else if (v[a] > v[b])
//			node[b]->rchild = node[i];
//		else
//			node[a]->lchild = node[i];
//	}
//}
//
////��ӡ����״���в鿴
//class PrintTree
//{
//public:
//	void Print(Node* root)
//	{
//		cout << "The shape of tree is: " << endl;
//		cout << "=============================================================" << endl;
//		PrintShape(root, 0, "H", 17);
//		cout << "=============================================================" << endl;
//	}
//	void PrintShape(Node* root, int h, string c, int len)
//	{
//		if (root)
//		{
//			PrintShape(root->rchild, h + 1, "v", len);
//			string val;
//			stringstream ss;
//			ss << root->val;
//			ss >> val;
//			val = c + val + c;
//			int lenM = val.length();
//			int lenL = (len - lenM) / 2;
//			int lenR = len - lenM - lenL;
//			val = getSpace(lenL) + val + getSpace(lenR);
//			cout << getSpace(h*len) + val << endl;
//			PrintShape(root->lchild, h + 1, "^", len);
//		}
//
//	}
//	string getSpace(int num)
//	{
//		string space = " ";
//		for (int i = 0; i < num; ++i)
//			space.append(" ");
//		return space;
//	}
//};
//
//void Test()
//{
//	vector<int>v;
//	v = { 5,3,4,2,6,1 };
//	Node* root = nullptr;
//	creatMaxTree(root, v);
//	PrintTree print;
//	print.Print(root);
//}
//
//
//
//
