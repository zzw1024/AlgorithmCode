#pragma once
#include <iostream>
#include <vector>

using namespace std;

//����Ŀ��
//	һ����˾�����½ڹ�ϵ��һ�ö�����������˾Ҫ�ٰ���ᣬ����Ϊ��֯���Ѿ������˴�ҵ�����
//	һ��Ա����ֱ���ϼ�������������Ա���϶���������
//	ÿ��Ա������һ����Ծ�ȵ�ֵ������˭���������Ա�������뺯����ô�������������Ծ��
//	�������Ļ�Ծֵ��
//	������
//	����һ���������������ֹ�ϵ
//		matrix =
//		{
//		1,6
//		1,5
//		1,4
//		}
//	�������ĺ����ǣ�
//	matrix[0] = { 1 , 6 }����ʾ0���Ա����ֱ���ϼ�Ϊ1, 0���Ա���Լ��Ļ�Ծ��Ϊ6
//	matrix[1] = { 1 , 5 }����ʾ1���Ա����ֱ���ϼ�Ϊ1�����Լ��������˾�����boss��, 1���Ա���Լ��Ļ�Ծ��Ϊ5
//	matrix[2] = { 1 , 4 }����ʾ2���Ա����ֱ���ϼ�Ϊ1, 2���Ա���Լ��Ļ�Ծ��Ϊ4
//	Ϊ��������Ծ�����Ӧ����1������0��2������󷵻ػ�Ծ��Ϊ10
//
//����⡿
//	ʹ�ö�̬�滮
//	ÿ���ڵ㱣�����Ծ��
//	Ȼ�������������յȼ�����չ��
//	x1���Ļ�Ծ��Ϊ��x1�Ļ�Ծ�� + x1�����ӽڵ㲻���Ļ�Ծ��
//	x1�����Ļ�Ծ�ȣ�x1���� + x1�����ӽڵ��ÿ���ڵ��е�max(��������)
//


///ʹ�õݹ����
void process(vector<vector<int>>data, vector<vector<int>>&dp, vector<bool>isVist, int& root)
{
	isVist[root] = true;//������
	dp[root][1] = data[root][1];//��ȡ��Ծֵ
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i][0] == root && !isVist[i])
		{
			process(data, dp, isVist, i);
			dp[root][1] += dp[i][0];
			dp[root][0] += dp[i][0] > dp[i][1] ? dp[i][0] : dp[i][1];
		}
	}
}



//ʹ�ö�̬�滮����
int getMaxHappy(vector<vector<int>>data)
{
	vector<vector<int>>dp(data.size(), vector<int>(data[0].size(), 0));
	vector<bool>isVist(data.size(), false);
	int root = 0;//�ҵ�boss
	for (int i = 0; i < data.size(); ++i)
		if (data[i][0] == i)//�Լ����Լ��� ��˾�������Ϊboss
		{
			root = i;
			break;
		}
	process(data, dp, isVist, root);
	return dp[root][0] > dp[root][1] ? dp[root][0] : dp[root][1];
}


///ʹ�ö������ĵݹ������
struct Node
{
	int val;//��Ծ��
	vector<Node*>child;//��������1:n�Ĺ�ϵ
	Node(int a) :val(a) {}
};

Node* Create(const vector<vector<int>>data)
{
	Node* head = nullptr;
	vector<Node*>node(data.size());
	int root = 0;
	for (int i = 0; i < data.size(); ++i)
		if (data[i][0] == i)
		{
			root = i;
			break;
		}
	node[root] = new Node(data[root][1]);
	for (int i=0;i<data.size();++i)
	{
		if (data[i][0] != i)//���Ǵ�boss
		{
			node[i] = new Node(data[i][1]);
			node[data[i][0]]->child.push_back(node[i]);
		}
		else
			head = node[i];
	}
	return head;
}


struct returnType
{
	int c;//���Ļ�Ծ��
	int nc;//�����Ļ�Ծ��
	returnType(int a, int b) :c(a), nc(b) {}
};

returnType* calMaxHappy(Node* head)
{
	int cvalue, ncvalue;
	cvalue = head->val;//headȥ�Ļ�Ծ��
	ncvalue = 0;//head��ȥ�Ļ�Ծ��
	for (int i = 0; i != head->child.size(); ++i)
	{
		returnType* res = calMaxHappy(head->child[i]);
		cvalue += res->nc;
		//��˾ȥ�Ļ�Ծ�� = ��˾�Ļ�Ծ�� + ������ȥ�Ļ�Ծ�ȣ���Ϊ��˾ȥ����������ȥ
		ncvalue += res->c > res->nc ? res->c : res->nc;
		//��˾��ȥ�Ļ�Ծ = ��˾��ȥ�Ļ�Ծ�� + ����ȥ���߲�ȥ�����ֵ����Ϊ��˾��ȥ����������ȥ������Բ�ȥ
	}
	return new returnType(cvalue, ncvalue);
}

void Test()
{
	vector<vector<int>>data;
	data = { {1,6},{1,5},{1,4} };
	cout << getMaxHappy(data) << endl;

	Node* head = Create(data);
	returnType* p = calMaxHappy(head);
	cout << (p->c > p->nc ? p->c : p->nc) << endl;
}