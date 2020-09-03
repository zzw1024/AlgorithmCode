//#pragma once
//#include <iostream>
//#include <map>
//
//using namespace std;
//
//
////设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
////
////get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 - 1。
////put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
////
////进阶：
////你是否可以在 O(1) 时间复杂度内执行两项操作？
////
////示例：
////
////LFUCache cache = new LFUCache(2 /* capacity (缓存容量) */);
////
////cache.put(1, 1);
////cache.put(2, 2);
////cache.get(1);       // 返回 1
////cache.put(3, 3);    // 去除 key 2
////cache.get(2);       // 返回 -1 (未找到key 2)
////cache.get(3);       // 返回 3
////cache.put(4, 4);    // 去除 key 1
////cache.get(1);       // 返回 -1 (未找到 key 1)
////cache.get(3);       // 返回 3
////cache.get(4);       // 返回 4
//
//class LFUCache {
//public:
//	LFUCache(int capacity) {
//		this->capacity = capacity;
//	}
//
//	int get(int key) {
//		if (dataMap.find(key) == dataMap.end())//数据不存在
//			return -1;
//		Node* p = dataMap[key];//找到数据节点
//		NodeList* h = headMap[p->num];
//		updataNode(p, h);
//
//		return p->val;
//	}
//
//	void put(int key, int value) {
//		if (capacity == 0)
//			return;
//		if (dataMap.find(key) != dataMap.end())//已经存在
//		{
//			Node* p = dataMap[key];//找到数据节点
//			NodeList* h = headMap[p->num];//找到头链表节点		
//			p->val = value;
//
//			updataNode(p, h);//更新数据的使用次数		
//		}
//		else//如果不存在，则新建
//		{
//			if (dataMap.size() >= this->capacity)//容量不足，需要删除数据
//				deleteData();
//
//			Node* p = new Node(key, value, 1);//使用用一次
//			dataMap[key] = p;//记录
//
//			//将新建节点插入使用1次的子链表中
//			if (headMap.find(1) == headMap.end())//当使用1次的子链表不存在
//				createNode(p, headList);
//			else
//				moveNode(p, headMap[1]);//插入在使用次数在1的子链表中
//		}
//	}
//
//private:
//	struct Node//子链表
//	{
//		int key;
//		int val;
//		int num;
//		Node* next;
//		Node* pre;
//		Node(int a, int b, int n) :key(a), val(b), num(n), next(nullptr), pre(nullptr) {}
//	};
//
//	struct NodeList//主链表
//	{
//		int num;
//		Node* head;//子链表的头节点
//		Node* tail;//子链表的尾结点
//		NodeList* next;
//		NodeList* pre;
//		NodeList(int a) :num(a), next(nullptr), pre(nullptr)
//		{
//			head = new Node(0, 0, a);//新建一个子链表的头结点
//			tail = head;
//		}
//	};
//
//private:
//	void getNode(Node*& p, NodeList*& h)//将节点从子链表中取出
//	{
//		p->pre->next = p->next;
//		if (p->next == nullptr)
//			h->tail = p->pre;
//		else
//			p->next->pre = p->pre;
//	}
//	void moveNode(Node*& p, NodeList*& q)//将节点向后移动
//	{
//		p->next = q->tail->next;
//		q->tail->next = p;
//		p->pre = q->tail;
//		q->tail = p;
//	}
//	void deleteNode(int num, NodeList*& h)//删除子链表
//	{
//		headMap.erase(num);//从map中删除
//		h->pre->next = h->next;
//		if (h->next != nullptr)
//			h->next->pre = h->pre;
//		delete h;
//		h = nullptr;
//	}
//	void createNode(Node*p, NodeList*& h)//新建子链表,并插入在主链中
//	{
//		NodeList* q = new NodeList(p->num);//新建一个子链表
//		headMap[p->num] = q;//保存对应的地址
//
//		moveNode(p, q);////将节点放入子链表中		
//
//		//将新子链插入主链表中
//		q->next = h->next;
//		if (h->next != nullptr)
//			h->next->pre = q;
//		h->next = q;
//		q->pre = h;
//	}
//	void updataNode(Node*& p, NodeList*& h)//更新函数的使用次数
//	{
//		int num = p->num;
//		p->num++;//使用次数+1
//
//		//将p从子链表中取出
//		getNode(p, h);
//
//		//将该数据向后面移动
//		if (headMap.find(p->num) == headMap.end())//不存在num+1的节点,那么新建
//			createNode(p, h);
//		else
//			moveNode(p, headMap[p->num]);////将节点放入子链表中	
//
//		//如果该子链表为空，将该子链表删除,并从map中删除
//		if (h->head == h->tail)
//			deleteNode(num, h);
//	}
//	void deleteData()//容量不足需要删除
//	{
//		NodeList* p = headList->next;
//		Node* q = p->head->next;//删除子链表排在最前面的数据
//		if (q == p->tail)//要删除的数据就是最后一个数据，则删除该节点和子链表
//			deleteNode(q->num, p);
//		else
//		{
//			p->head->next = q->next;
//			q->next->pre = p->head;
//		}
//		dataMap.erase(q->key);//删除记录
//		delete q;//删除
//		q = nullptr;
//	}
//
//private:
//	int capacity;
//	NodeList* headList = new NodeList(0);//主链表的头结点
//	map<int, Node*>dataMap;//key  <——>  真实数据节点地址
//	map<int, NodeList*>headMap;//次数 <——>  链表头节点地址
//};
//
///**
// * Your LFUCache object will be instantiated and called as such:
// * LFUCache* obj = new LFUCache(capacity);
// * int param_1 = obj->get(key);
// * obj->put(key,value);
// */
//
//void Test()
//{
//	LFUCache* f = new LFUCache(3);
//	f->put(1, 1);
//	f->put(2, 2);
//	f->put(3, 3);
//	f->put(4, 4);
//	cout << f->get(4) << endl;
//	cout << f->get(3) << endl;
//	cout << f->get(2) << endl;
//	cout << f->get(1) << endl;
//	f->put(5, 5);
//	cout << f->get(1) << endl;
//	cout << f->get(2) << endl;
//	cout << f->get(3) << endl;
//	cout << f->get(4) << endl;
//	cout << f->get(5) << endl;
//
//
//}