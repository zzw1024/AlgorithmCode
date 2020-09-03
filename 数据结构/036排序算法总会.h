#include "000�⺯��.h"

#define MAX_LENGTH_INSERT_SORT 7 /* ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ */
#define MAXSIZE 100  /* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */
#define N 9
struct SqList
{
	int v[MAXSIZE+1];//���ڴ洢Ҫ��������飬r[0]��Ϊ�ڱ�����ʱ��ű���
	int len;//��¼˳���ĳ���
};

//���ݽ���
void swap(int &i, int &j) {
	int temp;
	temp = i;
	i = j;
	j = temp;
}

/**************************������****************************/
//����ð�����򣬾���һ��һ�������Ա�
void  BubbleSort0(SqList* &l,int (&a)[2]) {
	for (int i = 1; i < l->len; ++i) {
		for (int j = i + 1; j <= l->len; ++j) {
			a[0]++;
			if (l->v[i] > l->v[j]){
				swap(l->v[i], l->v[j]);
				a[1]++;
			}
		}
	}
}

/**************************ð������****************************/
//ð�����������Ƚ�����
void BubbleSort(SqList* &l, int(&a)[2]) {
	for (int i = 1; i < l->len; ++i) {
		for (int j = l->len - 1; j >= i; --j) {
			a[0]++;
			if (l->v[j + 1] < l->v[j]) {
				swap(l->v[j + 1], l->v[j]);
				a[1]++;
			}
		}
	}
}

/**************************�Ľ�ð������****************************/
//�Ľ�ð�����򣬼����ڱ�ģʽ
void BubbleSort2(SqList* &l, int(&a)[2]) {
	bool flag = true;//�ڱ�
	for (int i = 1; flag&&i < l->len; ++i) {
		flag = false;
		for (int j = l->len - 1; j >= i; --j) {
			a[0]++;
			if (l->v[j + 1] < l->v[j]) {
				a[1]++;
				swap(l->v[j + 1], l->v[j]);
				flag = true;//���ݽ��������Ҫ����
			}
		}
	}
}

/**************************ѡ������****************************/
//ѡ�����򣬾��������ҳ�δ�����е���Сֵ����ǰ��
void SelectSort(SqList* &l, int(&a)[2]) {
	int i, j, min;
	for (i = 1; i < l->len; ++i) {
		min = i;
		for (j = i + 1; j < l->len; ++j) {
			a[0]++;
			if (l->v[min] > l->v[j])
				min = j;
		}
		if (i != min) {
			swap(l->v[min], l->v[i]);
			a[1]++;
		}
	}
}

/**************************��ֵ����****************************/
//��ֵ���򣬾��Ǵ�ǰ��������Ƚϣ����ڶ�����ΪС������Ȼ�󽫸�����ס��
//�Ӵ�λ�ôӺ���ǰ�Ƚϸ���������������������Ų��ֱ���ҵ���Ÿ�����λ��
//���㷨��Ҫһ����������ʱ�ռ��ţ�

void InsertSort(SqList* &l, int(&a)[2]) {
	int i, j;
	for (int i = 2; i < l->len; ++i) {
		a[0]++;
		if (l->v[i] < l->v[i - 1]) {//�ҵ���ǰ�Ⱥ�����
			l->v[0] = l->v[i];//�����ڱ�
			for (j = i - 1; l->v[0] < l->v[j]; --j) {//���رȽ�
				a[1]++;
				l->v[j + 1] = l->v[j];//��������Ų
			}
			l->v[j+1] = l->v[0];
		}
	}
}

/**************************ϣ������****************************/
//ϣ������
//���ֵ������񣬲����Ǽ���Ƚ�
void ShellSort(SqList* &l, int(&a)[2]) {
	int gap = l->len;
	int i, j;
	do {
		gap = gap / 3 + 1;//�����С
		for (i = gap + 1; i < l->len; ++i) {
			a[0]++;
			if (l->v[i] < l->v[i - gap]) {
				l->v[0] = l->v[i];
				for (j = i - gap; j > 0 && l->v[0] < l->v[j]; j -= gap) {//��ǰȥ����
					l->v[j + gap] = l->v[j];//��������ƣ�
					a[1]++;
				}
				l->v[j + gap] = l->v[0];//����
			}
		}
	} while (gap > 1);
}

/**************************************������*****************************/
//����Ϊ�����
void HeapAdjust(SqList* &l, int n, int len) {
	int temp = l->v[n];
	for (int i = 2 * n; i <= len; i *= 2) {//���Źؼ����нϴ�ĺ��ӽṹ����ɸѡ
		if (i < len&&l->v[i] < l->v[i + 1])++i;//iΪ�ؼ����нϴ�ļ�¼���±�
		if (temp >= l->v[i])break;//�ҵ������λ����
		l->v[n] = l->v[i];//
		n = i;
	}
	l->v[n] = temp;//���в���
}

//������
void HeapSort(SqList* &l, int(&a)[2]) {
	for (int i = l->len / 2; i > 0; --i) {//�������е����ݱ�Ϊһ�����
		a[0]++;
		HeapAdjust(l, i, l->len);
	}
	for (int i = l->len; i > 1; --i) {
		a[1]++;
		swap(l->v[1], l->v[i]);/* ���Ѷ���¼�͵�ǰδ�����������е����һ����¼���� */
		HeapAdjust(l, 1, i - 1);/*  ��L->r[1..i-1]���µ���Ϊ����� */
	}
}

/**************************�ݹ鷨�鲢+����****************************/
/* �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] */
//�鲢
void Merge(int *SR, int *TR, int pot, int m, int len) {
	int i,j,k;
	for (i = m + 1, k = pot; pot <= m && i <= len; ++k) {/*��SR�м�¼��С����ز���TR * /*/
		if (SR[pot] < SR[i])TR[k] = SR[pot++];
		else TR[k] = SR[i++];
	}
	if (pot <= m)
		for (j = 0; j <= m; ++j)
			TR[k + j] = SR[pot + j];	/* ��ʣ���SR[i..m]���Ƶ�TR */
	if (i <= len)
		for (j = 0; j <= len - i; ++j)
			TR[k + j] = SR[i + j];/* ��ʣ���SR[j..n]���Ƶ�TR */
}
//���еݹ�
void MSort(int *SR,int*TR1,int pot, int len, int(&a)[2]) {
	int TR2[MAXSIZE + 1];
	if (len == pot)
		TR1[pot] = SR[pot];
	else {
		int m = (len + pot) / 2;    //��ԭ����ƽ����������
		a[0]++;
		MSort(SR, TR2, pot, m, a);	/* �ݹ�ؽ�SR[pot..m]�鲢Ϊ�����TR2[pot..m] */
		MSort(SR, TR2, m + 1, len, a);	/* �ݹ�ؽ�SR[m+1..len]�鲢Ϊ�����TR2[m+1..len] */
		Merge(TR2, TR1, pot, m, len);	/* ��TR2[pot..m]��TR2[m+1..t]�鲢��TR1[pot..len] */
		a[1]++;
	}

}

//�ݹ鷨�鲢����
void MergeSort(SqList* &l, int(&a)[2]) {
	MSort(l->v,l->v,1, l->len,a);
}

/**************************�ǵݹ鷨�鲢����****************************/
/*��SR[]�����ڳ���Ϊs�������������鲢��TR[] * /*/
void MergePass(int *SR, int *TR, int k, int len, int(&a)[2]) {
	int i = 1, j;
	a[1]++;
	while (i <= len - 2 * k + 1) {
		//�����鲢
		Merge(SR, TR, i, i + k - 1, len);
		i = i + 2 * k;
	}
	if (i < len - k + 1)//�鲢�����������
		Merge(SR, TR, i, i + k - 1, len);
	else//���ֻʣ�µ�������
		for (j = i; j <= len; ++j)
			TR[j] = SR[j];
} 
//�鲢����
void MergeSort2(SqList* &l, int(&a)[2]) {
	int *TR = new int[l->len];
	int k = 1;
	while (k < l->len) {
		a[0]++;
		MergePass(l->v, TR, k, l->len, a);
		k = k * 2;//�ӳ�������
		MergePass(TR, l->v, k, l->len, a);
		k = 2 * k;//�����мӳ�
	}
}

/**************************��������****************************/
/* ����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ(��)�ļ�¼������(С)������ */
//�����������������߱���С���ұ߱����
int Partiton(SqList* &l, int pot, int len, int(&a)[2]) {
	int pkey;
	pkey = l->v[pot];//�����һ��λ�õ������������λ��
	while (pot < len) {
		a[0]++;
		while (pot < len&&l->v[len] >= pkey)//ȷ���ұߴ��ڹؼ���
			len--;
		a[1]++;
		swap(l->v[pot], l->v[len]);//���ȹؼ���С�������õ��ؼ��������
		a[0]++;
		while (pot < len&&l->v[pot] <= pkey)//ȷ����ߵ� ��С�ڹؼ���
			pot++;
		a[1]++;
		swap(l->v[pot], l->v[len]);//���ȹؼ�����������õ��ؼ������ұ�
	}
	return pot;//���عؼ�����λ��
}

/* ��˳���L�е�������L->r[low..high]���������� */
void QSort(SqList* &l, int pot, int len, int(&a)[2]) {
	int pivot;
	if (pot < len) {
		pivot = Partiton(l, pot, len, a);/*  ��L->r[low..high]һ��Ϊ�����������ֵpivot */
		QSort(l, pot, pivot - 1, a);/*  �Ե��ӱ�ݹ����� */
		QSort(l, pivot + 1, len, a);/*  �Ը��ӱ�ݹ����� */
	}
}
void QuickSort(SqList* &l, int(&a)[2]) {
	QSort(l, 1, l->len, a);
}

/**************************�Ľ���������****************************/
//����������Ż�
int Partiton1(SqList* &l, int pot, int len, int(&a)[2]) {
	int pkey;

	/////�Ľ�֮����֮��ѡ�м���Ϊ�ؼ�����λ��
	int m = pot + (len - pot) / 2;
	a[0]++;
	if (l->v[pot] > l->v[len]) {
		swap(l->v[pot], l->v[len]);/* ����������Ҷ����ݣ���֤��˽�С */
		a[1]++;
	}
	a[0]++;
	if (l->v[m] > l->v[len]) {
		swap(l->v[m], l->v[len]);/* �����м����Ҷ����ݣ���֤�м��С */
		a[1]++;
	}
	a[0]++;
	if (l->v[m] < l->v[pot]) {
		swap(l->v[m], l->v[pot]);/* �����м���������ݣ���֤��˽�С */
		a[1]++;
	}
	/////
	pkey = l->v[pot];//�����һ��λ�õ������������λ��
	l->v[0] = pkey;//����
	while (pot < len) {/*�ӱ�����˽�������м�ɨ�� */
		a[0]++;
		while (pot < len&&l->v[len] >= pkey)//ȷ���ұߴ��ڹؼ���
			--len;
		l->v[pot] = l->v[len];
		a[0]++;
		while (pot < len&&l->v[pot] <= pkey)//ȷ����ߵ� ��С�ڹؼ���
			++pot;
		l->v[len] = l->v[pot];
	}
	l->v[pot] = l->v[0];
	return pot;//���عؼ�����λ��
}

void QSort1(SqList* &l, int pot, int len, int(&a)[2]) {
	int pivot;
	if ((len - pot) > MAX_LENGTH_INSERT_SORT) {
		while (pot < len) {
			pivot = Partiton1(l, pot, len, a);/*  ��L->r[low..high]һ��Ϊ�����������ֵpivot */
			QSort1(l, pot, pivot - 1, a);/*  �Ե��ӱ�ݹ����� */
			pot = pivot + 1;//β�ݹ�
		}
	}
	else
		InsertSort(l,a);
}

void QuickSort1(SqList* &l, int(&a)[2]) {
	QSort1(l, 1, l->len, a);
}


/*************************************************************/
int T036(){
	/* int d[N]={9,1,5,8,3,7,4,6,2}; */
	int d[N] = { 50,10,90,30,70,40,80,60,20 };
	/* int d[N]={9,8,7,6,5,4,3,2,1}; */
	int count[2] = { 0,0 };//��¼�Ƚϴ����ͽ�������
	SqList *l0, *l1, *l2, *l3, *l4, *l5, *l6, *l7, *l8, *l9, *l10;

	l0 = new SqList;
	for (int i = 0; i < N; i++)
		l0->v[i + 1] = d[i];
	l0->len = N;

	l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = l10 = l0;
	printf("����ǰ:\n");
	for(int i=1;i<=N;++i)
		cout << l0->v[i] << "  ";
	cout << endl;

	printf("����ð������:\n");
	BubbleSort0(l0,count);
	for (int i = 1; i <= N; ++i)
		cout << l0->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("ð������:\n");
	BubbleSort(l1,count);
	for (int i = 1; i <= N; ++i)
		cout << l1->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("�Ľ�ð������:\n");
	BubbleSort2(l2,count);
	for (int i = 1; i <= N; ++i)
		cout << l2->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("ѡ������:\n");
	SelectSort(l3,count);
	for (int i = 1; i <= N; ++i)
		cout << l3->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("ֱ�Ӳ�������:\n");
	InsertSort(l4, count);
	for (int i = 1; i <= N; ++i)
		cout << l4->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("ϣ������:\n");
	ShellSort(l5, count);
	for (int i = 1; i <= N; ++i)
		cout << l5->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("������:\n");
	HeapSort(l6, count);
	for (int i = 1; i <= N; ++i)
		cout << l6->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("�鲢���򣨵ݹ飩:\n");
	MergeSort(l7, count);
	for (int i = 1; i <= N; ++i)
		cout << l7->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("�鲢���򣨷ǵݹ飩:\n");
	MergeSort2(l8, count);
	for (int i = 1; i <= N; ++i)
		cout << l8->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("��������:\n");
	QuickSort(l9, count);
	for (int i = 1; i <= N; ++i)
		cout << l9->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0

	printf("�Ľ���������:\n");
	QuickSort1(l10, count);
	for (int i = 1; i <= N; ++i)
		cout << l10->v[i] << "  ";
	cout << endl;
	cout << "�Ƚϴ����� " << count[0] << " ; ���������� " << count[1] << endl;
	count[0] = count[1] = 0;//��0


	/*����������*/
	/*
	srand(time(0));
	int Max=10000;
	int d[10000];
	int i;
	SqList l0;
	for(i=0;i<Max;i++)
		d[i]=rand()%Max+1;
	for(i=0;i<Max;i++)
		l0.r[i+1]=d[i];
	l0.length=Max;
	MergeSort(l0);
	print(l0);
	*/
	return 0;
}


