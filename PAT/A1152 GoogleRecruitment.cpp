//#include <iostream>
//#include <vector>
//#include <string>
//#include <cmath>
//using namespace std;
//int n, k;
//string str, res = "";
////void getPrimeTable(int inf, vector<bool>&notPrime)//����������
////{
////	notPrime[0] = notPrime[1] = true;
////	for (int i = 2; i <= inf; ++i)
////		if (notPrime[i] == false)//��2���������ʼ
////			for (int j = 2; j*i <= inf; ++j)
////				notPrime[j*i] = true;//�޳����������б���
////}
//
//bool isPrime(int x)//�ж��ǲ�������
//{
//	if (x < 3)
//		return true;
//	for (int i = 2; i*i <= x; ++i)
//		if (x%i == 0)
//			return false;
//	return true;
//}
//int main()
//{
//	cin >> n >> k;
//	cin >> str;
//	//int size = (int)pow(10, k);
//	//vector<bool>notPrime(size+1, false);//��ֹ�ڴ�̫���������Ƕ�̬���������
//	//getPrimeTable(size, notPrime);//����������
//	for (int i = 0; i + k <= n; ++i)
//	{
//
//		string s = str.substr(i, k);
//		int num = atoi(s.c_str());
//		if (isPrime(num))//notPrime[num]==false)//ʹ�õĴ���򵥵������жϣ�ע�͵Ĵ�����ʹ��������
//		{
//			res = s;
//			break;
//		}
//	}
//	if (res.size() > 0)
//		cout<<res;
//	else
//		cout << "404";
//	return 0;
//}
