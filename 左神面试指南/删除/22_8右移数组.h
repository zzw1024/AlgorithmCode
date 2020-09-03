#pragma once
#include <iostream>
#include <string>

using namespace std;
//
//Problem��
//����һ���ַ�����ʵ�Ǹ�ѭ�����飬����ѭ�����ơ�
//	���硱	abc	��	��
//	����ѭ������һλ���õ���	cab��	��
//	����ѭ��������λ���õ���bca	��	��
//	����ѭ��������λ���õ���	abc	��	��
//	���������ַ���str1��str2���ж�str2�ǲ�����str1ѭ�����Ƶõ��ġ�
//
//Solution��
//	1��������1ʹ�û�������洢��Ȼ��������һһ�Աȼ���
//	2��ֱ�ӶԱȣ����ҵ���ͬ��ͷ����Ȼ������һһ�Աȣ�����ĩβ���ͷ��ʼ
//	3��
//

struct Node
{
	char c;
	Node* next;
	Node(char c) :c(c), next(nullptr) {}
};

bool isSame1(string str1, string str2)//ʹ�û�������
{
	if (str1.length() != str2.length())
		return false;
	Node* head = new Node('#');
	Node*p = head;
	for (int i = 0; i < str1.length(); ++i)
	{
		Node* q = new Node(str1[i]);
		p->next = q;
		p = q;
	}
	p->next = head->next;//�γɻ�
	p = head->next;
	while (p->c != str2[0])//�ҵ�ͷ
	{
		p = p->next;
		if (p == head->next)
			return false;//��ͷ��ĸ���Ҳ�����ͬ��
	}
	for (int i = 0; i < str2.length(); ++i)//��ʼһһ�Ա�
	{
		if (p->c != str2[i])
			return false;
		p = p->next;
	}
	return true;
}


bool isSame2(string str1, string str2)//ֱ�ӶԱ�
{
	if (str1.length() != str2.length())
		return false;
	int i;
	for (i = 0; i < str1.length(); ++i)//�ҵ���ͬ��ͷ
	{
		if (str2[0] == str1[i])
			break;
	}
	if (i >= str1.length())
		return false;//��ͷ��ĸ���Ҳ�����ͬ��
	for (int j = 0; j < str2.length(); ++j,++i)//�ҵ���ͬ��ͷ
	{
		if (i == str1.length())
			i = 0;//�������β����ͷ��ʼ
		if (str2[j] != str1[i])
			return false;//���ֲ�ͬ�ͷ���
	}
	return true;

}

void Test()
{
	string str1;
	string str2;
	str1 = "abcde";
	str2 = "cdeab";
	cout << isSame1(str1, str2) << endl;
	cout << isSame2(str1, str2) << endl;

	str1 = "abcde";
	str2 = "cdfab";
	cout << isSame1(str1, str2) << endl;
	cout << isSame2(str1, str2) << endl;
}