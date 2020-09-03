#pragma once
#include <iostream>
#include <string>
using namespace std;

//构建前缀树
//本例子以只含字母的字符串来进行构造

struct Node
{
	char val;
	int path;//路过的次数
	int end;//作为节点数
	Node* next;
	Node(char c = '#') :val(c), path(0), end(0), next(NULL){}
};

class Trie
{
public:
	Trie();
	~Trie();
	void Insert(string str);
	void Delete(string str);
	bool Find(string str);
	int GetMaxNumber(string str);

private:
	Node* root = NULL;
};

Trie::Trie()
{
	this->root = new Node('#');
}

Trie::~Trie()
{
	root = NULL;
}

void Trie::Insert(string str)
{
	Node* p = root;
	for (int i = 0; i < str.size(); ++i)
	{
		if (p->next == NULL)
			p->next = new Node[26];
		p = p->next;
		int index = str[i] - 'a';
		if (p[index].val != str[i])
			p[index].val = str[i];//其实val值没有，因为index就代表了什么字母了
		if (i + 1 == str.size())//是结尾就end++
			p[index].end++;
		else
			p[index].path++;//是经过就path++

	}
}


void Trie::Delete(string str)
{
	if (this->Find(str))
	{
		Node* p = root;
		for (int i = 0; i < str.size(); ++i)
		{
			p = p->next;
			int index = str[i] - 'a';
			if (i + 1 == str.size())//是结尾就end++
				p[index].end--;
			else
				p[index].path--;//是经过就path++
			if (p[index].path == 0 && p[index].end == 0)
			{
				p[index] = NULL;
				return;//此节点及之后节点必为该字符串的记录，此处为提前删除
			}
		}
	}
}

bool Trie::Find(string str)
{
	Node* p = root;
	for (int i = 0; i < str.size(); ++i)
	{
		p = p->next;
		int index = str[i] - 'a';
		if (p[index].val != str[i])
			return false;
	}
	return true;
}

int Trie::GetMaxNumber(string str)//计算有哪些字母是以str为前缀
{
	Node* p = root;
	for (int i = 0; i < str.size(); ++i)
	{
		p = p->next;
		int index = str[i] - 'a';
		if (p[index].val != str[i])
			return 0;
	}
	return p[str[str.size() - 1] - 'a'].path;
}



void Test()
{
	Trie T;
	T.Insert("qwer");
	T.Insert("asdf");
	T.Insert("abcd");
	T.Insert("azsq");
	cout << T.GetMaxNumber("a") << endl;

	cout << T.Find("qazxsw") << endl;
	int i = 0;
	cout << T.Find("qwer") << endl;

	T.Delete("azsq");
	cout << T.Find("azsq") << endl;
}