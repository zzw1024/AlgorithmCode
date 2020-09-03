//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//int main()
//{
//	int T, M, L, X, Y;
//	cin >> T;
//	while (T--)
//	{
//		cin >> M >> L;
//		vector<vector<int>>v(M, vector<int>(M, 0));
//		for (int i = 0; i < M; ++i)
//			for (int j = 0; j < M; ++j)
//				cin >> v[i][j];
//		cin >> X >> Y;
//		int preL = 0, sX = 0, sY = 0, eX = 0, eY = 0;
//		while (preL != L)
//		{
//			preL = L;
//			sX = (X - L) < 0 ? 0 : (X - L);
//			sY = (Y - L) < 0 ? 0 : (Y - L);
//			eX = (X + L) > M - 1 ? M - 1 : (X + L);
//			eY = (Y + L) > M - 1 ? M - 1 : (Y + L);
//			for(int i=sX;i<=eX;++i)
//				for(int j=sY;j<=eY;++j)
//					if (v[i][j] > 0)
//						if ((X - i)*(X - i) + (Y - j)*(Y - j) <= L * L)
//						{
//							L += v[i][j];
//							v[i][j] = 0;
//						}
//		}
//		cout << L << endl;
//	}
//	return 0;
//}