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
///////////////�ݹ鷽ʽ///////////////
//void preOrder(Node* root)//ǰ�����
//{
//	if (root == nullptr)
//		return;
//	res.push_back(root->v);
//	preOrder(root->l);
//	preOrder(root->r);
//}
//void inOrder(Node* root)//�������
//{
//	if (root == nullptr)
//		return;
//	preOrder(root->l);
//	res.push_back(root->v);
//	preOrder(root->r);
//}
//void lastOrder(Node* root)//�������
//{
//	if (root == nullptr)
//		return;
//	lastOrder(root->l);
//	lastOrder(root->r);
//	res.push_back(root->v);
//}
///////////////�ǵݹ鷽ʽ///////////
//void NpreOrder(Node* root)//ǰ�����
////1.����һ���µ�ջ����Ϊstack��Ȼ��ͷ�ڵ�headѹ��stack�С�
////2.��stack�е���ջ���ڵ㣬��Ϊcur��Ȼ���ӡcur�ڵ��ֵ���ٽ��ڵ�cur���Һ��ӣ���Ϊ�յĻ�����ѹ��stack�У����cur�����ӣ���Ϊ�յĻ���ѹ��stack�С�
////3.�����ظ�����2��ֱ��stackΪ�գ�ȫ�����̽�����
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
//void NinOrder(Node* root)//�������
////1.����һ���µ�ջ����Ϊstack����ʼʱ�������cur = head��
////2.�Ȱ�cur�ڵ�ѹ��ջ�У�����cur�ڵ�Ϊͷ������������˵�����ΰ���߽�ѹ��ջ�У�����ͣ����cur = cur.left��Ȼ���ظ�����2��
////3.�����ظ�����2��ֱ������curΪ�գ���ʱ��stack�е���һ���ڵ㣬��Ϊnode��
////��ӡnode��ֵ��������cur = node.right��Ȼ������ظ�����2��
////4.��stackΪ����curΪ��ʱ����������ֹͣ��
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
//void NlastOrder1(Node* root)//�������
////�Ƚ���������ջʵ�ֺ�������Ĺ��̣�����������£�
////1.����һ��ջ����Ϊsl��Ȼ��ͷ�ڵ�headѹ��sl�С�
////2.��sl�е����Ľڵ��Ϊcur��Ȼ�����ν�cur�����Ӻ��Һ���ѹ��sl�С�
////3.�����������У�ÿһ����s1�е����Ľڵ㶼�Ž�s2�С�
////4.�����ظ�����2�Ͳ���3��ֱ��s1Ϊ�գ�����ֹͣ��
////5.��s2�����ε����ڵ㲢��ӡ����ӡ��˳����Ǻ��������˳��
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
//void NlastOrder2(Node* root)//�������
////������ֻ��һ��ջʵ�ֺ�������Ĺ��̣�����������£�
////1.����һ��ջ����Ϊstack����ͷ�ڵ�ѹ��stack��ͬʱ������������h��c�������������У�h�������һ�ε�������ӡ�Ľڵ㣬c����stack��ջ���ڵ㣬��ʼʱhΪͷ�ڵ㣬cΪnull��
////2.ÿ����c���ڵ�ǰstack��ջ���ڵ㵫�ǲ���stack�е�����ʱ���������������
////�����c�����Ӳ�Ϊnull������h������c�����ӣ�Ҳ������c���Һ��ӣ����c������ѹ��stack�С��������һ����ô����ԭ������h�����������һ�ε�������ӡ�Ľڵ㣬�������h����c�����ӻ����Һ��ӣ�˵��c�����������������Ѿ���ӡ��ϣ���ʱ��Ӧ���ٽ�c�����ӷ���stack�С�����˵����������û���������ô��ʱ��c������ѹ��stack�С�
////����������ٲ�����������c���Һ��Ӳ�Ϊnull��h������c���Һ��ӣ����c���Һ���ѹ��stack�С����������h����c���Һ��ӣ�˵��c���������Ѿ���ӡ��ϣ���ʱ��Ӧ���ٽ�c���Һ��ӷ���stack�С�����˵����������û���������ʱ��c���Һ���ѹ��stack�С�
////����������ٺ������ڶ���������˵��c�������������������Ѿ���ӡ��ϣ���ô��stack�е���c����ӡ��Ȼ����h = c��
////3.һֱ�ظ�����2��ֱ��stackΪ�գ�����ֹͣ��
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