//#if 0
////这个题的坑就在于n是一个及其长的数字，故只能有容器来存放
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main() {
//	string str;
//	cin >> str;
//	int s = 0;
//	for (auto a : str)
//		s += (a - '0');
//	vector<string>v;
//	while (s) {
//		string str;
//		switch (s % 10)
//		{
//		case 0:
//			str = "ling";
//			v.push_back(str);
//			break;
//		case 1:
//			str = "yi";
//			v.push_back(str);
//			break;
//		case 2:
//			str = "er";
//			v.push_back(str);
//			break;
//		case 3:
//			str = "san";
//			v.push_back(str);
//			break;
//		case 4:
//			str = "si";
//			v.push_back(str);
//			break;
//		case 5:
//			str = "wu";
//			v.push_back(str);
//			break;
//		case 6:
//			str = "liu";
//			v.push_back(str);
//			break;
//		case 7:
//			str = "qi";
//			v.push_back(str);
//			break;
//		case 8:
//			str = "ba";
//			v.push_back(str);
//			break;
//		case 9:
//			str = "jiu";
//			v.push_back(str);
//			break;
//		default:
//			break;
//		}
//		s = s / 10;
//	}
//	while (v.size() > 1) {
//		cout << v.back() << " ";
//		v.pop_back();
//	}
//	cout << v.back() << endl;
//	system("pause");
//	return 0;
//}
//
//#endif