////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int n;
////int main()
////{
////	cin >> n;
////	vector<int>v(n);
////	for (int i = 0; i < n; ++i)
////		cin >> v[i];
////	sort(v.begin(), v.end());
////	int k = 0;
////	for (k = 0; k < n; ++k)
////		if (v[k] > n - k)
////			break;
////	cout << n - k;
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
//	int num = 0;
//	while (num<n && v[num]>num + 1)num++;
//	cout << num << endl;
//	return 0;		
//}