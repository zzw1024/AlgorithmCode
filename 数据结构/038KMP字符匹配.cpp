//#include "000�⺯��.h"
////string text = "BBC ABCDAB ABCDABCDABDE";
////string pattern = "ABCDABD";
//string text = "substring searching algorithm";
//string pattern = "search";
////�����㷨
//int Violence()
//{
//	int i = 0, j = 0;
//	int slen = text.length(), plen = pattern.length();
//	while (i < slen && j < plen)
//	{
//		if (text[i] == pattern[j])
//		{
//			++i; 
//			++j;
//		}
//		else
//		{
//			i = i - j + 1;//�ص�������λ��
//			j = 0;
//		}
//	}
//	if (j == plen)
//		return i - j;
//	else
//		return -1;
//}
//
////KMP
////next�������ԭ����Ǹ���һ��ԭ���飬Ȼ���ԭ��������һλ����ƥ��
//void getNext(vector<int>&next)
//{
//	int j = 0;
//	int k = -1;//k�ǹؼ���k=0������ǰ׺���飬k=-1���ǽ�ǰ׺���������һλ
//	int len = pattern.length();
//	next[0] = -1;
//	while (j < len-1)
//	{
//		if (k == -1 || pattern[j] == pattern[k])//������������ԭ����ƥ��
//		{
//			++k;
//			++j;
//			next[j] = k;
//		}
//		else
//			k = next[k];//�ִӸ��������ͷ��ʼƥ�䣬-1��λ��
//	}
//}
//int KMP()
//{
//	int i = 0, j = 0;
//	int slen = text.length(), plen = pattern.length();
//	vector<int>next(pattern.length());
//	getNext(next);
//	while (i < slen && j < plen)
//	{
//		if (j == -1 || text[i] == pattern[j])//j==-1��ʾ��һ����ĸ��û��ƥ����
//		{
//			++i;
//			++j;
//		}
//		else
//			j = next[j];//һ��ûƥ�䣬����next�еĲ���
//	}
//	if (j == plen)//ƥ��ɹ�
//		return i - j;
//	else
//		return -1;
//}
//
//int Sunnday()
//{
//	int i = 0, j = 0;
//	int slen = text.length(), plen = pattern.length();
//	vector<int>local(128, -1);
//	for (int k = 0; k < plen; ++k)
//		local[pattern[k]] = k;//��ס�Ӵ���ÿ����ĸ����ҵ�λ��
//	while (i < slen && j <plen)
//	{
//		if (text[i] == pattern[j])
//		{
//			++i;
//			++j;
//		}
//		else
//		{
//			int k = i + plen - j;//�жϺ����һ����ĸ
//			if (k >= slen)break;
//			if (local[text[k]] == -1)//�������Ӵ���
//			{
//				j = 0;
//				i = k+1;//�������һλ
//			}
//			else//�����Ӵ���
//			{
//				j = 0;
//				i = k - local[text[k]];
//			}
//		}
//	}
//	if (j == plen)
//		return i - j;
//	else
//		return -1;
//}
//
//int main()
//{
//	cout << KMP() << endl;
//	cout << Sunnday() << endl;
//	return 0;
//}