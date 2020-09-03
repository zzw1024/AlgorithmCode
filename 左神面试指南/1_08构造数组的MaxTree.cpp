//#include <iostream>
//#include <vector>
//#include <deque>
//#include <sstream>
//
//using namespace std;
//
////
////Problem:
////	【题目】将一个没有重复数字的数组中的数据构造一个二叉树
////	每个节点都是该子树的最大值
////	【要求】
////	时间复杂度为O(N)
////Solution:
////	使用单调栈,栈的顺序是维持从大到小排序
////	通过使用单调栈，将数组中中所有数的左右比他大的数记录下来
////	当某个数既无左边比他大的数，有无右边比他大的数，则该数为全局最大，将其作为二叉树的根
////	然后，某数只有左比他大的数，或者右比他大的数，则该数直接挂在比他大的数的下面，
////	当某个数既有左比他大的数，又有右比他大的数，则挂在两个数中较小数的下面。
////	然后直接构成一棵树。
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
//{//以下代码都是以数组的下角标为根据
//	vector<Node*>node;
//	vector<pair<int, int>>res;//存储每个数的左右大小的数
//	res.resize(v.size());
//	deque<int>d;//单调栈
//	for (int i = 0; i < v.size(); ++i)
//	{
//		Node* p = new Node(v[i]);
//		node.push_back(p);//先生成相关的节点
//		while (!d.empty() && v[i] > v[d.back()])
//		{
//			int index = d.back();
//			d.pop_back();
//			if (d.empty())//有右大值，无左大值
//				res[index] = pair<int, int>(-1, i);
//			else//有右大值和左大值
//				res[index] = pair<int, int>(d.back(), i);
//		}
//		d.push_back(i);
//	}
//	while (!d.empty())
//	{
//		int index = d.back();
//		d.pop_back();
//		if (d.empty())//即无右大值，又无左大值
//			res[index] = pair<int, int>(-1, -1);
//		else//无右大值有左大值
//			res[index] = pair<int, int>(d.back(), -1);
//	}
//	for (int i = 0; i < res.size(); ++i)
//	{
//		int a, b;
//		a = res[i].first;
//		b = res[i].second;
//		if (a == -1 && b == -1)//即无右大值，又无左大值为根节点
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
////打印树形状进行查看
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
