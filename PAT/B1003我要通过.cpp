//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
////��Ŀ�����ģ���Ȼû��˵��A���ڵĹ��ɣ���������
////���ȣ�����Ҫ��PAT���ڣ��Ҳ����������ַ�
////���P��T�м�A�ĸ�������P֮ǰ�ĸ���==T֮���A�ĸ���������������������
//int main() {
//	int n;
//	cin >> n;
//	vector<string> v(n, "YES");
//	for (int i = 0; i < n; ++i) {
//		string s;
//		cin >> s;
//		int p = s.find('P');
//		int t = s.find('T');
//		int a = count(s.begin(), s.end(), 'A');//ͳ��A���ַ�
//		if (p == -1 || t == -1 || (t - 1) <= p || a != (s.size() - 2)) {
//			//P��T��T����P��������������ĸ�����false
//			v[i] = "NO";
//			continue;
//		}
//		else if (p*(t - p - 1) != (s.size() - 1 - t)) {
//			v[i] = "NO";
//			continue;
//		}
//	}
//	for (int i = 0; i < n; ++i) {
//		cout << v[i] << endl;
//	}
//
//	return 0;
//}
//
