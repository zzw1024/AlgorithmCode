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
////	n = floor(sqrt(nn));//ȡСֵ
////	while (nn%n!=0)n--;//�ҵ�m,n
////	m = nn / n;
////	vector<vector<int>>arry(m, vector<int>(n, 0));	
////	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
////	int lm = 0, ln = 0;//���Ͻ�
////	int rm = m - 1, rn = n - 1;//���½�
////	int k = 0;//ʹ�����ݵ��½Ǳ�
////	while (lm <= rm && ln <= rn && k < nn)
////	{
////		if (lm == rm)//ֻ��һ�У����ӡ
////			for (int i = ln; i <= rn; ++i)
////				arry[lm][i] = v[k++];
////		else if (ln == rn)//ֻ��һ��
////			for (int i = lm; i <= rm; ++i)
////				arry[i][ln] = v[k++];
////		else
////		{
////			for (int i = ln; i < rn; ++i)//����
////				arry[lm][i] = v[k++];
////			for(int i=lm;i<rm;++i)//����
////				arry[i][rn]= v[k++];
////			for (int i = rn; i > ln; --i)//����
////				arry[rm][i] = v[k++];
////			for (int i = rm; i > lm; --i)
////				arry[i][ln] = v[k++];
////		}
////		lm++, ln++;//���Ͻ�������
////		rm--, rn--;//���½�������
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
//	int Lx = 0, Ly = 0, Rx = x - 1, Ry = y - 1, k = 0;//���ϽǺ����½�
//	while(Lx<=Rx && Ly<=Ry && k<n)
//	{
//		if (Lx == Rx)//ֻ��һ��
//			for (int i = Ly; i <= Ry; ++i)
//				matrix[Lx][i] = v[k++];
//		else if (Ly == Ry)//ֻ��һ��
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
