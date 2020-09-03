//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int T, n;
//	vector<int>v = { 1,2,3,4,5,6,7,8,9,10 };
//	cin >> T;
//	while (T--)
//	{
//		cin >> n;
//		vector<int>A(n), V(n);
//		int minN = n + 1, sum = 0, index = 0;
//		for (int i = 0; i < n; ++i)
//			cin >> A[i];
//		
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> V[i];
//			sum += V[i];
//			if (minN > V[i])
//			{
//				minN = V[i];
//				index = i;
//			}
//		}
//		vector<int>temp = V;
//		sort(temp.begin(), temp.end());
//		if (A.size() % 2 == 0)
//			cout << sum << endl;
//		else
//		{
//			if(index = A.size()/2+1)
//				cout << sum +temp[2] << endl;
//			else
//				cout << sum + temp[1] << endl;
//		}			
//	}
//	return 0;
//}