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

//数据结构
struct HTree
{
	double weight;//权值
	int parent;//双亲
	int lchild;//左孩子
	int rchild;//左孩子
	char value;//结点字符
};

//编码结构体
struct HCode
{
	char c;
	vector<int>v;
};

void HuffTreeCreate(HTree *HuNode, int n)
{
	//单节点初始化
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		HuNode[i].weight = 0;
		HuNode[i].parent = -1;
		HuNode[i].lchild = -1;
		HuNode[i].rchild = -1;
		HuNode[i].value = '*';
	}
	//输入参数
	cout << "Please input the value and weight of the node:" << endl;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> HuNode[i].value >> HuNode[i].weight;
	}
	//构造哈夫曼树
	for (int i = 0; i < n - 1; ++i)
	{
		int m1, m2;
		m1 = m2 = MAXVALUE;
		int x1, x2;
		x1 = x2 = 0;
		for (int j = 0; j < n + i; ++j)//寻找最小的两个节点
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
		//将这两个最小的节点作为叶子组成二叉树，并将其根节点作为一个新的 节点
		HuNode[n + i].weight = HuNode[x1].weight + HuNode[x2].weight;
		HuNode[n + i].lchild = x1;
		HuNode[n + i].rchild = x2;
		
		HuNode[x1].parent = n + i;
		HuNode[x2].parent = n + i;

	}

}

//这里编码是反着编码，顺着读取
void HuffCodeCrete(HTree* HuNode, map<char, vector<int>>& HuCode, int n)
{
	//使用栈存储
	stack<int>sta;
	for (int i = 0; i < n; ++i)//因为开始的所有单节点都是树的叶子节点
	{
		int m = i;
		int p = HuNode[m].parent;//从第一位开始找父节点
		while (p != -1)
		{
			if (HuNode[p].lchild == m)//为做孩子编码
				sta.push(0);
			else
				sta.push(1);
			m = p;
			p = HuNode[m].parent;
		}
		//该叶子节点编码结束
		//存储代码
		while (!sta.empty())
		{
			HuCode[HuNode[i].value].push_back(sta.top());
			sta.pop();
		}
	}
}


//编码
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
			cout << "输入代码有误！" << endl;
		}
	}
	for (auto a : Code)
		cout << a;

}


//解码
void Decoding(HTree *HuNode, string s)
{
	//先找到根节点：
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
	HTree HuffNode[MAXNODE];//初始节点
	map<char, vector<int>>HuffCode;//编码结构体
	int n;
	cout << "Please input n：" << endl;
	cin >> n;
	HuffTreeCreate(HuffNode, n);//哈夫曼树建立
	HuffCodeCrete(HuffNode, HuffCode, n);//哈夫曼树编码
	string s;
	//编码：
	cout << "请输入你要加密的代码：";
	cin >> s;
	cout << "密码为：";
	Encoding(HuffCode, s, n);
	cout << endl;

	//解码
	cout << "请输入你要解码的代码：";
	cin >> s;
	cout << "明码为：";
	Decoding(HuffNode, s);
	cout << endl;

	return 0;

}
