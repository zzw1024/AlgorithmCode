#pragma once
#include <iostream>
#include <string>
using namespace std;

//����ǰ׺��
//��������ֻ����ĸ���ַ��������й���

struct Node
{
	char val;
	int path;//·���Ĵ���
	int end;//��Ϊ�ڵ���
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
			p[index].val = str[i];//��ʵvalֵû�У���Ϊindex�ʹ�����ʲô��ĸ��
		if (i + 1 == str.size())//�ǽ�β��end++
			p[index].end++;
		else
			p[index].path++;//�Ǿ�����path++

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
			if (i + 1 == str.size())//�ǽ�β��end++
				p[index].end--;
			else
				p[index].path--;//�Ǿ�����path++
			if (p[index].path == 0 && p[index].end == 0)
			{
				p[index] = NULL;
				return;//�˽ڵ㼰֮��ڵ��Ϊ���ַ����ļ�¼���˴�Ϊ��ǰɾ��
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

int Trie::GetMaxNumber(string str)//��������Щ��ĸ����strΪǰ׺
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