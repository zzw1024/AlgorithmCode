#include "000库函数.h"
//我们修改数据类型以保存指向Huffman树节点的指针
#define TYPE htNode *

#define MAX_SZ 256

//哈夫曼树节点定义
struct htNode {
	char symbol;
	struct htNode *left, *right;
};
/*我们将整个树“封装”在一个结构中
因为将来我们可能会添加像"size"这样的字段
如果我们需要的话。这样我们就不用修改整个了
源代码。*/
struct htTree {
	htNode *root;
};
//：哈夫曼表节点(链表实现)
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
	//我们为优先队列类型分配内存
	//我们初始化字段的值
	*queue = new pQueue;
	(*queue)->first = NULL;
	(*queue)->size = 0;
	return ;
}
//课程说是降序排列，我也觉得是降序排列，但是，但是，但是这代码看起来是升序排列
void addPQueue(pQueue **queue, TYPE val, unsigned int priority) {
	//如果队列已满，我们不需要添加指定的值。
	//我们向控制台输出一条错误消息并返回。
	if ((*queue)->size == MAX_SZ) {
		cout << "the queue is full!" << endl;
		return;
	}
	pQueueNode *aux = new pQueueNode;
	aux->priority = priority;
	aux->val = val;
	//如果队列为空，则添加第一个值。
	//我们验证了两次，以防结构在运行时被异常修改(很少发生)。
	if ((*queue)->size == 0 || (*queue)->first == NULL) {
		aux->next = NULL;
		(*queue)->first = aux;
		(*queue)->size = 1;
		return;
	}
	else {
		//如果队列中已经有元素以及元素的优先级
		//我们要添加的优先级大于第一个元素的优先级，
		//我们把它加到第一个元素前面。
		//注意，这里我们需要按降序排列优先级,因为重复度越高的元素优先级越高
		if (priority <= (*queue)->first->priority) {//尾插？因为大的要在前面
			aux->next = (*queue)->first;
			(*queue)->first = aux;
			++((*queue)->size);
			return;
		}
		else {//我们正在根据元素的优先级寻找适合它的位置
			pQueueNode *itr = (*queue)->first;//放在最前面
			while (itr->next != NULL) {
				//和前面一样，降序排列时，我们将元素放在元素的开头
				//效率优先次序相同，即使它打消了排队的想法。
				if (priority <= itr->next->priority) {
					aux->next = itr->next;
					itr->next = aux;
					++((*queue)->size);
					return;
				}
				itr = itr->next;
			}
			//如果我们到达了终点而没有添加元素，
			//我们将把它添加到队列的末尾。
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
	//我们从队列中获取元素，只要它不是空的
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
	//如果到了最后，我们将在表中引入代码
	if (treeNode->left == NULL && treeNode->right == NULL) {//为叶子
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
	//：我们为左边的每一步连接一个0
	if (treeNode->left != NULL) {//左为零
		code[k] = '0';
		traverseTree(treeNode->left, table, k + 1, code);
	}
	if (treeNode->right != NULL) {
		code[k] = '1';
		traverseTree(treeNode->right, table, k + 1, code);
	}

}

hlTable *buildTable(htTree *huffmanTree) {

	//初始化
	hlTable *table = new hlTable;
	table->first = NULL;
	table->last = NULL;
	//辅助变量
	string code(MAX_SZ, '0');
	//k将存储遍历的级别
	int k = 0;
	//我们遍历树并计算代码
	traverseTree(huffmanTree->root, &table, k, code);
	return table;
}

htTree *buildTree(string inputString) {
	int probability[MAX_SZ];
	for (int i = 0; i < MAX_SZ; ++i)
		probability[i] = 0;
	//我们将符号视为数组索引，并计算每个符号出现的次数
	for (int i = 0; i < inputString.size(); ++i)
		probability[(unsigned char)inputString[i]]++;//转化为ASCLL码
	//包含树节点的队列
	pQueue *huffmanQueue;
	initpQueue(&huffmanQueue);
	//我们为字符串中的每个符号创建节点
	for (int i = 0; i < MAX_SZ; ++i) {
		if (probability[i] != 0) {
			htNode *aux = new htNode;
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)i;
			addPQueue(&huffmanQueue, aux, probability[i]);
		}
	}
	//我们应用本文中描述的步骤来构建树
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
	//创建树
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

	/*对于要解码的字符串的每个“位”
	//向左走一步，得到0
	//或在右边1个单位*/
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