#pragma once
#include <iostream>
#include <hash_map>
#include <time.h>
#include <list>

using namespace std;

//【题目】
//跳表实现
//
//【题解】
//功能与红黑树类似
//key - value
//每个数据有一个层数
//利用随机函数来判断决定有多少层数
//而随机函数是等概率的产生0 / 1，
//当第n次才产生1则该数节点层数为n
//
//最开始会产生一个系统最小层数
//当插入一个新的数据N，从系统最小的最上一层开始查找，
//当该节点右边的数比N大则从该节点的下面走，否则向右边走。
//当M节点自己比N小，但右边的数比N大且M的层数 == N的层数，那么N应该插在M的右边
//
//
//当要插入数据N是最大时，且层数比系统最小层数要高，则系统最小扩层 == N的层数
//其新建节点 == nullptr， 将nullptr视为最大值，那么N值应该插在系统最小到nullptr之间


class JumpTable
{
public:
	void add(int num);
	int get();


private:
	struct Node
	{
		int val;
		list<Node*>lis;
		Node(int a) :val(a) {}
	};





};
