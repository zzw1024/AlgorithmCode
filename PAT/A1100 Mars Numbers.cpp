////#include <iostream>
////#include <string>
////#include <unordered_map>
////using namespace std;
////int main() {
////	string low[13] = {//数字到火星文低位的映射
////		 "tret","jan","feb","mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
////	string high[13] = {//数字到火星文高位的映射
////		 "tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
////	unordered_map<string, int>temp;//火星文到数字的映射
////	for (int i = 0; i < 13; ++i) {
////		temp[low[i]] = i;
////		temp[high[i]] = i * 13;
////	}
////	int n;
////	scanf("%d%*c", &n);
////	string digit = "";
////	while (n--) {
////		getline(cin, digit);
////		if (isdigit(digit[0])) {//如果是数字
////			int k = stoi(digit);
////			if (k / 13 != 0)//高位不为0，输出高位
////				printf("%s", high[k / 13].c_str());
////			if (k / 13 != 0 && k % 13 != 0)//高位低位均不为0，输出空格
////				printf(" ");
////			if (k / 13 == 0 || k % 13 != 0)//高位为0或者高位不为0但低位为0时，输出低位
////				printf("%s", low[k % 13].c_str());
////			puts("");//换行
////		}
////		else {//是火星文
////			int k = 0;
////			stringstream stream(digit);
////			while (stream >> digit)//按空格键分割字符串
////				k += temp[digit];
////			printf("%d\n", k);
////		}
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	getchar();
//	string Mars[25] = { "tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
//		"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
//	while (n--)
//	{
//		string s;
//		getline(cin, s);
//		if (isdigit(s[0]))
//		{
//			int a = atoi(s.c_str());
//			if (a == 13)
//				cout << Mars[13] << endl;
//			else if (a > 13)
//				cout << Mars[a / 13+12] << " " << Mars[a % 13] << endl;
//			else 
//				cout << Mars[a % 13] << endl;
//		}
//		if (s.find(' ') == -1)
//		{
//			for (int i = 0; i < 25; ++i)
//				if (s == Mars[i])
//					cout << ((i > 12 ? (i - 12) * 13 : 0) + i % 13) << endl;
//		}
//		else
//		{
//			string s1, s2;
//			s1.assign(s.begin(), s.begin() + 3);
//			s2.assign(s.begin() + 4, s.end());
//			int nums = 0;
//			for (int i = 13; i < 25; ++i)
//				if (s1 == Mars[i])
//					nums += (i - 12) * 13;
//			for (int i = 0; i < 13; ++i)
//				if (s2 == Mars[i])
//					cout << nums + i << endl;
//		}
//	}
//	return 0;
//}
//
//
