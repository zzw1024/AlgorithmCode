#pragma once
#include <iostream>
#include <hash_map>
#include <deque>

using namespace std;
//
//����Ŀ��
//���һ�ֻ���ṹ���ýṹ�ڹ���ʱȷ����С�������СΪK�������������ܣ�
//set(key, value)������¼(key, value)����ýṹ��
//get(key)������key��Ӧ��valueֵ��
//��Ҫ��
//	1��set��get������ʱ�临�Ӷ�ΪO(1)��
//	2��ĳ��key��set��get����һ����������Ϊ���key�ļ�¼�������ʹ�õġ�
//	3��������Ĵ�С����Kʱ���Ƴ������ʹ�õļ�¼����set��get���Զ�ġ�
//��������
//���軺��ṹ��ʵ����cache����СΪ3�������η���������Ϊ��
//	1��cache.set("A", 1)�����ʹ�õļ�¼Ϊ("A", 1)��
//	2��cache.set("B", 2)�����ʹ�õļ�¼Ϊ("B", 2)��("A", 1)��Ϊ������ġ�
//	3��cache.set("C", 3)�����ʹ�õļ�¼Ϊ("C", 3)��("A", 1)����������ġ�
//	4��cache.get("A")�����ʹ�õļ�¼Ϊ("A", 1)��("B", 2)��Ϊ������ġ�
//	5��cache.set("D", 4)����С������3�������Ƴ���ʱ�����ʹ�õļ�¼("B", 2)��
//	�����¼("D", 4)������Ϊ���ʹ�õļ�¼��Ȼ��("C", 3)��Ϊ�����ʹ�õ�
//	��¼
//
//����⡿
//	����������hash_map����Ϊhash�����ɾ�ò�ĸ��Ӷȶ�ΪO(1)
//	����ʹ��Ƶ��ʹ�ö��д洢��ʹ�õķ���ͷ����ʹ�õ��Զ�����ţ������ʹ�õ��ڶ�β
//	��ÿ�δӶ�����ȡ������ʹ�õ�����������ͷ���ĸ��Ӷ�ΪO(N),����������
//	����ֻ��ʹ��˫�����������д洢��
//	hash���д����ÿ�����ݽڵ�ĵ�ַ�������������������λ�õ������Ӷ�ΪO(1)
//	���ʹ�õ����ݽڵ��������β����������ʹ�õ��������β������Ϊ��������ʱ��Ҫ����ʹ�õģ�
//	�������β��������ӷ��㡣
//


#define M 5//����ռ�Ĵ�С
struct Node
{
	int val;//���ݴ��������У� �������ڱ���
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
	void update(Node* p);//����ʹ��Ƶ��
	hash_map<char, Node*>map;
	Node* head = new Node(' ', -1);//ָ�������ͷ
	Node* end = head;//ָ�������β
};

void Cash::update(Node* p)
{
	if (p == end)
		return;//p������β���Ͳ����ƶ���
	Node* q = p->pre;
	q->next = p->next;
	p->next->pre = q;
	end->next = p;
	p->pre = end;//����p��ʹ���ʣ���Ų������β��
	end = p;
}

void Cash::set(const char c, const int a)
{
	if (map.find(c) == map.end())//�����ھʹ���
	{
		if (this->map.size() == M)//����ռ�����
		{
			Node* p = this->head->next;
			this->head->next = p->next;//ɾ��λ������ͷ��������õĽڵ�
			if (p->next == nullptr)//ֻ��һ������
				end = head;
			else
				p->next->pre = head;
			map.erase(p->c);//�ӱ���ɾ�����������ռ�
			delete p;
		}
		Node* p = new Node(c, a);//�²��������������β
		this->end->next = p;
		p->pre = end;
		end = p;
		map[c] = p;//��������
	}
	else//���ڣ���Ҫ��������ʹ��Ƶ��
	{
		Node* p = map[c];//�õ��������е�λ��
		p->val = a;//��������ֵ
		update(p);//����ʹ��Ƶ��
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
	update(p);//����ʹ��Ƶ��
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
