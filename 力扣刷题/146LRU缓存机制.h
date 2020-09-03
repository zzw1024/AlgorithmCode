//#pragma once
//#include "_000库函数.h"
//
//class LRUCache {
//public:
//	LRUCache(int capacity) {
//		this->capacity = capacity;
//	}
//
//	int get(int key) {
//		if (map.find(key) == map.end())
//			return -1;
//		Node* p = map[key];
//		update(p);//更新使用频率
//		return p->val;
//	}
//
//	void put(int key, int value) {
//		if (map.find(key) == map.end())//不存在就存入
//		{
//			if (this->map.size() == this->capacity)//缓存空间已满
//			{
//				Node* p = this->head->next;
//				this->head->next = p->next;//删除位于链表头部的最不常用的节点
//				if (p->next == nullptr)//只有一个数据
//					end = head;
//				else
//					p->next->pre = head;
//				map.erase(p->key);//从表中删除，以留出空间				
//				delete p;
//			}
//			Node* p = new Node(key, value);//新插入的数据在链表尾
//			this->end->next = p;
//			p->pre = end;
//			end = p;
//			map[key] = p;//存入数据
//		}
//		else//存在，但要更新数的使用频率
//		{
//			Node* p = map[key];//得到在链表中的位置
//			p->val = value;//更新数据值
//			update(p);//更新使用频率
//		}
//	}
//
//private:
//	struct Node
//	{
//		int key;
//		int val;
//		Node* pre;
//		Node* next;
//		Node(int k, int v) :key(k), val(v), pre(nullptr), next(nullptr) {}
//	};
//
//	int capacity = 0;
//	hash_map<int, Node*>map;
//	Node* head = new Node(' ', -1);//指向链表的头
//	Node* end = head;//指向链表的尾
//	void update(Node* p)
//	{
//		if (p == end)
//			return;//p在链表尾部就不用移动了
//		Node* q = p->pre;
//		q->next = p->next;
//		p->next->pre = q;
//		end->next = p;
//		p->pre = end;//更新p的使用率，并挪至链表尾部
//		end = p;
//	}
//};
//
///**
// * Your LRUCache object will be instantiated and called as such:
// * LRUCache* obj = new LRUCache(capacity);
// * int param_1 = obj->get(key);
// * obj->put(key,value);
// */
//
//void Test()
//{
//	LRUCache* rr = new LRUCache(1);
//	rr->put(2, 1);
//	cout << rr->get(2) << endl;
//	rr->put(2, 2);
//	cout << rr->get(2) << endl;
//	rr->get(2);
//	rr->put(3, 2);
//	rr->get(2);
//	rr->get(3);
//	
//
//}