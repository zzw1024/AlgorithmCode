#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
	string str;
	Node* next;
	Node(string s = "") :str(s), next(NULL) {}
};

//Problem:
//	����Ŀ�� ���һ��ֽ�����ŷ��������ϣ�Ȼ���ֽ�����±���
//	�Ϸ�����1�Σ�ѹ���ۺۺ�չ������ʱ �ۺ��ǰ���ȥ�ģ����ۺ�
//	ͻ��ķ���ָ��ֽ���ı��档�����ֽ�����±����Ϸ���������
//	2 �Σ�ѹ���ۺۺ�չ������ʱ�������ۺۣ����ϵ�������������
//	�ۡ����ۺۺ����ۺۡ�
//	����һ ���������N������ֽ�������±����Ϸ���������N�Σ�
//	����ϵ��´�ӡ�����ۺ۵ķ��� ���磺N = 1ʱ����ӡ�� down
//	N = 2ʱ����ӡ�� down down up
//
//Solution:
//	���ȣ������ۺ۴����Ǻܺ���ģ�һ����2^0 + 2^1 + ...+ 2^N
//	�����ۺ۴���Ҳ�ܺ��㣬��һ�������ۺۣ�Ȼ�������ۺ����ƽ�����ۺ���������ۺ۶�һ��
//	���ǲ�֪����ôʹ�õݹ�
//	�����ҵ������ˣ���������һ���ۺ۵ļ�϶���β����¡���n��
//	���磺
//		��2���ۺ�Ϊ��   ��    ��    ��
//		��3���ۺ�Ϊ����    ��    ��    ��
//		����         �� �� �� �� �� �� ��

Node* ZheZhi01(const int N)//�ǵݹ鷽ʽ,ʹ��������������
{
	Node* head = new Node("");
	Node* p;
	for (int i = 1; i <= N; ++i)
	{
		p = head;
		if (i == 1)//��һ���ۺ�
		{
			Node* q = new Node("down");
			q->next = p->next;
			p->next = q;
			p = p->next->next;
		}		
		while(p)
		{
			Node* q1 = new Node("down");
			q1->next = p->next;
			p->next = q1;
			p = p->next->next;

			Node* q2 = new Node("up");
			q2->next = p->next;
			p->next = q2;
			p = p->next->next;
		}

	}
	return head;
}

void ZheZhi02(const int N, int i, bool down)//ʹ�õݹ鷽ʽ
{
	if (i > N)
		return;
	ZheZhi02(N, i + 1, true);
	if (down)
		cout << "down" << '\t';
	else
		cout << "up" << '\t';
	ZheZhi02(N, i + 1, false);
}


void Test()
{
	int N;
	cout << "��������ֽ���� N: ";
	cin >> N;

	ZheZhi02(N, 1, true);


	Node* head = NULL;
	head = ZheZhi01(N);
	Node* p = head->next;
	cout << "��ֽ��Ϊ��" << endl;
	while (p)
	{
		cout << p->str << "\t";
		p = p->next;
	}
	cout << endl;

}