//#include <iostream>
//#include <vector>
//#include <list>
//
//using namespace std;
//
////����Ŀ��
////��������arr������num���������ж��ٸ��������������������
////max��arr[i.j]�� - min��arr[i.j]�� <= num max��arfi.j]����ʾ������ar[ij]�е����ֵ��min��arli.j]����ʾ������arr[i.j]�е���Сֵ��
////��Ҫ��
////������鳤��ΪN����ʵ��ʱ�临�Ӷ�ΪO��N���Ľⷨ��
////����⡿
////ʹ����������ջ��һ��ջά�ִӴ�С������ͷ����Զ�����ֵ
////һ��ά�ִ�С���������ͷ����Զ������Сֵ
////Ȼ��ʹ�ô��ڽ��������ƶ�
////�����ƺ������С���numʱ������������������ɵ���������������Ϊ����������Ҫ��
////��ô����Ķ����������Ҫ��
////Ȼ��������ƣ��������С������Ҫ��
//
//int getSubArrayNum(vector<int>v, int num)
//{
//	int l, r, res = 0;
//	list<int>maxl, minl;
//	for (l=-1,r=0;l<r && r<v.size();++r)
//	{
//		while (!maxl.empty() && v[r] > v[maxl.back()])			
//			maxl.pop_back();
//		while (!minl.empty() && v[r] < v[minl.back()])
//			minl.pop_back();
//		maxl.push_back(r);
//		minl.push_back(r);
//		if (v[maxl.front()] - v[minl.front()] > num)
//			res += r - l;
//		while(v[maxl.front()] - v[minl.front()] > num)
//		{
//			++l;
//			if (maxl.front() == l)
//				maxl.pop_front();
//			if (minl.front() == l)
//				minl.pop_front();
//		}
//	}
//	res += r - l;
//	return res;
//}
//
//
//int main()
//{
//	vector<int>v = { 8,5,4,6,9,1,4,5,7,8,6,3,4,5,9,8 };
//	int num = 4;
//	cout << getSubArrayNum(v, num) << endl;
//	return 0;
//}