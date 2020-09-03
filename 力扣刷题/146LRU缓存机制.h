//#pragma once
//#include "_000�⺯��.h"
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
//		update(p);//����ʹ��Ƶ��
//		return p->val;
//	}
//
//	void put(int key, int value) {
//		if (map.find(key) == map.end())//�����ھʹ���
//		{
//			if (this->map.size() == this->capacity)//����ռ�����
//			{
//				Node* p = this->head->next;
//				this->head->next = p->next;//ɾ��λ������ͷ��������õĽڵ�
//				if (p->next == nullptr)//ֻ��һ������
//					end = head;
//				else
//					p->next->pre = head;
//				map.erase(p->key);//�ӱ���ɾ�����������ռ�				
//				delete p;
//			}
//			Node* p = new Node(key, value);//�²��������������β
//			this->end->next = p;
//			p->pre = end;
//			end = p;
//			map[key] = p;//��������
//		}
//		else//���ڣ���Ҫ��������ʹ��Ƶ��
//		{
//			Node* p = map[key];//�õ��������е�λ��
//			p->val = value;//��������ֵ
//			update(p);//����ʹ��Ƶ��
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
//	Node* head = new Node(' ', -1);//ָ�������ͷ
//	Node* end = head;//ָ�������β
//	void update(Node* p)
//	{
//		if (p == end)
//			return;//p������β���Ͳ����ƶ���
//		Node* q = p->pre;
//		q->next = p->next;
//		p->next->pre = q;
//		end->next = p;
//		p->pre = end;//����p��ʹ���ʣ���Ų������β��
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