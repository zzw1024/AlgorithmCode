#include "000�⺯��.h"

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

#define OK 1
#define NO 0
#define HASHSIZE 12 /* ����ɢ�б�Ϊ����ĳ��� */
#define NULLKEY -32768 

struct HashTable
{
	vector<int>elem;//��̬�������飬�������������㣬����Ҫ���������ڴ�
	int count;//Ԫ�ظ���
};

//��ʼ����ϣ��
int InitHashTable(HashTable* &H) {
	H->count = HASHSIZE;
	H->elem.assign(HASHSIZE, NULLKEY);
	return OK;
}

//��������
int InsertHash(HashTable* &H, int key) {
	int addr = key % HASHSIZE;//ʹ�ó�����������ȡɢ�е�ַ
	while (H->elem[addr] != NULLKEY)//��������ڿգ����ַ���ڳ�ͻ
		addr = (addr + 1) % HASHSIZE;//ʹ�ÿ��ŵ�ַ�������ַ��ͻ����
	H->elem[addr] = key;//����ַΪ�գ����Ž���
	return OK;
}

//����Ԫ��
int SearchHash(HashTable *H, int key, int &addr) {
	addr = key % HASHSIZE;
	while (H->elem[addr] != key) {		
		addr = (addr + 1) % HASHSIZE;
		if (H->elem[addr] == NULLKEY || addr == key % HASHSIZE)//�õ�ַΪ�ջ����ǵ�ַ������ѭ��
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
		printf("���� %d �ĵ�ַΪ��%d \n", key, addr);
	else
		printf("���� %d ʧ�ܡ�\n", key);

	for (int i = 0; i < HASHSIZE; i++)
	{
		key = arr[i];
		SearchHash(H, key, addr);
		printf("���� %d �ĵ�ַΪ��%d \n", key, addr);
	}

	return 0;
}
