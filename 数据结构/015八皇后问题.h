#include "000�⺯��.h"
#include <algorithm>

static int num;
static int *x;
static int sum;

bool place(int k)
{
	for (int j = 1; j < k; j++)
		if (abs(x[k] - x[j]) == abs(k - j) || x[j] == x[k])
			return false;
	return true;

}

void backtrack(int t)
{
	if (t > num) //numΪ�ʺ����Ŀ
	{
		sum++;//sumΪ���еĿ��еĽ�
		for (int m = 1; m <= num; m++)
		{
			cout << x[m];//��һ����������ݹ鵽Ҷ�ڵ��ʱ��һ�����н�
		}
		cout << endl;
	}
	else
		for (int i = 1; i <= num; i++)//�����ýڵ������Ҷ
		{
			x[t] = i;
			if (place(t)) backtrack(t + 1);//�˴���place����������������������˵���������жϣ����������������һ���ݹ�
		}
}
void T015()
{
	num = 8;
	sum = 0;
	x = new int[num + 1];//��Ϊһ���ڵ���num��Ҷ������Ҫnum+1��λ��
	for (int i = 0; i <= num; i++)
		x[i] = 0;
	backtrack(1);
	cout << "��������" << sum;

}





//�ⷨ��
bool isPass(int*);
int EightQueue() {
	int a[8] = { 0,1, 2, 3, 4, 5, 6, 7 };
	int n = 0;	
	while (next_permutation(a, a + 8)) {//һһ�ж������Ƿ����
		if (isPass(a))++n;//���оͼ���һ��
	}
	return n;
}


bool isPass(int *a) {//�ж�б���Ƿ���ܵ������ʺ�Ĺ���
	int queue[8][8] = { 0 };
	for(int i=0;i<8;++i)
		queue[i][a[i]] = 1;//����0-7���֣�ÿ�а���a�����ֶ�Ӧ���н��з��ûʺ��򲻻����ͬ��ͬ�г��������ʺ��ˣ����������ж�

	for (int i = 0; i < 8; ++i) {
		for (int t = i - 1, k = a[i] - 1; t >= 0 && k >= 0; --t, --k) {//���Ϸ�
			if (queue[t][k] == 1)
				return false;
		}
		for (int t = i + 1, k = a[i] + 1; t < 8 && k < 8; ++t, ++k) {//���·�
			if (queue[t][k] == 1)
				return false;
		}
		for (int t = i + 1, k = a[i] - 1; t < 8 && k >= 0; ++t, --k) {//���·�
			if (queue[t][k] == 1)
				return false;
		}
		for (int t = i - 1, k = a[i] + 1; t >= 0 && k < 8; --t, ++k) {//���Ϸ�
			if (queue[t][k] == 1)
				return false;
		}
	}
	return true;
}



void T015()
{
	cout << "��������" << EightQueue() << endl;

}