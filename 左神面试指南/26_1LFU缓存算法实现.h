#pragma once
#include <iostream>
#include <hash_map>

using namespace std;
//
//����Ŀ��
//	LFUҲ��һ�������Ļ����㷨,�����˽�֮��ʵ��LFU�е�set �� get
//	Ҫ������������ʱ�临�Ӷȶ�ΪO(1)
//
//����⡿
//	LFU�㷨��LRU�㷨����
//	��LRU������ʹ�õ�����ʹ��Ƶ����ǰ�棬Ҳ����LRU��ͨ��ʹ��ʱ���������
//	ʹ��ʱ��Խ�£���ʹ��Ƶ��Խ�ߣ���ʹ��ʱ��Խ�ã���ʹ��Ƶ��Խ�ͣ������ռ���ʱ����ɾ���ĸ������
//	��LFU�Ǹ���ʹ�ô�������ʹ��Ƶ�ʵģ�ʹ�ô���Խ�࣬��ʹ��Ƶ��Խ�ߣ�ʹ�ô���Խ�٣�ʹ��Ƶ��Խ�ͣ����ռ���ʱԽ���ױ�ɾ��
//	ͬ����ʹ��hash_map���˫��������д洢��
//	hash��洢�ؼ�����˫������Ľڵ��ַ
//	��˫����������ݴ洢����ʹ�ô�����ÿ��ʹ�ô�����Ȼ��һ��˫������
//	��putһ�����ݣ�����ʹ�ô���Ϊ1������ڵ��µ������а�put˳�����δ洢
//	��ÿgetһ�����ݣ������ڣ��������Ӧʹ�ô���������ڵ����ó���������һ������ڵ��£���ʹ�ô��� + 1�Ľڵ�
//	��ס������ͬ��ʹ�ô����У��ǰ���ʹ��ʱ��˳����д�ŵģ�
//	���ԣ����ռ���ʱ������ɾ���������ͷ�е�ͷ����ʹ�ô���Ϊ1�Ľڵ��е�ͷ��㡾������롿����ʹ�ô�����һ����ͬ����ɾ����ʹ�ô����ڵ�������� ͷ�ڵ�
//	���ԣ����ݴ��������β��������ɾ���������ͷ��
//	���У���ĳ������ڵ�Ϊ�գ���ɾ����ĳ������ڵ㲻���ڣ����½�
//	���磬��ʹ�ô���Ϊ2�Ľڵ��������ݣ���ɾ���ýڵ㣬
//	����һ�������ݵ�ʹ�ô���Ϊ2ʱ�����ֲ�����ʹ�ô���Ϊ2�Ľڵ㣬��ô��Ӧ���½�һ���ڵ�
//

struct Node//������
{
	int key;
	int val;
	int num;
	Node* next;
	Node* pre;
	Node(int a, int b, int n) :key(a), val(b), num(n), next(nullptr), pre(nullptr) {}
};

struct NodeList//������
{
	int num;
	Node* head;//�������ͷ�ڵ�
	Node* tail;//�������β���
	NodeList* next;
	NodeList* pre;
	NodeList(int a) :num(a), next(nullptr), pre(nullptr)
	{
		head = new Node(0, 0, a);//�½�һ���������ͷ���
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
	void getNode(Node*& p, NodeList*& h);//���ڵ����������ȡ��
	void moveNode(Node*& p, NodeList*& h);//���ڵ�����ƶ�
	void deleteNode(int num, NodeList*& h);//ɾ��������
	void createNode(Node*p, NodeList*& h);//�½�������,��������������
	void updataNode(Node*& p, NodeList*& h);//���º�����ʹ�ô���
	void deleteData();//����������Ҫɾ��

private:
	int capacity;
	NodeList* headList = new NodeList(0);//�������ͷ���
	hash_map<int, Node*>dataMap;//key  <����>  ��ʵ���ݽڵ��ַ
	hash_map<int, NodeList*>headMap;//���� <����>  ����ͷ�ڵ��ַ
};

void LFU::set(int key, int value)
{
	if (this->capacity == 0)
		return;
	if (dataMap.find(key) != dataMap.end())//�Ѿ�����
	{
		Node* p = dataMap[key];//�ҵ����ݽڵ�
		NodeList* h = headMap[p->num];//�ҵ�ͷ����ڵ�		
		p->val = value;

		updataNode(p, h);//�������ݵ�ʹ�ô���		
	}
	else//��������ڣ����½�
	{
		if (dataMap.size() >= this->capacity)//�������㣬��Ҫɾ������
			deleteData();

		Node* p = new Node(key, value, 1);//ʹ����һ��
		dataMap[key] = p;//��¼

		//���½��ڵ����ʹ��1�ε���������
		if (headMap.find(1) == headMap.end())//��ʹ��1�ε�����������
			createNode(p, headList);
		else
			moveNode(p, headMap[1]);//������ʹ�ô�����1����������
	}
}

int LFU::get(int key)
{
	if (dataMap.find(key) == dataMap.end())//���ݲ�����
		return -1;
	Node* p = dataMap[key];//�ҵ����ݽڵ�
	NodeList* h = headMap[p->num];
	updataNode(p, h);

	return p->val;
}

void LFU::getNode(Node*& p, NodeList*& h)//���ڵ����������ȡ��
{
	p->pre->next = p->next;
	if (p->next == nullptr)
		h->tail = p->pre;
	else
		p->next->pre = p->pre;
}

void LFU::moveNode(Node*& p, NodeList*& q)//���ڵ�����ƶ�
{
	p->next = q->tail->next;
	q->tail->next = p;
	p->pre = q->tail;
	q->tail = p;
}

void LFU::deleteNode(int num, NodeList*& h)//ɾ��������
{
	headMap.erase(num);//��map��ɾ��
	h->pre->next = h->next;
	if (h->next != nullptr)
		h->next->pre = h->pre;
	delete h;
	h = nullptr;
}


void LFU::createNode(Node*p, NodeList*& h)//�½�������,��������������
{
	NodeList* q = new NodeList(p->num);//�½�һ��������
	headMap[p->num] = q;//�����Ӧ�ĵ�ַ

	moveNode(p, q);////���ڵ������������		

	//��������������������
	q->next = h->next;
	if (h->next != nullptr)
		h->next->pre = q;
	h->next = q;
	q->pre = h;
}

void LFU::updataNode(Node*& p, NodeList*& h)//���º�����ʹ�ô���
{
	int num = p->num;
	p->num++;//ʹ�ô���+1

	//��p����������ȡ��
	getNode(p, h);

	//��������������ƶ�
	if (headMap.find(p->num) == headMap.end())//������num+1�Ľڵ�,��ô�½�
		createNode(p, h);
	else
		moveNode(p, headMap[p->num]);////���ڵ������������	

	//�����������Ϊ�գ�����������ɾ��,����map��ɾ��
	if (h->head == h->tail)
		deleteNode(num, h);
}

void LFU::deleteData()//����������Ҫɾ��
{
	NodeList* p = headList->next;
	Node* q = p->head->next;//ɾ��������������ǰ�������
	if (q == p->tail)//Ҫɾ�������ݾ������һ�����ݣ���ɾ���ýڵ��������
		deleteNode(q->num, p);
	else
	{
		p->head->next = q->next;
		q->next->pre = p->head;
	}
	dataMap.erase(q->key);//ɾ����¼
	delete q;//ɾ��
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