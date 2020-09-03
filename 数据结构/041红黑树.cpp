#include "000库函数.h"


enum RBTColor {RED, BLACK};

template<class T>
class RBNode
{
public:
	RBTColor color;//颜色
	T value; //值
	RBNode *left;//左孩子
	RBNode *right;//右孩子
	RBNode *parent;//父节点

	RBNode(T v, RBTColor c, RBNode *p, RBNode *l, RBNode *r) :
		value(v), color(c), parent(p), left(l), right(r) {}
};

template <class T>
class RBTree
{
private: 
	RBNode<T> *mRoot;//整棵树的根节点

public:
	RBTree();
	~RBTree();

	//前序遍历
	void preOrder();
	//中序遍历
	void inOrder();
	//后序遍历
	void postOrder();

	//查找
	RBNode<T> *search(T key);

	//最小值
	T getMin();
	//最大值
	T getMax();

	//前驱节点，即左子树最右叶节点
	RBNode<T> *getPreNode(RBNode *root);
	//后继节点，即右子树最左节点
	RBNode<T> *getPostNode(RBNode *root);

	//插入
	void insert(T key);
	//删除
	void remove(T key);
	//销毁
	void destroy();
	//打印
	void print();

private:
	//前序遍历
	void preOrder(RBNode<T> *root) const;
	//中序遍历
	void inOrder(RBNode<T> *root) const;
	//后序遍历
	void postOrder(RBNode<T> *root) const;

	//最小值
	RBNode<T> *getMin(RBNode<T> *root) const;
	//最大值
	RBNode<T> *getMax(RBNode<T> *root) const;

	//查找
	RBNode<T> *search(RBNode<T> *root, T key) const;
	
	//左旋
	void rateLeft(RBNode<T> *&root, RBNode<T> *node);
	//右旋
	void rateRight(RBNode<T> *&root, RBNode<T> *node);

	//插入
	void insert(RBNode<T> *&root, RBNode<T> *x);
	//插入修正函数
	void insertFixUp(RBNode<T> *&root, RBNode<T> *x);

	//删除
	void remove(RBNode<T> *&root, RBNode<T> *x);
	//删除修正函数
	void removeFixUp(RBNode<T> *&root, RBNode<T> *x);

	//销毁
	void destroy(RBNode *&tree);
	
	//打印
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

//构造函数
template <class T>
RBTree<T>::RBTree()
{
	mRoot = nullptr;
}
//析构函数
template<class T>
RBTree<T>::~RBTree()
{
	destroy();
}

//前序遍历
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
//中序遍历
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
//后序遍历
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

//搜索
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

//最小值
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

//最大值
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

//前驱节点，即左子树最右叶节点
template<class T>
RBNode<T> *RBTree<T>::getPreNode(RBNode<T> *root)
{
	if (root->left)return getMax(root->left);
	//如果root为一个左节点,则其拥有左子树的最低父节点就是其前驱节点
	//如果root为一个右节点，则其父节点就是其前驱节点
	RBNode<T> *p = root->parent;
	while (p != nullptr && root==p->left)
	{
		root = p;
		p = p->parent;
	}
	return p;
}
//后继节点，即右子树最左节点
template<class T>
RBNode<T> *RBTree<T>::getPostNode(RBNode<T> *root)
{
	if (root->right != nullptr)return getMin(root->right);
	//如果root为一个右孩子，则找到最低的父节点，且父节点必须有左孩子
	//如果root为一个左孩子，则其父节点就是他的后继节点
	RBNode<T>*p = root->parent;
	while (p != nullptr && x == p->right)
	{
		root = p;
		p = p->parent;
	}
	return p;
}

//左旋
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

//右旋
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

//插入函数
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
	//插入调整
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




