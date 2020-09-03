//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//struct Node
//{
//	int v;
//	Node *l, *r;
//	Node(int a = -1) :v(a), l(nullptr), r(nullptr) {}
//};
//Node* root;
//void creatTree()
//{
//	root = new Node(1);
//	root->l = new Node(2);
//	root->r = new Node(3);
//	root->l->r = new Node(4);
//	root->l->r->l = new Node(7);
//	root->l->r->r = new Node(8);
//	root->l->r->r->r = new Node(11);
//	root->l->r->r->r->l = new Node(13);
//	root->l->r->r->r->r = new Node(14);
//	root->r->l = new Node(5);
//	root->r->r = new Node(6);
//	root->r->l->l = new Node(9);
//	root->r->l->r = new Node(10);
//	root->r->l->l->l = new Node(12);
//	root->r->l->l->l->l = new Node(15);
//	root->r->l->l->l->r = new Node(16);
//}
//////////////��׼һ/////////////////
//int getHeight(Node* h, int l)//��ȡ����������
//{
//	if (h == nullptr)
//		return l;
//	return max(getHeight(h->l, l + 1), getHeight(h->r, l + 1));
//}
//void setEdgeMap(Node* h, int l, vector<vector<Node*>>&edgeMap)
//{
//	if (h == nullptr)
//		return;
//	edgeMap[l][0] = edgeMap[l][0] == nullptr ? h : edgeMap[l][0];
//	edgeMap[l][1] = h;
//	setEdgeMap(h->l, l + 1, edgeMap);//��������߽�
//	setEdgeMap(h->r, l + 1, edgeMap);//�������ұ߽�
//}
//void printLeafEdge(Node* h, int l, vector<vector<Node*>>edgeMap)
//{
//	if (h == nullptr)
//		return;
//	if (h->l == nullptr && h->r == nullptr && h != edgeMap[l][0] && h != edgeMap[l][1])//��Ҷ�ӽڵ㣬���������ұ߽�ڵ�
//		cout << h->v << " ";
//	printLeafEdge(h->l, l + 1, edgeMap);//����Ѱ�Ҹñ߽�Ҷ�ӽڵ�
//	printLeafEdge(h->r, l + 1, edgeMap);
//}
//void printEdge1(Node* root)
//{
//	if (root == nullptr)
//		return;
//	int h = getHeight(root, 0);//�õ����
//	vector<vector<Node*>>edgeMap(h, vector<Node*>(2));//ÿһ������ұ߽�
//	setEdgeMap(root, 0, edgeMap);
//	//�ȴ�ӡ��߽�
//	for (int i = 0; i < edgeMap.size(); ++i)
//		cout << edgeMap[i][0]->v << " ";
//	//��ӡ�������ұ߽磬���ǽڵ�߽�Ľڵ�
//	printLeafEdge(root, 0, edgeMap);
//	//��ӡ�ұ߽�ڵ�
//	for (size_t i = edgeMap.size() - 1; i >= 0; --i)
//		if (edgeMap[i][0] != edgeMap[i][1])
//			cout << edgeMap[i][1]->v << " ";
//}
//////////////��׼��/////////////////
//void printLeftEdge(Node* h, bool f)
//{
//	if (h == nullptr)
//		return;
//	if (f || (h->l == nullptr && h->r == nullptr))//�߽�Ҷ�ӽڵ�
//		cout << h->v << " ";
//	printLeftEdge(h->l, f);
//	printLeftEdge(h->r, f && h->l == nullptr ? true : false);
//}
//void printRightEdge(Node* h, bool f)
//{
//	if (h == nullptr)
//		return;
//	printLeftEdge(h->l, f && h->r == nullptr ? true : false);
//	printLeftEdge(h->r, f);
//	if (f || (h->l == nullptr && h->r == nullptr))//�߽�Ҷ�ӽڵ�
//		cout << h->v << " ";
//}
//void printEdge2(Node* root)
//{
//	if (root == nullptr)
//		return;
//	cout << root->v << " ";//���ڵ�����Ҫ��
//	if (root->l != nullptr && root->r != nullptr)
//	{
//		printLeftEdge(root->l, true);
//		printRightEdge(root->r, true);
//	}
//	else
//		printEdge2(root->l != nullptr ? root->l : root->r);
//
//}
//
//int main()
//{
//	creatTree();
//	//printEdge1(root);
//	printEdge2(root);
//	return 0;
//}
//
//
//
//
//����Ŀ��
//����һ�ö�������ͷ�ڵ�head�������������ֱ�׼�ֱ�ʵ�ֶ������߽�ڵ����ʱ���ӡ��
//��׼һ��
//1.ͷ�ڵ�Ϊ�߽�ڵ㡣
//2.Ҷ�ڵ�Ϊ�߽�ڵ㡣
//3.����ڵ��������ڵĲ�������������ҵģ���ôҲ�Ǳ߽��㡣
//��׼����
//1.ͷ�ڵ�Ϊ�߽�ڵ㡣
//2.Ҷ�ڵ�Ϊ�߽�ڵ㡣
//3.����߽�������ȥ��·��Ϊ�߽�ڵ㡣
//4.���ұ߽�������ȥ��·��Ϊ�߽�ڵ㡣
//���磬��ͼ3 - 2��ʾ������
//
//����׼һ�Ĵ�ӡ���Ϊ��1��2��4��7��11��13��14��15��16��12��10��6��3
//����׼���Ĵ�ӡ���Ϊ��1��2��4��7��13��14��15��16��10��6��3
//��Ҫ��
//1.����ڵ���ΪN�����ֱ�׼ʵ�ֵ�ʱ�临�Ӷ�Ҫ��ΪO(N)������ռ临�Ӷ�Ҫ��ΪO(h)��hΪ�������ĸ߶ȡ�
//2.���ֱ�׼��Ҫ����ʱ��˳���Ҳ��ظ���ӡ���еı߽�ڵ㡣
//�����
//���ձ�׼һ��Ҫ��ʵ�ִ�ӡ�ľ���������£�
//1.�õ�������ÿһ������������ҵĽڵ㡣����Ŀ��������˵�������¼���£�
//����ڵ�            ���ҽڵ�
//��һ��  1                        1
//�ڶ���  2                        3
//������  4                        6
//���Ĳ�  7                       10
//�����  11                     12
//������  13                     16
//2.���ϵ��´�ӡ���в��е�����ڵ㡣����Ŀ��������˵������ӡ��1��2��4��7��11��13��
//3.�����������������ӡ��Щ������ĳһ����������ҵĽڵ㣬��ͬʱ����Ҷ�ڵ�Ľڵ㡣����Ŀ��������˵������ӡ��14��15��
//4.���µ��ϴ�ӡ���в��е����ҽڵ㣬���ڵ㲻�ܼ�������ڵ㣬�������ҽڵ㡣����Ŀ��������˵������ӡ��16��12��10��6��3��
//////////////��׼һ/////////////////
//int getHeight(Node* h, int l)//��ȡ����������
//{
//	if (h == nullptr)
//		return l;
//	return max(getHeight(h->l, l + 1), getHeight(h->r, l + 1));
//}
//void setEdgeMap(Node* h, int l, vector<vector<Node*>>&edgeMap)
//{
//	if (h == nullptr)
//		return;
//	edgeMap[l][0] = edgeMap[l][0] == nullptr ? h : edgeMap[l][0];
//	edgeMap[l][1] = h;
//	setEdgeMap(h->l, l + 1, edgeMap);//��������߽�
//	setEdgeMap(h->r, l + 1, edgeMap);//�������ұ߽�
//}
//void printLeafEdge(Node* h, int l, vector<vector<Node*>>edgeMap)
//{
//	if (h == nullptr)
//		return;
//	if (h->l == nullptr && h->r == nullptr && h != edgeMap[l][0] && h != edgeMap[l][1])//��Ҷ�ӽڵ㣬���������ұ߽�ڵ�
//		cout << h->v << " ";
//	printLeafEdge(h->l, l + 1, edgeMap);//����Ѱ�Ҹñ߽�Ҷ�ӽڵ�
//	printLeafEdge(h->r, l + 1, edgeMap);
//}
//void printEdge1(Node* root)
//{
//	if (root == nullptr)
//		return;
//	int h = getHeight(root, 0);//�õ����
//	vector<vector<Node*>>edgeMap(h, vector<Node*>(2));//ÿһ������ұ߽�
//	setEdgeMap(root, 0, edgeMap);
//	//�ȴ�ӡ��߽�
//	for (int i = 0; i < edgeMap.size(); ++i)
//		cout << edgeMap[i][0]->v << " ";
//	//��ӡ�������ұ߽磬���ǽڵ�߽�Ľڵ�
//	printLeafEdge(root, 0, edgeMap);
//	//��ӡ�ұ߽�ڵ�
//	for (int i = edgeMap.size() - 1; i >= 0; --i)
//		if (edgeMap[i][0] != edgeMap[i][1])
//			cout << edgeMap[i][1]->v << " ";
//}
//
//���ձ�׼����Ҫ��ʵ�ִ�ӡ�ľ���������£�
//1.��ͷ�ڵ㿪ʼ����Ѱ�ң�ֻҪ�ҵ���һ���������ӣ������Һ��ӵĽڵ㣬��Ϊh������벽��2������������У��ҹ��Ľڵ㶼��ӡ������Ŀ��������˵������ӡ��1����Ϊͷ�ڵ�ֱ�ӷ���Ҫ�����Դ�ӡ��û�к�����Ѱ�ҹ��̣�ֱ�ӽ��벽��2���������������ͼ3 - 3��ʾ����ʱ���ӡ��1��2��3���ڵ�3�Ǵ�ͷ�ڵ㿪ʼ���µ�һ������Ҫ��ġ�������������ϵ���һֱ�ҵ�Ҷ�ڵ�Ҳ�����ڷ���Ҫ��Ľڵ㣬˵���������ǰ�״�ṹ����ô��ӡ�ҹ��Ľڵ��ֱ�ӷ��ؼ��ɡ�
//2.h���������Ƚ��벽��3�Ĵ�ӡ���̣�h���������ٽ��벽��4�Ĵ�ӡ���̣���󷵻ء�
//3.��ӡ��߽������·���Լ�h�����������е�Ҷ�ڵ㣬������ο�printLeftEdge������
//4.��ӡ�ұ߽������·���Լ�h�����������е�Ҷ�ڵ㣬������ο�printRightEdge������
//////////////��׼��/////////////////
//void printLeftEdge(Node* h, bool f)
//{
//	if (h == nullptr)
//		return;
//	if (f || (h->l == nullptr && h->r == nullptr))//�߽�Ҷ�ӽڵ�
//		cout << h->v << " ";
//	printLeftEdge(h->l, f);
//	printLeftEdge(h->r, f && h->l == nullptr ? true : false);
//}
//void printRightEdge(Node* h, bool f)
//{
//	if (h == nullptr)
//		return;
//	printLeftEdge(h->l, f && h->r == nullptr ? true : false);
//	printLeftEdge(h->r, f);
//	if (f || (h->l == nullptr && h->r == nullptr))//�߽�Ҷ�ӽڵ�
//		cout << h->v << " ";
//}
//void printEdge2(Node* root)
//{
//	if (root == nullptr)
//		return;
//	cout << root->v << " ";//���ڵ�����Ҫ��
//	if (root->l != nullptr && root->r != nullptr)
//	{
//		printLeftEdge(root->l, true);
//		printRightEdge(root->r, true);
//	}
//	else
//		printEdge2(root->l != nullptr ? root->l : root->r);
//
//}
//
