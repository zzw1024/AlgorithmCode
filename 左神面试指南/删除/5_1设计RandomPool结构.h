#pragma once
#include <iostream>
#include <hash_map>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;


//Problem:
//	   ���RandomPool�ṹ
//		   ����Ŀ�� ���һ�ֽṹ���ڸýṹ���������������ܣ�
//		   insert(key)����ĳ��key���뵽�ýṹ���������ظ����롣
//		   delete(key)����ԭ���ڽṹ�е�ĳ��key�Ƴ��� 
//		   getRandom()���ȸ���������ؽṹ�е��κ�һ��key��
//		   ��Ҫ�� Insert��delete��getRandom������ʱ�临�Ӷȶ���
//		   O(1)
//
//Solution:
//	   ʹ������hash��һ���Ǽ�¼��ţ�һ����¼�ؼ���
//		�����и��ؼ�֮�����ǣ��ȸ��ʷ���һ���ؼ���
//		����ʹ���ù�ϣ�������д洢����ô�и����⣬��ɾ������ʱ����ʹ�ù�ϣ���м�����հ�����
//		��õı����м���������ݵķ������ǽ�Ҫɾ�����ݵ������ĩβ�����ݽ��н���
//		Ȼ��ֱ��ɾ���������ݣ�����Ҫʹ��������ϣ��


template<class T>
class RandomPool
{
public:
	void insert(T key);
	void del(T key);
	T getRandom();
	void getPrint(T key);
	void getPrint(int index);

private:
	hash_map<T, int>KeyMap;
	hash_map<int, T>IndexMap;
	int size = 0;
};


template<class T>
void RandomPool<T>::insert(T key)
{
	if (KeyMap.find(key) == KeyMap.end())
	{
		KeyMap[key] = this->size;
		IndexMap[this->size] = key;
		++(this->size);
		cout << "add succeed!" << endl;
	}
	else
		cout << "add filed!" << endl;
}


template<class T>
void RandomPool<T>::del(T key)
{
	auto ptr = KeyMap.find(key);
	if (ptr == KeyMap.end())
	{
		cout << "delete filed! there is not exsite the key!" << endl;
		return;
	}
	//�������ҵ�Ԫ�������һ��Ԫ��
	T temp = IndexMap[--(this->size)];//���һ��Ԫ�صĹؼ���,ͬʱ��hash���е�Ԫ��ɾ����
	int index = KeyMap[key];//Ҫɾ��Ԫ�ص�λ��
	KeyMap[temp] = index;
	IndexMap[index] = temp;//�����һ��Ԫ���滻Ҫɾ��Ԫ�ص�λ��
	//��ʽɾ��
	KeyMap.erase(ptr);
	IndexMap.erase(IndexMap.find(index));
}

template<class T>
T RandomPool<T>::getRandom()
{
	if (this->size == 0)
	{
		cout << "the map is empty!" << endl;
	}
	else
	{
		int index = (int)((rand() % (99 + 1) / (double)(99 + 1))*(this->size));//�������һ��λ��
		return IndexMap[index];
	}
}

template<class T>
void RandomPool<T>::getPrint(T key)
{
	if (KeyMap.find(key) == KeyMap.end())
		cout << "the key is not exsite!" << endl;
	else
		cout << KeyMap[key] << endl;
}

template<class T>
void RandomPool<T>::getPrint(int index) 
{
	if (IndexMap.find(index) == IndexMap.end())
		cout << "the key is not exsite!" << endl;
	else
		cout << IndexMap[index] << endl;
}


void Test()
{
	srand((unsigned)time(NULL));
	RandomPool<string>map;
	map.insert("zz");
	map.insert("zw");
	map.insert("ww");
	map.insert("wz");

	cout << map.getRandom() << endl;
	map.getPrint(2);
	map.getPrint("ww");
	map.del("zw");
	map.getPrint("zw");
}