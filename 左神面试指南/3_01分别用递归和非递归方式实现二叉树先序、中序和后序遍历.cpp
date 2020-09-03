//#include <iostream>
//#include <queue>
//#include <vector>
//#include <stack>
//using namespace std;
//struct Node
//{
//	int v;
//	Node *r, *l;
//	Node(int a = -1) :v(a), r(nullptr), l(nullptr) {}
//};
//Node* root = nullptr;
//vector<int>res;
//void creatTree()
//{
//	root = new Node(1);
//	root->l = new Node(2);
//	root->r = new Node(3);
//	root->l->l = new Node(4);
//	root->l->r = new Node(5);
//	root->r->l = new Node(6);
//	root->r->r = new Node(7);
//}
///////////////递归方式///////////////
//void preOrder(Node* root)//前序遍历
//{
//	if (root == nullptr)
//		return;
//	res.push_back(root->v);
//	preOrder(root->l);
//	preOrder(root->r);
//}
//void inOrder(Node* root)//中序遍历
//{
//	if (root == nullptr)
//		return;
//	preOrder(root->l);
//	res.push_back(root->v);
//	preOrder(root->r);
//}
//void lastOrder(Node* root)//后序遍历
//{
//	if (root == nullptr)
//		return;
//	lastOrder(root->l);
//	lastOrder(root->r);
//	res.push_back(root->v);
//}
///////////////非递归方式///////////
//void NpreOrder(Node* root)//前序遍历
////1.申请一个新的栈，记为stack。然后将头节点head压入stack中。
////2.从stack中弹出栈顶节点，记为cur，然后打印cur节点的值，再将节点cur的右孩子（不为空的话）先压入stack中，最后将cur的左孩子（不为空的话）压入stack中。
////3.不断重复步骤2，直到stack为空，全部过程结束。
//{
//	if (root == nullptr)
//		return;
//	stack<Node*>s;
//	s.push(root);
//	while (!s.empty())
//	{
//		Node* p = s.top();
//		s.pop();
//		res.push_back(p->v);
//		if (p->r != nullptr)
//			s.push(p->r);
//		if (p->l != nullptr)
//			s.push(p->l);
//	}
//}
//
//void NinOrder(Node* root)//中序遍历
////1.申请一个新的栈，记为stack。初始时，令变量cur = head。
////2.先把cur节点压入栈中，对以cur节点为头的整棵子树来说，依次把左边界压入栈中，即不停地令cur = cur.left，然后重复步骤2。
////3.不断重复步骤2，直到发现cur为空，此时从stack中弹出一个节点，记为node。
////打印node的值，并且让cur = node.right，然后继续重复步骤2。
////4.当stack为空且cur为空时，整个过程停止。
//{
//	if (root == nullptr)
//		return;
//	stack<Node*>s;
//	Node* p = root;
//	while (p != nullptr || !s.empty())
//	{
//		if (p != nullptr)
//		{
//			s.push(p);
//			p = p->l;
//		}
//		else
//		{
//			p = s.top();
//			s.pop();
//			res.push_back(p->v);
//			p = p->r;
//		}
//	}
//}
//void NlastOrder1(Node* root)//后序遍历
////先介绍用两个栈实现后序遍历的过程，具体过程如下：
////1.申请一个栈，记为sl，然后将头节点head压入sl中。
////2.从sl中弹出的节点记为cur，然后依次将cur的左孩子和右孩子压入sl中。
////3.在整个过程中，每一个从s1中弹出的节点都放进s2中。
////4.不断重复步骤2和步骤3，直到s1为空，过程停止。
////5.从s2中依次弹出节点并打印，打印的顺序就是后序遍历的顺序。
//{
//	if (root == nullptr)
//		return;
//	stack<Node*>s1, s2;
//	s1.push(root);
//	Node* p;
//	while (!s1.empty())
//	{
//		p = s1.top();
//		s1.pop();
//		s2.push(p);
//		if (p->l != nullptr)
//			s1.push(p->l);
//		if (p->r != nullptr)
//			s1.push(p->r);
//	}
//	while (!s2.empty())
//	{
//		p = s2.top();
//		s2.pop();
//		res.push_back(p->v);
//	}
//}
//void NlastOrder2(Node* root)//后序遍历
////最后介绍只用一个栈实现后序遍历的过程，具体过程如下：
////1.申请一个栈，记为stack，将头节点压入stack，同时设置两个变量h和c。在整个流程中，h代表最近一次弹出并打印的节点，c代表stack的栈顶节点，初始时h为头节点，c为null。
////2.每次令c等于当前stack的栈顶节点但是不从stack中弹出此时分以下三种情况。
////①如果c的左孩子不为null，并且h不等于c的左孩子，也不等于c的右孩子，则把c的左孩子压入stack中。具体解释一下这么做的原因，首先h的意义是最近一次弹出并打印的节点，所以如果h等于c的左孩子或者右孩子，说明c的左子树与右子树已经打印完毕，此时不应该再将c的左孩子放入stack中。否则，说明左子树还没处理过，那么此时将c的左孩子压入stack中。
////②如果条件①不成立，并且c的右孩子不为null，h不等于c的右孩子，则把c的右孩子压入stack中。含义是如果h等于c的右孩子，说明c的右子树已经打印完毕，此时不应该再将c的右孩子放入stack中。否则，说明右子树还没处理过，此时将c的右孩子压入stack中。
////③如果条件①和条件②都不成立，说明c的左子树和右子树都已经打印完毕，那么从stack中弹出c并打印，然后令h = c。
////3.一直重复步骤2，直到stack为空，过程停止。
//{
//	if (root == nullptr)
//		return;
//	stack<Node*>s;
//	s.push(root);
//	Node* p;//root==h  p==c
//	while (!s.empty())
//	{
//		p = s.top();
//		if (p->l != nullptr && root != p->l && root != p->r)
//			s.push(p->l);
//		else if (p->r != nullptr && root != p->r)
//			s.push(p->r);
//		else
//		{
//			res.push_back(p->v);
//			s.pop();
//			root = p;
//		}
//	}
//}
//
//int main()
//{
//
//}