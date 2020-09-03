#pragma once
#include <iostream>
#include <string>

using namespace std;
//
//Problem：
//想想一个字符串其实是个循环数组，可以循环右移。
//	比如”	abc	”	，
//	向右循环右移一位，得到”	cab”	，
//	向右循环右移两位，得到“bca	”	，
//	向右循环右移三位，得到“	abc	”	，
//	给定两个字符串str1和str2，判断str2是不是由str1循环右移得到的。
//
//Solution：
//	1、将数组1使用环形链表存储，然后与数组一一对比即可
//	2、直接对比，先找到相同的头部，然后右移一一对比，到达末尾则从头开始
//	3、
//

struct Node
{
	char c;
	Node* next;
	Node(char c) :c(c), next(nullptr) {}
};

bool isSame1(string str1, string str2)//使用环形链表
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
	p->next = head->next;//形成环
	p = head->next;
	while (p->c != str2[0])//找到头
	{
		p = p->next;
		if (p == head->next)
			return false;//连头字母都找不到相同的
	}
	for (int i = 0; i < str2.length(); ++i)//开始一一对比
	{
		if (p->c != str2[i])
			return false;
		p = p->next;
	}
	return true;
}


bool isSame2(string str1, string str2)//直接对比
{
	if (str1.length() != str2.length())
		return false;
	int i;
	for (i = 0; i < str1.length(); ++i)//找到相同的头
	{
		if (str2[0] == str1[i])
			break;
	}
	if (i >= str1.length())
		return false;//连头字母都找不到相同的
	for (int j = 0; j < str2.length(); ++j,++i)//找到相同的头
	{
		if (i == str1.length())
			i = 0;//向后移至尾，从头开始
		if (str2[j] != str1[i])
			return false;//出现不同就返回
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