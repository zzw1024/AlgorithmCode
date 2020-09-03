////#include <iostream>
////#include <algorithm>
////#include <vector>
////#include <cmath>
////using namespace std;
////int nn, m, n;
////int main()
////{
////	cin >> nn;
////	vector<int>v(nn);
////	for (int i = 0; i < nn; ++i)
////		cin >> v[i];
////	n = floor(sqrt(nn));//取小值
////	while (nn%n!=0)n--;//找到m,n
////	m = nn / n;
////	vector<vector<int>>arry(m, vector<int>(n, 0));	
////	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
////	int lm = 0, ln = 0;//左上角
////	int rm = m - 1, rn = n - 1;//右下角
////	int k = 0;//使用数据的下角标
////	while (lm <= rm && ln <= rn && k < nn)
////	{
////		if (lm == rm)//只有一行，则打印
////			for (int i = ln; i <= rn; ++i)
////				arry[lm][i] = v[k++];
////		else if (ln == rn)//只有一列
////			for (int i = lm; i <= rm; ++i)
////				arry[i][ln] = v[k++];
////		else
////		{
////			for (int i = ln; i < rn; ++i)//上行
////				arry[lm][i] = v[k++];
////			for(int i=lm;i<rm;++i)//右列
////				arry[i][rn]= v[k++];
////			for (int i = rn; i > ln; --i)//下行
////				arry[rm][i] = v[k++];
////			for (int i = rm; i > lm; --i)
////				arry[i][ln] = v[k++];
////		}
////		lm++, ln++;//左上角右下移
////		rm--, rn--;//右下角左上移
////	}
////	for (int i = 0; i < m; ++i)
////	{
////		for (int j = 0; j < n; ++j)
////			cout << arry[i][j] << (j == n - 1 ? "" : " ");
////		cout << endl;
////	}
////	return 0;
////}
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, x, y;
//	cin >> n;
//	x = y = sqrt(n);
//	while (x*y != n)
//		if (x*y < n)++x;
//		else if (x*y > n)y--;
//	vector<int>v(n);
//	vector<vector<int>>matrix(x, vector<int>(y));
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
//	int Lx = 0, Ly = 0, Rx = x - 1, Ry = y - 1, k = 0;//左上角和右下角
//	while(Lx<=Rx && Ly<=Ry && k<n)
//	{
//		if (Lx == Rx)//只有一行
//			for (int i = Ly; i <= Ry; ++i)
//				matrix[Lx][i] = v[k++];
//		else if (Ly == Ry)//只有一列
//			for (int i = Lx; i <= Rx; ++i)
//				matrix[i][Ly] = v[k++];
//		else
//		{
//			for (int i = Ly; i < Ry; ++i)
//				matrix[Lx][i] = v[k++];
//			for (int i = Lx; i < Rx; ++i)
//				matrix[i][Ry] = v[k++];
//			for (int i = Ry; i > Ly; --i)
//				matrix[Rx][i] = v[k++];
//			for (int i = Rx; i > Lx; --i)
//				matrix[i][Ly] = v[k++];
//			Lx++;
//			Ly++;
//			Rx--;
//			Ry--;
//		}
//	}
//	for (auto a : matrix)
//	{
//		for (int i = 0; i < y; ++i)
//			cout << (i == 0 ? "" : " ") << a[i];
//		cout << endl;
//	}
//	return 0;
//}
//
