//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int n;
//vector<int>v;
//double res;
//int main()
//{
//	cin >> n;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end());
//	int nums = 0;
//	for (int i = 0; i < n;)
//	{
//		vector<int>temp;
//		int index = i;
//		temp.push_back(v[i]);
//		for (int j = i + 1; j < n; ++j)
//		{
//			if (v[j] = v[j-1] + 1)
//			{
//				temp.push_back(v[j]);
//				index = j;
//			}
//			else 
//				break;
//		}
//		i = index + 1;
//		int a = 1, sum = 0;
//		for (int j = 0; j < temp.size(); ++j)
//		{
//			a = sum + 1;
//			sum += a;
//			res += temp[j] * a;
//		}
//		nums = sum;
//		if (temp == v)//不能算全序列
//		{
//			res -= temp.back();
//			nums -= 1;
//		}
//	}
//	printf("%0.6f\n", res / nums);
//	return 0;
//
//}