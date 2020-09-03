#include "000�⺯��.h"
//�����޸����������Ա���ָ��Huffman���ڵ��ָ��
#define TYPE htNode *

#define MAX_SZ 256

//���������ڵ㶨��
struct htNode {
	char symbol;
	struct htNode *left, *right;
};
/*���ǽ�����������װ����һ���ṹ��
��Ϊ�������ǿ��ܻ������"size"�������ֶ�
���������Ҫ�Ļ����������ǾͲ����޸�������
Դ���롣*/
struct htTree {
	htNode *root;
};
//����������ڵ�(����ʵ��)
struct hlNode {
	char symbol;
	string code;
	struct hlNode *next;
};
//
struct hlTable {
	hlNode *first;
	hlNode *last;
};

struct  pQueueNode{
	TYPE val;
	unsigned int priority;
	struct pQueueNode* next;
};

struct pQueue {
	unsigned int size;
	pQueueNode *first;
};

void initpQueue(pQueue **queue) {
	//����Ϊ���ȶ������ͷ����ڴ�
	//���ǳ�ʼ���ֶε�ֵ
	*queue = new pQueue;
	(*queue)->first = NULL;
	(*queue)->size = 0;
	return ;
}
//�γ�˵�ǽ������У���Ҳ�����ǽ������У����ǣ����ǣ���������뿴��������������
void addPQueue(pQueue **queue, TYPE val, unsigned int priority) {
	//����������������ǲ���Ҫ���ָ����ֵ��
	//���������̨���һ��������Ϣ�����ء�
	if ((*queue)->size == MAX_SZ) {
		cout << "the queue is full!" << endl;
		return;
	}
	pQueueNode *aux = new pQueueNode;
	aux->priority = priority;
	aux->val = val;
	//�������Ϊ�գ�����ӵ�һ��ֵ��
	//������֤�����Σ��Է��ṹ������ʱ���쳣�޸�(���ٷ���)��
	if ((*queue)->size == 0 || (*queue)->first == NULL) {
		aux->next = NULL;
		(*queue)->first = aux;
		(*queue)->size = 1;
		return;
	}
	else {
		//����������Ѿ���Ԫ���Լ�Ԫ�ص����ȼ�
		//����Ҫ��ӵ����ȼ����ڵ�һ��Ԫ�ص����ȼ���
		//���ǰ����ӵ���һ��Ԫ��ǰ�档
		//ע�⣬����������Ҫ�������������ȼ�,��Ϊ�ظ���Խ�ߵ�Ԫ�����ȼ�Խ��
		if (priority <= (*queue)->first->priority) {//β�壿��Ϊ���Ҫ��ǰ��
			aux->next = (*queue)->first;
			(*queue)->first = aux;
			++((*queue)->size);
			return;
		}
		else {//�������ڸ���Ԫ�ص����ȼ�Ѱ���ʺ�����λ��
			pQueueNode *itr = (*queue)->first;//������ǰ��
			while (itr->next != NULL) {
				//��ǰ��һ������������ʱ�����ǽ�Ԫ�ط���Ԫ�صĿ�ͷ
				//Ч�����ȴ�����ͬ����ʹ���������Ŷӵ��뷨��
				if (priority <= itr->next->priority) {
					aux->next = itr->next;
					itr->next = aux;
					++((*queue)->size);
					return;
				}
				itr = itr->next;
			}
			//������ǵ������յ��û�����Ԫ�أ�
			//���ǽ�������ӵ����е�ĩβ��
			if (itr->next = NULL) {
				itr->next = aux;
				aux->next = NULL;
				++((*queue)->size);
				return;
			}

		}
	}

}

TYPE getPQueue(pQueue **queue) {
	TYPE returnValue;
	//���ǴӶ����л�ȡԪ�أ�ֻҪ�����ǿյ�
	if ((*queue)->size > 0) {
		returnValue = (*queue)->first->val;
		(*queue)->first = (*queue)->first->next;
		--(*queue)->size;
	}
	else {
		cout << "the queue is empty!" << endl;
	}
	return returnValue;
}


void traverseTree(htNode *treeNode, hlTable **table, int k, string code) {
	//�������������ǽ��ڱ����������
	if (treeNode->left == NULL && treeNode->right == NULL) {//ΪҶ��
		hlNode *aux = new hlNode;
		code[k] = '\0';
		aux->code = code;
		aux->symbol = treeNode->symbol;
		aux->next = NULL;
		if ((*table)->first == NULL) {
			(*table)->first = aux;
			(*table)->last = aux;
		}
		else {
			(*table)->last->next = aux;
			(*table)->last = aux;
		}

	}
	//������Ϊ��ߵ�ÿһ������һ��0
	if (treeNode->left != NULL) {//��Ϊ��
		code[k] = '0';
		traverseTree(treeNode->left, table, k + 1, code);
	}
	if (treeNode->right != NULL) {
		code[k] = '1';
		traverseTree(treeNode->right, table, k + 1, code);
	}

}

hlTable *buildTable(htTree *huffmanTree) {

	//��ʼ��
	hlTable *table = new hlTable;
	table->first = NULL;
	table->last = NULL;
	//��������
	string code(MAX_SZ, '0');
	//k���洢�����ļ���
	int k = 0;
	//���Ǳ��������������
	traverseTree(huffmanTree->root, &table, k, code);
	return table;
}

htTree *buildTree(string inputString) {
	int probability[MAX_SZ];
	for (int i = 0; i < MAX_SZ; ++i)
		probability[i] = 0;
	//���ǽ�������Ϊ����������������ÿ�����ų��ֵĴ���
	for (int i = 0; i < inputString.size(); ++i)
		probability[(unsigned char)inputString[i]]++;//ת��ΪASCLL��
	//�������ڵ�Ķ���
	pQueue *huffmanQueue;
	initpQueue(&huffmanQueue);
	//����Ϊ�ַ����е�ÿ�����Ŵ����ڵ�
	for (int i = 0; i < MAX_SZ; ++i) {
		if (probability[i] != 0) {
			htNode *aux = new htNode;
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)i;
			addPQueue(&huffmanQueue, aux, probability[i]);
		}
	}
	//����Ӧ�ñ����������Ĳ�����������
	while (huffmanQueue->size != 1) {
		int priority = huffmanQueue->first->priority;
		priority += huffmanQueue->first->next->priority;

		htNode *left = getPQueue(&huffmanQueue);
		htNode *right = getPQueue(&huffmanQueue);

		htNode *newNode = new htNode;
		newNode->left = left;
		newNode->right = right;

		addPQueue(&huffmanQueue, newNode, priority);
	}
	//������
	htTree *tree = new htTree;
	tree->root = getPQueue(&huffmanQueue);
	return tree;
}

void encode(hlTable *table,string stringToEncode) {
	hlNode *traversal;
	cout << "waiting encoded string is:  " << stringToEncode << endl;
	for (int i = 0; i < stringToEncode.size(); ++i) {
		traversal = table->first;
		while (traversal->symbol != stringToEncode[i])
			traversal = traversal->next;
		cout << traversal->code;
	}
	cout << endl;
}

void decode(htTree *tree, string stringToDecode) {
	htNode *traversal = tree->root;
	cout << "Decoding string is: " << stringToDecode;

	/*����Ҫ������ַ�����ÿ����λ��
	//������һ�����õ�0
	//�����ұ�1����λ*/
	for (int i = 0; i < stringToDecode.size(); ++i) {
		if (traversal->left == NULL && traversal->right == NULL) {
			cout << traversal->symbol << endl;
			traversal = tree->root;
		}
		if (stringToDecode[i] == '0')
			traversal = traversal->left;
		if (stringToDecode[i] == '1')
			traversal = traversal->right;
		if (stringToDecode[i] != '0'&&stringToDecode[i] != '1') {
			cout << "the Encoding string error!" << endl;
			return;
		}
	}
	if (traversal->left == NULL && traversal->right == NULL) {
		cout << traversal->symbol;
		traversal = tree->root;
	}
	cout << endl;
}







int T019(void)
{
	//We build the tree depending on the string
	htTree *codeTree = buildTree("beep boop beer!");
	//We build the table depending on the Huffman tree
	hlTable *codeTable = buildTable(codeTree);

	//We encode using the Huffman table
	encode(codeTable, "beep boop beer!");
	//We decode using the Huffman tree
	//We can decode string that only use symbols from the initial string
	decode(codeTree, "0011111000111");
	//Output : 0011 1110 1011 0001 0010 1010 1100 1111 1000 1001
	return 0;
}