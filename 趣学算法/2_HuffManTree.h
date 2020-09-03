#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXBIT MAXLEAF
#define MAXNODE MAXLEAF*2-1

using namespace std;

//���ݽṹ
struct HTree
{
	double weight;//Ȩֵ
	int parent;//˫��
	int lchild;//����
	int rchild;//����
	char value;//����ַ�
};

//����ṹ��
struct HCode
{
	char c;
	vector<int>v;
};

void HuffTreeCreate(HTree *HuNode, int n)
{
	//���ڵ��ʼ��
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		HuNode[i].weight = 0;
		HuNode[i].parent = -1;
		HuNode[i].lchild = -1;
		HuNode[i].rchild = -1;
		HuNode[i].value = '*';
	}
	//�������
	cout << "Please input the value and weight of the node:" << endl;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> HuNode[i].value >> HuNode[i].weight;
	}
	//�����������
	for (int i = 0; i < n - 1; ++i)
	{
		int m1, m2;
		m1 = m2 = MAXVALUE;
		int x1, x2;
		x1 = x2 = 0;
		for (int j = 0; j < n + i; ++j)//Ѱ����С�������ڵ�
		{
			if (HuNode[j].weight < m1 && HuNode[j].parent == -1)
			{
				m2 = m1;
				x2 = x1;
				x1 = j;
				m1 = HuNode[j].weight;
			}
			else if (HuNode[j].weight < m2 && HuNode[j].parent == -1)
			{
				m2 = HuNode[j].weight;
				x2 = j;
			}
		}
		//����������С�Ľڵ���ΪҶ����ɶ���������������ڵ���Ϊһ���µ� �ڵ�
		HuNode[n + i].weight = HuNode[x1].weight + HuNode[x2].weight;
		HuNode[n + i].lchild = x1;
		HuNode[n + i].rchild = x2;
		
		HuNode[x1].parent = n + i;
		HuNode[x2].parent = n + i;

	}

}

//��������Ƿ��ű��룬˳�Ŷ�ȡ
void HuffCodeCrete(HTree* HuNode, map<char, vector<int>>& HuCode, int n)
{
	//ʹ��ջ�洢
	stack<int>sta;
	for (int i = 0; i < n; ++i)//��Ϊ��ʼ�����е��ڵ㶼������Ҷ�ӽڵ�
	{
		int m = i;
		int p = HuNode[m].parent;//�ӵ�һλ��ʼ�Ҹ��ڵ�
		while (p != -1)
		{
			if (HuNode[p].lchild == m)//Ϊ�����ӱ���
				sta.push(0);
			else
				sta.push(1);
			m = p;
			p = HuNode[m].parent;
		}
		//��Ҷ�ӽڵ�������
		//�洢����
		while (!sta.empty())
		{
			HuCode[HuNode[i].value].push_back(sta.top());
			sta.pop();
		}
	}
}


//����
void Encoding(const map<char, vector<int>>& HuCode, string s, int n)
{
	vector<int>Code;
	for (int i = 0; i < s.size(); ++i)
	{
		auto ptr = HuCode.find(s[i]);
		if ( ptr != HuCode.end())
		{
			Code.insert(Code.end(), ptr->second.begin(), ptr->second.end());
		}
		else
		{
			cout << "�����������" << endl;
		}
	}
	for (auto a : Code)
		cout << a;

}


//����
void Decoding(HTree *HuNode, string s)
{
	//���ҵ����ڵ㣺
	int root;
	for (root = 0; HuNode[root].parent != -1;)
		root = HuNode[root].parent;

	for (int i = 0; i < s.size();)
	{
		int p = root;
		while (HuNode[p].lchild != -1)
		{
			int a = s[i] - '0';
			if (a == 0)
				p = HuNode[p].lchild;
			else
				p = HuNode[p].rchild;
			i++;
		}
		cout << HuNode[p].value;
	}
}


int HuffMan()
{
	HTree HuffNode[MAXNODE];//��ʼ�ڵ�
	map<char, vector<int>>HuffCode;//����ṹ��
	int n;
	cout << "Please input n��" << endl;
	cin >> n;
	HuffTreeCreate(HuffNode, n);//������������
	HuffCodeCrete(HuffNode, HuffCode, n);//������������
	string s;
	//���룺
	cout << "��������Ҫ���ܵĴ��룺";
	cin >> s;
	cout << "����Ϊ��";
	Encoding(HuffCode, s, n);
	cout << endl;

	//����
	cout << "��������Ҫ����Ĵ��룺";
	cin >> s;
	cout << "����Ϊ��";
	Decoding(HuffNode, s);
	cout << endl;

	return 0;

}
