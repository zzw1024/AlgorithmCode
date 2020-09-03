#include <iostream>

using namespace std;


//����һ������arr����һ����num�����С��num�������������
//��ߣ�����num��������������м䣬����num�������������
//�ұߡ�
//Ҫ�����ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(N)

void swap(int& a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//��ס�����α���n��n << N���������ʱ�临�Ӷ� = n*O(N) == O(N)
template<class T>//Ŀǰ��ֻ�뵽��ʹ��ģ����ʵ���������飬���������÷����������ˡ�
void Test(T& array , const int num)
{
	int N, p1, p2;//����ָ��
	p1 = -1;//��ָ�룬��p1��߲���p1����������<num
	p2 = N = sizeof(array) / sizeof(array[0]);//��ָ�룬p2=N��p2���ұߺ�p2��������������num
	for (int i = 0; i != p2; )
	{
		if (array[i] < num)
			swap(array[++p1], array[i++]);
		else if (array[i] > num)
			swap(array[--p2], array[i]);
		else
			++i;

	}

}

void Heland()
{
	int arr[] = { 1, 5,7,4,6,4,2,9 };	
	Test(arr, 4);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		cout << arr[i] << "  ";
	cout << endl << "**************************" << endl;
}

