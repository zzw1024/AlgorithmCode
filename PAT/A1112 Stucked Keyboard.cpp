////#include <iostream>
////#include <string>
////using namespace std;
////int main()
////{
////	int n;
////	string str, res = "", bad = "", temp = "";
////	int key[128] = { 0 };
////	cin >> n;
////	getchar();
////	getline(cin, str);
////	for (int i = 0; i < str.length();)
////	{
////		int j = i + 1;
////		while (j < str.length() && str[j] == str[i])//�ظ��ַ�
////			++j;
////		if (key[str[i]] >= 0)//���ǻ���
////			key[str[i]] = (j - i) % n == 0 ? 1 : -1;//�ظ�n���ǻ���
////		i = j;
////	}		
////	bool out[128] = { false };//��ʾ�Ƿ������
////	for (int i = 0; i < str.length();)
////	{
////		res += str[i];
////		if (key[str[i]] == 1)//Ϊ����
////		{
////			if (out[str[i]] == false)//��Ϊ�����
////				bad += str[i];
////			out[str[i]] = true;//�����
////			i += n;//�����ظ���
////		}
////		else
////			++i;//��������
////	}
////	cout << bad << endl << res << endl;
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	int k;
//	cin >> k;
//	string str, res = "";
//	cin >> str;
//	bool isExit[128] = { false }, isFail[128] = { false };
//	for (int i = 0; i < str.length(); ++i)
//	{
//		int n = 0;
//		isFail[str[i]] = false;
//		while (i < str.length() - 1 && str[i] == str[i + 1])
//		{
//			n++;
//			i++;
//		}
//		if ((n + 1) % k == 0 && isFail[str[i - 1]] == false)
//		{
//			isFail[str[i - 1]] = true;
//			res += str[i-1];
//		}
//	}
//	for (auto a : res)
//	{
//		if (isFail[a] == true && isExit[a] == false)
//		{
//			isExit[a] = true;
//			cout << a;
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < str.length(); ++i)
//		if (isFail[str[i]] == true)
//			str.erase(i, k - 1);
//	cout << str << endl;
//	return 0;
//}