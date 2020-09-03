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
//	【题目】 请把一段纸条竖着放在桌子上，然后从纸条的下边向
//	上方对折1次，压出折痕后展开。此时 折痕是凹下去的，即折痕
//	突起的方向指向纸条的背面。如果从纸条的下边向上方连续对折
//	2 次，压出折痕后展开，此时有三条折痕，从上到下依次是下折
//	痕、下折痕和上折痕。
//	给定一 个输入参数N，代表纸条都从下边向上方连续对折N次，
//	请从上到下打印所有折痕的方向。 例如：N = 1时，打印： down
//	N = 2时，打印： down down up
//
//Solution:
//	首先，计算折痕次数是很好算的，一共是2^0 + 2^1 + ...+ 2^N
//	上下折痕次数也很好算，第一次是下折痕，然后上下折横次数平分总折横次数，下折痕多一次
//	但是不知道怎么使用递归
//	但是找到规律了，就是在上一次折痕的间隙依次插入下、上n次
//	比如：
//		第2次折痕为：   下    下    上
//		第3次折痕为：下    上    下    上
//		即：         下 下 上 下 下 上 上

Node* ZheZhi01(const int N)//非递归方式,使用链表插入更方便
{
	Node* head = new Node("");
	Node* p;
	for (int i = 1; i <= N; ++i)
	{
		p = head;
		if (i == 1)//第一次折横
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

void ZheZhi02(const int N, int i, bool down)//使用递归方式
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
	cout << "请输入折纸次数 N: ";
	cin >> N;

	ZheZhi02(N, 1, true);


	Node* head = NULL;
	head = ZheZhi01(N);
	Node* p = head->next;
	cout << "折纸痕为：" << endl;
	while (p)
	{
		cout << p->str << "\t";
		p = p->next;
	}
	cout << endl;

}