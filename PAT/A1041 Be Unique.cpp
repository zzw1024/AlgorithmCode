//////#include <iostream>
//////#include <unordered_map>
//////using namespace std;
//////int N, num[100001];
//////int main()
//////{
//////	cin >> N;
//////	unordered_map<int, int> numbers;
//////	for (int i = 0; i < N; ++i)
//////	{
//////		cin >> num[i];
//////		numbers[num[i]]++;//为了保证单得到存数的位子顺序，借助num[i]
//////	}
//////	for (int i = 0; i < N; ++i)
//////	{
//////		if (numbers[num[i]] == 1)
//////		{
//////			cout << num[i] << endl;
//////			return 0;
//////		}
//////	}
//////	cout << "None" << endl;
//////	return 0;
//////}
////
////
////#include <iostream>
////#include <vector>
////using namespace std;
////int main()
////{
////	int n;
////	cin >> n;
////	vector<int>v(n);
////	int nums[10010] = { 0 };
////	for (int i = 0; i < n; ++i)
////	{
////		cin >> v[i];
////		nums[v[i]]++;
////	}
////	for (auto a : v)
////	{
////		if (nums[a] == 1)
////		{
////			cout << a << endl;
////			return 0;
////		}
////	}
////	cout << "None" << endl;
////	return 0;
////}
//
