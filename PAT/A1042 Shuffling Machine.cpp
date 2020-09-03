//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	int K, N = 54;
//	vector<string>cards(N + 1), res(N + 1), temp(N + 1);
//	vector<int>n(N + 1);
//	for (int i = 1; i <= N; ++i)
//	{
//		string s;
//		if (i <= 13)
//			s = "S" + to_string(i);
//		else if (i <= 26)
//			s = "H" + to_string(i - 13);
//		else if (i <= 39)
//			s = "C" + to_string(i - 26);
//		else if (i <= 52)
//			s = "D" + to_string(i - 39);
//		else
//			s = "J" + to_string(i - 52);
//		cards[i] = s;
//	}
//	cin >> K;
//	for (int i = 1; i <= N; ++i)
//		cin >> n[i];
//	res = cards;
//	for (int i = 0; i < K; ++i)
//	{
//		temp = res;
//		for (int j = 1; j <= N; ++j)
//			res[n[j]] = temp[j];
//	}
//	for (int i = 1; i <= N; ++i)
//		cout << res[i] << (i == N ? "" : " ");
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//vector<int>v(55, 0);
//vector<string>str(55, ""), s(55, "");
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= 54; ++i)
//		cin >> v[i];
//	string temp = "SHCDJ";
//	for (int i = 0; i < 54; ++i)
//	{
//		s[i + 1] += temp[i / 13];
//		s[i + 1] += to_string((i % 13 + 1));
//	}
//	str = s;
//	for (int i = 0; i < n; ++i)
//	{
//		str = s;
//		for (int j = 1; j <= 54; ++j)
//			s[v[j]] = str[j];		
//	}
//	for (int i = 1; i <= 54; ++i)
//		cout << (i == 1 ? "" : " ") << s[i];
//	return 0;
//}
