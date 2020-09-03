#pragma once
#include <iostream>
#include <hash_map>

using namespace std;
//
//【题目】
//	LFU也是一个著名的缓存算法,自行了解之后实现LFU中的set 和 get
//	要求：两个方法的时间复杂度都为O(1)
//
//【题解】
//	LFU算法与LRU算法很像
//	但LRU是最新使用的排在使用频率最前面，也就是LRU是通过使用时间进行排序，
//	使用时间越新，其使用频率越高，而使用时间越久，其使用频率越低，即当空间满时，被删除的概率最大
//	而LFU是根据使用次数来算使用频率的，使用次数越多，其使用频率越高，使用次数越少，使用频率越低，当空间满时越容易被删除
//	同样，使用hash_map表和双向链表进行存储；
//	hash表存储关键词与双向链表的节点地址
//	而双向链表的数据存储的是使用次数，每种使用次数仍然是一个双向链表，
//	当put一个数据，则在使用次数为1的链表节点下的链表中按put顺序依次存储
//	当每get一个数据，若存在，而在相对应使用次数的链表节点中拿出，放在下一个链表节点下，即使用次数 + 1的节点
//	记住，在相同的使用次数中，是按照使用时间顺序进行存放的，
//	所以，当空间满时，首先删除大链表的头中的头，即使用次数为1的节点中的头结点【最早放入】，若使用次数都一样，同样是删除该使用次数节点中链表的 头节点
//	所以，数据存放于链表尾部，数据删除于链表的头部
//	还有，当某个链表节点为空，则删除，某个链表节点不存在，则新建
//	比如，当使用次数为2的节点中无数据，则删出该节点，
//	当有一个新数据的使用次数为2时，发现不存在使用次数为2的节点，那么就应该新建一个节点
//

struct Node//子链表
{
	int key;
	int val;
	int num;
	Node* next;
	Node* pre;
	Node(int a, int b, int n) :key(a), val(b), num(n), next(nullptr), pre(nullptr) {}
};

struct NodeList//主链表
{
	int num;
	Node* head;//子链表的头节点
	Node* tail;//子链表的尾结点
	NodeList* next;
	NodeList* pre;
	NodeList(int a) :num(a), next(nullptr), pre(nullptr)
	{
		head = new Node(0, 0, a);//新建一个子链表的头结点
		tail = head;
	}
};

class LFU
{
public:
	LFU(int size) :capacity(size) {}
	void set(int key, int value);
	int get(int key);
	
private:
	void getNode(Node*& p, NodeList*& h);//将节点从子链表中取出
	void moveNode(Node*& p, NodeList*& h);//将节点向后移动
	void deleteNode(int num, NodeList*& h);//删除子链表
	void createNode(Node*p, NodeList*& h);//新建子链表,并插入在主链中
	void updataNode(Node*& p, NodeList*& h);//更新函数的使用次数
	void deleteData();//容量不足需要删除

private:
	int capacity;
	NodeList* headList = new NodeList(0);//主链表的头结点
	hash_map<int, Node*>dataMap;//key  <——>  真实数据节点地址
	hash_map<int, NodeList*>headMap;//次数 <——>  链表头节点地址
};

void LFU::set(int key, int value)
{
	if (this->capacity == 0)
		return;
	if (dataMap.find(key) != dataMap.end())//已经存在
	{
		Node* p = dataMap[key];//找到数据节点
		NodeList* h = headMap[p->num];//找到头链表节点		
		p->val = value;

		updataNode(p, h);//更新数据的使用次数		
	}
	else//如果不存在，则新建
	{
		if (dataMap.size() >= this->capacity)//容量不足，需要删除数据
			deleteData();

		Node* p = new Node(key, value, 1);//使用用一次
		dataMap[key] = p;//记录

		//将新建节点插入使用1次的子链表中
		if (headMap.find(1) == headMap.end())//当使用1次的子链表不存在
			createNode(p, headList);
		else
			moveNode(p, headMap[1]);//插入在使用次数在1的子链表中
	}
}

int LFU::get(int key)
{
	if (dataMap.find(key) == dataMap.end())//数据不存在
		return -1;
	Node* p = dataMap[key];//找到数据节点
	NodeList* h = headMap[p->num];
	updataNode(p, h);

	return p->val;
}

void LFU::getNode(Node*& p, NodeList*& h)//将节点从子链表中取出
{
	p->pre->next = p->next;
	if (p->next == nullptr)
		h->tail = p->pre;
	else
		p->next->pre = p->pre;
}

void LFU::moveNode(Node*& p, NodeList*& q)//将节点向后移动
{
	p->next = q->tail->next;
	q->tail->next = p;
	p->pre = q->tail;
	q->tail = p;
}

void LFU::deleteNode(int num, NodeList*& h)//删除子链表
{
	headMap.erase(num);//从map中删除
	h->pre->next = h->next;
	if (h->next != nullptr)
		h->next->pre = h->pre;
	delete h;
	h = nullptr;
}


void LFU::createNode(Node*p, NodeList*& h)//新建子链表,并插入在主链中
{
	NodeList* q = new NodeList(p->num);//新建一个子链表
	headMap[p->num] = q;//保存对应的地址

	moveNode(p, q);////将节点放入子链表中		

	//将新子链插入主链表中
	q->next = h->next;
	if (h->next != nullptr)
		h->next->pre = q;
	h->next = q;
	q->pre = h;
}

void LFU::updataNode(Node*& p, NodeList*& h)//更新函数的使用次数
{
	int num = p->num;
	p->num++;//使用次数+1

	//将p从子链表中取出
	getNode(p, h);

	//将该数据向后面移动
	if (headMap.find(p->num) == headMap.end())//不存在num+1的节点,那么新建
		createNode(p, h);
	else
		moveNode(p, headMap[p->num]);////将节点放入子链表中	

	//如果该子链表为空，将该子链表删除,并从map中删除
	if (h->head == h->tail)
		deleteNode(num, h);
}

void LFU::deleteData()//容量不足需要删除
{
	NodeList* p = headList->next;
	Node* q = p->head->next;//删除子链表排在最前面的数据
	if (q == p->tail)//要删除的数据就是最后一个数据，则删除该节点和子链表
		deleteNode(q->num, p);
	else
	{
		p->head->next = q->next;
		q->next->pre = p->head;
	}
	dataMap.erase(q->key);//删除记录
	delete q;//删除
	q = nullptr;
}


void Test()
{
	LFU* f = new LFU(3);
	f->set(1, 11);
	f->set(2, 22);
	f->set(3, 33);
	cout << f->get(4) << endl;
	f->set(4, 44);
	cout << f->get(1) << endl;
	cout << f->get(2) << endl;
	cout << f->get(2) << endl;
	cout << f->get(2) << endl;
	cout << f->get(3) << endl;
	cout << f->get(3) << endl;
	cout << f->get(4) << endl;
	cout << f->get(4) << endl;
	cout << f->get(4) << endl;
	f->set(5, 55);
	cout << f->get(3) << endl;
	cout << f->get(5) << endl;

}