#pragma once
#include <iostream>
#include <hash_map>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;


//Problem:
//	   设计RandomPool结构
//		   【题目】 设计一种结构，在该结构中有如下三个功能：
//		   insert(key)：将某个key加入到该结构，做到不重复加入。
//		   delete(key)：将原本在结构中的某个key移除。 
//		   getRandom()：等概率随机返回结构中的任何一个key。
//		   【要求】 Insert、delete和getRandom方法的时间复杂度都是
//		   O(1)
//
//Solution:
//	   使用两个hash表，一个是记录标号，一个记录关键词
//		这里有个关键之处就是，等概率返回一个关键词
//		若简单使用用哈希表来进行存储，那么有个问题，当删除数据时，会使得哈希表中间产生空白数据
//		最好的避免中间产生空数据的方法就是将要删除数据的与表中末尾的数据进行交换
//		然后直接删除最后的数据，故需要使用两个哈希表


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
	//交换查找到元素与最后一个元素
	T temp = IndexMap[--(this->size)];//最后一个元素的关键词,同时将hash表中的元素删除了
	int index = KeyMap[key];//要删除元素的位置
	KeyMap[temp] = index;
	IndexMap[index] = temp;//将最后一个元素替换要删除元素的位置
	//正式删除
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
		int index = (int)((rand() % (99 + 1) / (double)(99 + 1))*(this->size));//随机生成一个位置
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