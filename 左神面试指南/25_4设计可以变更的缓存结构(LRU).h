#pragma once
#include <iostream>
#include <hash_map>
#include <deque>

using namespace std;
//
//【题目】
//设计一种缓存结构，该结构在构造时确定大小，假设大小为K，并有两个功能：
//set(key, value)：将记录(key, value)插入该结构。
//get(key)：返回key对应的value值。
//【要求】
//	1．set和get方法的时间复杂度为O(1)。
//	2．某个key的set或get操作一旦发生，认为这个key的记录成了最经常使用的。
//	3．当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
//【举例】
//假设缓存结构的实例是cache，大小为3，并依次发生如下行为：
//	1．cache.set("A", 1)。最经常使用的记录为("A", 1)。
//	2．cache.set("B", 2)。最经常使用的记录为("B", 2)，("A", 1)变为最不经常的。
//	3．cache.set("C", 3)。最经常使用的记录为("C", 3)，("A", 1)还是最不经常的。
//	4．cache.get("A")。最经常使用的记录为("A", 1)，("B", 2)变为最不经常的。
//	5．cache.set("D", 4)。大小超过了3，所以移除此时最不经常使用的记录("B", 2)，
//	加入记录("D", 4)，并且为最经常使用的记录，然后("C", 3)变为最不经常使用的
//	记录
//
//【题解】
//	储存数据用hash_map，因为hash表的增删该查的复杂度都为O(1)
//	本来使用频率使用队列存储，使用的放在头，不使用的自动向后排，最不经常使用的在队尾
//	但每次从队列中取出正在使用的数据至队列头部的复杂度为O(N),不满足条件
//	所以只能使用双向链表来进行存储，
//	hash表中存放着每个数据节点的地址参数，故链表的中数据位置调整复杂度为O(1)
//	最经常使用的数据节点在链表的尾部，不经常使用的在链表的尾部，因为缓存数据时需要经常使用的，
//	而链表的尾部插入更加方便。
//


#define M 5//缓存空间的大小
struct Node
{
	int val;//数据存在链表中， 索引存在表中
	char c;
	Node* pre;
	Node* next;
	Node(char c, int a) :c(c), val(a), pre(nullptr), next(nullptr) {}
};

class Cash
{
public:
	void set(const char c, const int a);
	int get(const char c);

private:
	void update(Node* p);//更新使用频率
	hash_map<char, Node*>map;
	Node* head = new Node(' ', -1);//指向链表的头
	Node* end = head;//指向链表的尾
};

void Cash::update(Node* p)
{
	if (p == end)
		return;//p在链表尾部就不用移动了
	Node* q = p->pre;
	q->next = p->next;
	p->next->pre = q;
	end->next = p;
	p->pre = end;//更新p的使用率，并挪至链表尾部
	end = p;
}

void Cash::set(const char c, const int a)
{
	if (map.find(c) == map.end())//不存在就存入
	{
		if (this->map.size() == M)//缓存空间已满
		{
			Node* p = this->head->next;
			this->head->next = p->next;//删除位于链表头部的最不常用的节点
			if (p->next == nullptr)//只有一个数据
				end = head;
			else
				p->next->pre = head;
			map.erase(p->c);//从表中删除，以留出空间
			delete p;
		}
		Node* p = new Node(c, a);//新插入的数据在链表尾
		this->end->next = p;
		p->pre = end;
		end = p;
		map[c] = p;//存入数据
	}
	else//存在，但要更新数的使用频率
	{
		Node* p = map[c];//得到在链表中的位置
		p->val = a;//更新数据值
		update(p);//更新使用频率
	}
}


int Cash::get(const char c)
{
	if (map.find(c) == map.end())
	{
		cout << "the data is not existe!" << endl;
		return -1;
	}
	Node* p = map[c];
	update(p);//更新使用频率
	return p->val;
}


void Test()
{
	Cash v;
	v.set('A', 1);
	v.set('B', 2);
	v.set('C', 3);
	v.set('D', 4);
	v.set('E', 5);
	v.set('F', 6);
	cout << v.get('A') << endl;

	cout << v.get('B') << endl;
	v.set('G', 7);
	cout << v.get('B') << endl;
	cout << v.get('C') << endl;


}
