//#include "000�⺯��.h"
//int n;
//vector<int>v = { 46,4,11,2,0,5,23,6,17,8,10,9 };
//void swap(int a, int b)
//{
//	int temp = v[a];
//	v[a] = v[b];
//	v[b] = temp;
//}
//
//
////01������
//void Sort01()
//{
//	for (int i = 0; i < n; ++i)
//	{
//		int minV = v[i], index = i;
//		for (int j = i + 1; j < n; ++j)
//		{
//			if (minV > v[j])
//			{
//				minV = v[j];
//				index = j;
//			}
//		}
//		swap(i, index);
//	}
//}
//
////02ð������
//void Sort02()
//{
//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < n - i - 1; ++j)
//			if (v[j] > v[j + 1])
//				swap(j, j + 1);
//}
//
////03ѡ������
//void Sort03()
//{
//	for (int i = 0; i < n; ++i)
//	{
//		int index = i;
//		for (int j = i + 1; j < n; ++j)
//			if (v[index] > v[j])
//				index = j;
//		if (index != i)
//			swap(i, index);
//	}
//}
////04ֱ�Ӳ�������
//void Sort04()
//{
//	int temp;//��ʱ�ڱ�
//	for (int i = 1; i < n; ++i)
//	{
//		temp = v[i];
//		int j = i - 1;
//		for (; j >= 0; --j)//��i��ǰһλ��ʼ�Ӻ���ǰ�Ƚ�
//			if (temp < v[j])
//				v[j + 1] = v[j];//�����
//			else
//				break;//�ҵ�λ����
//		v[j+1] = temp;//ע�⣬j��ǰ�ƶ���
//	}
//}
////05ϣ������
//void Sort05()
//{
//	for (int gap = n / 2; gap > 0; gap /= 2)//gapΪ��Ŀ�ȣ���ʼȡ���ȵ�һ�룬�˺�ÿһ�ζ��۰�ȡ
//	{
//		//����ÿ�����Ϊgap�����ݽ��в�������
//		for (int i = 0; i < gap; ++i)//ÿ��i����Ϊgap��jһ��Ƚ�
//		{
//			for (int j = i + gap; j < n; j+=gap)//j��Ӧ����i�Ŀ��Ϊgap����ֵ
//			{
//				if (v[j] < v[j - gap])//���ǰС��Ӧ����ǰ����
//				{
//					int k = j - gap, temp = v[j];//temp�ڱ�
//					while (k >= 0 && v[k] > temp)
//					{
//						v[k + gap] = v[k];//����
//						k -= gap;
//					}
//					v[k + gap] = temp;//k-gap�ˣ��������gap
//				}
//			}
//		}
//	}
//}
////06��������
//void Merge(int iL, int iR, int jL, int jR)//�˴���L��R�ֱ�Ϊ����С����ı߽�
//{
//	vector<int>temp(jR - iL + 1);//���ٴ�СΪ��������Ĵ�С�ռ�
//	int k = 0, i = iL, j = jL;
//	while (i <= iR && j <= jR)
//	{
//		if (v[i] <= v[j])//�˴��ĵȺű�֤���㷨���ȶ��ԣ�ʹ����ͬ��ֵǰ��λ�ò���
//			temp[k++] = v[i++];
//		else
//			temp[k++] = v[j++];
//	}
//	while (i <= iR)//����1δ��
//		temp[k++] = v[i++];
//	while (j <= jR)//����2δ��
//		temp[k++] = v[j++];
//
//	for (i = iL, k = 0; i <= jR; ++k, ++i)//���鲢���ź������ֵ��ֵ��ԭ����
//		v[i] = temp[k];
//}
////�Ե����ϣ��ǵݹ�桾С���鵽�����顿
//void Sort06()
//{
//	//stepΪС����Ĵ�С���˴�step�Ĵ���Ϊ����С����Ĵ�С���ʶ���2�ı���
//	for (int step = 2; step / 2 < n; step *= 2)//1&1�飬2&2�飬4&4�顣������
//	{//һ���Ǵ�1��1�����鿪ʼ��������Ȼ��û����֤������
//		for (int i = 0; i < n; i += step)
//			//sort(v + i, v + min(i + step, n));//ֱ��ʹ���Դ���sort������������
//			if ((i + step / 2 ) < n)//�м�ڵ�
//				Merge(i, i + step / 2 - 1, i + step / 2, min(i + step - 1, n - 1));//��i��ʼ���ڿ��Ϊstep�з�Ϊ����С������й鲢
//	}
//}
////�Զ����£��ݹ�桾�����鵽С���顿
//void Sort07(int L, int R)
//{
//	if (L < R)
//	{
//		int mid = L + (R - L) / 2;//���е�
//		Sort07(L, mid);//����߽��еݹ��зֳ�С����
//		Sort07(mid + 1, R);//���ұ߽��еݹ��зֳ�С����
//		Merge(L, mid, mid + 1, R);//���������߽��й鲢
//	}
//}
//
////��������
////��������л���
//int Partition(int L, int R)
//{
//	//int p = round(1.0*rand() / RAND_MAX * (R - L) + L);//ѡȡ���λ�õ���Ϊ��׼ֵ
//	//swap(v[L], v[p]);//����׼ֵ���������
//	int key = v[L];//һ��Ĭ��ʹ������˵�ֵΪ��׼ֵ
//	while (L < R)
//	{
//		while (L < R && v[R]>key)--R;//��������ֱ���ҵ���keyС����
//		v[L] = v[R];//��С�����Ƶ����
//		while (L < R && v[L] <= key)++L;//�������ң�ֱ���ҵ���key����
//		v[R] = v[L];//��������Ƶ��ұ�
//	}
//	v[L] = key;//key���м��λ��
//	return L;//�����е�����
//}
//
//void Sort08(int L, int R)
//{
//	if (L < R)
//	{
//		int pos = Partition(L, R);
//		Sort08(L, pos - 1);//������������п�������
//		Sort08(pos + 1, R);//������������п�������
//	}
//}
////�����򣺴����
////���µ���
//void downAdjust(int L, int R)
//{
//	int i = L, j = 2 * L + 1;//iΪ���ڵ㣬jΪ���ӽڵ�
//	while (j <= R)
//	{
//		if (j + 1 <= R && v[j + 1] > v[j])//�����ҽڵ㣬���ҽڵ����ô��ѡ�ҽڵ�,��ѡȡ�����ӽڵ��븸�ڵ�Ա�
//			++j;//ѡȡ���ҽڵ�
//		if (v[j] <= v[i])//���ӽڵ㶼�ȸ��ڵ�С�������������������
//			break;
//		//������Ļ�����ô�Ҿͽ�����ӽڵ�j�븸�ڵ�i�Ե�,
//		swap(i, j);
//		i = j;
//		j = 2 * i + 1;//�������±���
//	}
//}
////����
//void createHeap()
//{
//	for (int i = n / 2; i >= 0; --i)
//		downAdjust(i, n - 1);
//}
////ɾ���Ѷ�Ԫ��
//void deleteTop()
//{
//	v[0] = v[n - 1];//Ҳ���ǶѶ�ʹ�����һ����ֵ�����
//	downAdjust(0, n - 2);//Ȼ���ǰn-1������������
//}
//void Sort09()
//{
//	createHeap();//����
//	for (int i = n - 1; i > 0; --i)//�����ʼ������ֱ��ֻʣ�����һ������
//	{
//		swap(i, 0);//ÿ�ζ������ֵ�ŵ����
//		downAdjust(0, i - 1);//��ǰ0-i���������¹��ɴ����
//	}
//}
//
////���Ԫ�أ�
////���ϵ���
//void  upAdjust(int L, int R)
//{
//	int  i = R, j = (i - 1) / 2;//iΪ��������㣬jΪ�丸��
//	while (j >= L)
//	{
//		if (v[j] < v[i])//���ڵ�С�ˣ���ô�ͽ����ӽڵ������
//		{
//			swap(v[i], v[j]);
//			i = j;
//			j = (i - 1) / 2;//�������ϱ���
//		}
//		else//�������
//			break;
//	}
//}
//void insert(int  x)
//{
//	v[n] = x;//���¼����ֵ���������������мǱ�֤����ռ����
//	upAdjust(0, n);//���ϵ����¼���Ľ��n
//}
//
////��������
//void Sort10()
//{
//	int minN = v[0], maxN = v[0];
//	for (auto a : v)//�ҳ����ֵ����Сֵ
//	{
//		minN = minN < a ? minN : a;
//		maxN = maxN > a ? maxN : a;
//	}
//	vector<int>nums(maxN - minN + 1, 0);//�Կռ任ȡʱ�䣬��������ÿ����������
//	for (auto a : v)
//		++nums[a - minN];
//	for (int i = 0, k = 0; i < nums.size(); ++i)//��������ԭ����
//		while (nums[i]--)
//			v[k++] = i + minN;
//}
//
////Ͱ����
//void Sort11()
//{
//	int minN = v[0], maxN = v[0];
//	for (auto a : v)//�ҳ����ֵ����Сֵ
//	{
//		minN = minN < a ? minN : a;
//		maxN = maxN > a ? maxN : a;
//	}
//	vector<vector<int>>bucket((maxN-minN)/10+1);//�����ǰ������ݷ�Χ���е�����
//	for (auto a : v)//�����ݷ����Ӧ��Ͱ��
//		bucket[(a - minN) / 10].push_back(a);
//	for (int i = 0; i < bucket.size(); ++i)
//		sort(bucket[i].begin(), bucket[i].end());//�ֱ��ÿ��Ͱ�������򣬿���ʹ������������㷨�����˸о�û��Ҫʹ�ø��ӵ������㷨
//	int k = 0;
//	for (auto a : bucket)//�����ݸ���ԭ����
//		for (auto b : a)
//			v[k++] = b;
//}
//
////��������
//void Sort12()
//{
//	int maxBit = 0;//����λ��
//	int bit = 1;//�ȴӸ�λ��ʼ
//	for (auto a : v)
//	{
//		int len = to_string(a).length();//�����Ҿ�͵��ֱ��ʹ��string��ת��
//		maxBit = maxBit > len ? maxBit : len;
//	}	
//	for (int i = 1; i <= maxBit; ++i)//�������ж���λ�ͽ��ж��ٴ�����
//	{
//		vector<vector<int>>count(10);//���λ������ֵ��ͬ������
//		for (auto a : v)
//			count[(a % (bit * 10) / bit)].push_back(a);//���յ�bitλ�Ͻ�������
//		int k = 0;
//		for (auto a : count)
//			for (auto b : a)
//				v[k++] = b;//�����ݷŻ�
//		bit *= 10;//��ǰһλ
//	}
//}
//int main()
//{
//	n = v.size();
//	vector<int>org = v;
//	Sort12( );
//
//
//	for (auto a : v)
//		cout << a << " ";
//	return 0;
//}
