#include "000库函数.h"

#define MAXSIZE 100 /* 存储空间初始分配量 */

#define OK 1
#define NO 0
#define HASHSIZE 12 /* 定义散列表长为数组的长度 */
#define NULLKEY -32768 

struct HashTable
{
	vector<int>elem;//动态分配数组，但用容器更方便，但需要大量连续内存
	int count;//元素个数
};

//初始化哈希表
int InitHashTable(HashTable* &H) {
	H->count = HASHSIZE;
	H->elem.assign(HASHSIZE, NULLKEY);
	return OK;
}

//插入数据
int InsertHash(HashTable* &H, int key) {
	int addr = key % HASHSIZE;//使用除留余数法求取散列地址
	while (H->elem[addr] != NULLKEY)//如果不等于空，则地址存在冲突
		addr = (addr + 1) % HASHSIZE;//使用开放地址法解决地址冲突问题
	H->elem[addr] = key;//若地址为空，则存放进来
	return OK;
}

//查找元素
int SearchHash(HashTable *H, int key, int &addr) {
	addr = key % HASHSIZE;
	while (H->elem[addr] != key) {		
		addr = (addr + 1) % HASHSIZE;
		if (H->elem[addr] == NULLKEY || addr == key % HASHSIZE)//该地址为空或者是地址出现了循环
			return NO;
	}
	return OK;
}

int T035()
{
	int arr[HASHSIZE] = { 12,67,56,16,25,37,22,29,15,47,48,34 };
	int  addr, key, result;
	HashTable *H = new HashTable;
	key = 39;

	InitHashTable(H);
	for (int i = 0; i < HASHSIZE; i++)
		InsertHash(H, arr[i]);

	result = SearchHash(H, key, addr);
	if (result)
		printf("查找 %d 的地址为：%d \n", key, addr);
	else
		printf("查找 %d 失败。\n", key);

	for (int i = 0; i < HASHSIZE; i++)
	{
		key = arr[i];
		SearchHash(H, key, addr);
		printf("查找 %d 的地址为：%d \n", key, addr);
	}

	return 0;
}
