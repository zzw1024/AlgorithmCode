//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
////题目贼恶心，竟然没有说出A存在的规律！！！！！
////首先，必须要有PAT存在，且不能有其他字符
////其次P与T中间A的个数乘以P之前的个数==T之后的A的个数！！！！！！！！！
//int main() {
//	int n;
//	cin >> n;
//	vector<string> v(n, "YES");
//	for (int i = 0; i < n; ++i) {
//		string s;
//		cin >> s;
//		int p = s.find('P');
//		int t = s.find('T');
//		int a = count(s.begin(), s.end(), 'A');//统计A的字符
//		if (p == -1 || t == -1 || (t - 1) <= p || a != (s.size() - 2)) {
//			//P或T或T不在P后面或存在其他字母则输出false
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
