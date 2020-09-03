//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m;
//bool isHeap = true, isMaxHeap = true;
//vector<int>level, post;
//void DFS(int index, int &k)
//{
//	if (index >= m)return;
//	int L = 2 * index + 1, R = 2 * index + 2;
//	if ((isMaxHeap && ((L < m && level[index] < level[L]) || (R < m && level[index] < level[R]))) ||
//		(!isMaxHeap && ((L<m && level[index]>level[L]) || (R<m && level[index]>level[R]))))
//		isHeap = false;
//	DFS(L, k);
//	DFS(R, k);
//	post[k++] = level[index];
//}
//int main()
//{
//	cin >> n >> m;
//	level.resize(m);
//	post.resize(m);
//	while (n--)
//	{
//		for (int i = 0; i < m; ++i)
//			cin >> level[i];
//		isHeap = isMaxHeap = true;
//		isMaxHeap = level[0] > level[1];
//		int k = 0;
//		DFS(0, k);
//		if (isMaxHeap && isHeap)
//			printf("Max Heap\n");
//		else if (isHeap)
//			printf("Min Heap\n");
//		else
//			printf("Not Heap\n");
//		for (int i = 0; i < m; ++i)
//			printf("%s%d", i == 0 ? "" : " ", post[i]);
//		printf("\n");
//	}
//	return 0;
//}