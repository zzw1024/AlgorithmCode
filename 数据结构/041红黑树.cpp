#include "000�⺯��.h"


enum RBTColor {RED, BLACK};

template<class T>
class RBNode
{
public:
	RBTColor color;//��ɫ
	T value; //ֵ
	RBNode *left;//����
	RBNode *right;//�Һ���
	RBNode *parent;//���ڵ�

	RBNode(T v, RBTColor c, RBNode *p, RBNode *l, RBNode *r) :
		value(v), color(c), parent(p), left(l), right(r) {}
};

template <class T>
class RBTree
{
private: 
	RBNode<T> *mRoot;//�������ĸ��ڵ�

public:
	RBTree();
	~RBTree();

	//ǰ�����
	void preOrder();
	//�������
	void inOrder();
	//�������
	void postOrder();

	//����
	RBNode<T> *search(T key);

	//��Сֵ
	T getMin();
	//���ֵ
	T getMax();

	//ǰ���ڵ㣬������������Ҷ�ڵ�
	RBNode<T> *getPreNode(RBNode *root);
	//��̽ڵ㣬������������ڵ�
	RBNode<T> *getPostNode(RBNode *root);

	//����
	void insert(T key);
	//ɾ��
	void remove(T key);
	//����
	void destroy();
	//��ӡ
	void print();

private:
	//ǰ�����
	void preOrder(RBNode<T> *root) const;
	//�������
	void inOrder(RBNode<T> *root) const;
	//�������
	void postOrder(RBNode<T> *root) const;

	//��Сֵ
	RBNode<T> *getMin(RBNode<T> *root) const;
	//���ֵ
	RBNode<T> *getMax(RBNode<T> *root) const;

	//����
	RBNode<T> *search(RBNode<T> *root, T key) const;
	
	//����
	void rateLeft(RBNode<T> *&root, RBNode<T> *node);
	//����
	void rateRight(RBNode<T> *&root, RBNode<T> *node);

	//����
	void insert(RBNode<T> *&root, RBNode<T> *x);
	//������������
	void insertFixUp(RBNode<T> *&root, RBNode<T> *x);

	//ɾ��
	void remove(RBNode<T> *&root, RBNode<T> *x);
	//ɾ����������
	void removeFixUp(RBNode<T> *&root, RBNode<T> *x);

	//����
	void destroy(RBNode *&tree);
	
	//��ӡ
	void print(RBNode<T> *tree, T key, int direction);

#define rb_parent(r) ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r) ((r)->color == RED)
#define rb_is_black(r) ((r)->color == BLACk)
#define rb_set_black(r) do{(r)->color = BLACK;}while(0)
#define rb_set_red(r) do{(r)->color = RED;}while(0)
#define rb_set_parent(r, p) do{(r)->parent = (p);}while(0)
#define rb_set_color(r, c) do{(r)->parent = (c);}while(0) 
};

//���캯��
template <class T>
RBTree<T>::RBTree()
{
	mRoot = nullptr;
}
//��������
template<class T>
RBTree<T>::~RBTree()
{
	destroy();
}

//ǰ�����
template<class T>
void RBTree<T>::preOrder()
{
	preOrder(mRoot);
}
template<class T>
void RBTree<T>::preOrder(RBNode<T> *root)const
{
	if (root == nullptr)
		return;
	cout << root->value << " ";
	preOrder(root->left);
	preOrder(root->right);
}
//�������
template<class T>
void RBTree<T>::inOrder()
{
	inOrder(mRoot);
}
template<class T>
void RBTree<T>::inOrder(RBNode<T> *root)const
{
	if (root == nullptr)
		return;
	inOrder(root->left);
	cout << root->value << " ";
	inOrder(root->right);
}
//�������
template <class T>
void RBTree<T>::postOrder()
{
	postOrder(mRoot);
}
template<class T>
void RBTree<T>::postOrder(RBNode<T> *root)const
{
	if (root == nullptr)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->value << " ";
}

//����
template<class T>
RBNode<T> *RBTree<T>::search(T key)
{
	return search(mRoot, key);
}
template<class T>
RBNode<T> *RBTree<T>::search(RBNode<T> *root, T key)const
{
	if (root == nullptr || key == root->value)
		return root;
	else if (key < root->value)
		return search(root->left, key);
	else
		return search(root->right, key);
}

//��Сֵ
template<class T>
T RBTree<T>::getMin()
{
	RBNode<T> *p = getMin(mRoot);
	return p == nullptr ? nullptr : p->value;
}
template<class T>
RBNode<T> *RBTree<T>::getMin(RBNode<T> *root) const
{
	while (root!=nullptr && root->left != nullptr)
		root = root->left;
	return root;
}

//���ֵ
template<class T>
T RBTree<T>::getMax()
{
	RBNode<T> *p = getMax(mRoot);
	return p == nullptr ? nullptr : p->value;
}
template<class T>
RBNode<T> *RBTree<T>::getMax(RBNode<T> *root) const
{
	while (root != nullptr && root->right != nullptr)
		root = root->right;
	return root;
}

//ǰ���ڵ㣬������������Ҷ�ڵ�
template<class T>
RBNode<T> *RBTree<T>::getPreNode(RBNode<T> *root)
{
	if (root->left)return getMax(root->left);
	//���rootΪһ����ڵ�,����ӵ������������͸��ڵ������ǰ���ڵ�
	//���rootΪһ���ҽڵ㣬���丸�ڵ������ǰ���ڵ�
	RBNode<T> *p = root->parent;
	while (p != nullptr && root==p->left)
	{
		root = p;
		p = p->parent;
	}
	return p;
}
//��̽ڵ㣬������������ڵ�
template<class T>
RBNode<T> *RBTree<T>::getPostNode(RBNode<T> *root)
{
	if (root->right != nullptr)return getMin(root->right);
	//���rootΪһ���Һ��ӣ����ҵ���͵ĸ��ڵ㣬�Ҹ��ڵ����������
	//���rootΪһ�����ӣ����丸�ڵ�������ĺ�̽ڵ�
	RBNode<T>*p = root->parent;
	while (p != nullptr && x == p->right)
	{
		root = p;
		p = p->parent;
	}
	return p;
}

//����
template<class T>
void RBTree<T>::rateLeft(RBNode<T>*&root, RBNode<T>*node)
{
	RBNode<T> *p = node->right;
	node->right = p->left;
	if (p->left != nullptr)
		p->left->parent = node;
	
	p->parent = node->parent;

	if (node->parent == nullptr)
		root = p;
	else if (node->parent->left == node)
		node->parent->left = p;
	else
		node->parent->right = p;

	p->left = node;
	node->parent = p;
}

//����
template<class T>
void RBTree<T>::rateRight(RBNode<T> *&root, RBNode<T> *node)
{
	RBNode<T> *p = node->left;
	node->left = p->right;

	if (p->right != nullptr)
		p->right->parent = node;

	p->parent = node->parent;

	if (node->parent == nullptr)
		root = p;
	else
	{
		if (node == node->parent->right)
			node->parent->right = p;
		else
			node->parent->left = p;
	}

	p->right = node;
	node->parent = p;
}

//���뺯��
template<class T>
void RBTree<T>::insert(T key)
{
	RBNode<T> *p = new RBNode<T>(key, RED, nullptr, nullptr, nullptr);
	insert(mRoot, p);
}
template <class T>
void RBTree<T>::insert(RBNode<T> *&root, RBNode<T> *node)
{
	RBNode<T> *p = nullptr;
	RBNode<T> *t = root;
	while (t != nullptr)
	{
		p = t;
		if (node->value < t->value)
			t = t->left;
		else
			t = t->right;
	}

	node->parent = p;
	if (p != nullptr)
	{
		if (node->value < p->value)
			p->left = node;
		else
			p->right = node;
	}
	else
		root = node;
	node->color = RED;
	//�������
	insertFixUp(root, node);
}
template<class T>
void RBTree<T>::insertFixUp(RBNode<T>*&root, RBNode<T>*node)
{
	RBNode<T> *p, *gp;
	//
	vector<int, int>v;
	sort(v.begin(), v.end());

}




