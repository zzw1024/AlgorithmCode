#pragma once
#include <iostream>
#include <hash_map>
#include <time.h>
#include <list>

using namespace std;

//����Ŀ��
//����ʵ��
//
//����⡿
//��������������
//key - value
//ÿ��������һ������
//��������������жϾ����ж��ٲ���
//����������ǵȸ��ʵĲ���0 / 1��
//����n�βŲ���1������ڵ����Ϊn
//
//�ʼ�����һ��ϵͳ��С����
//������һ���µ�����N����ϵͳ��С������һ�㿪ʼ���ң�
//���ýڵ��ұߵ�����N����Ӹýڵ�������ߣ��������ұ��ߡ�
//��M�ڵ��Լ���NС�����ұߵ�����N����M�Ĳ��� == N�Ĳ�������ôNӦ�ò���M���ұ�
//
//
//��Ҫ��������N�����ʱ���Ҳ�����ϵͳ��С����Ҫ�ߣ���ϵͳ��С���� == N�Ĳ���
//���½��ڵ� == nullptr�� ��nullptr��Ϊ���ֵ����ôNֵӦ�ò���ϵͳ��С��nullptr֮��


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
