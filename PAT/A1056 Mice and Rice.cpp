////#include <iostream>
////#include <vector>
////#include <queue>
////using namespace std;
////int Np, Ng, w[1010], res[1010];
////int main()
////{
////	cin >> Np >> Ng;
////	for (int i = 0; i < Np; ++i)
////		cin >> w[i];
////	queue<int>q;
////	for (int i = 0; i < Np; ++i)
////	{
////		int a;
////		cin >> a;
////		q.push(a);
////	}
////	while (q.size() > 1)//即在产生冠军前需要继续迭代
////	{
////		int group = q.size() / Ng + (q.size() % Ng == 0 ? 0 : 1);
////		int size = q.size();
////		for (int i = 1; i <= group; ++i)
////		{
////			int lastN = i == group ? (size - (group - 1)*Ng) : Ng;//每组队员数量
////			int index = q.front();
////			for (int j = 0; j < lastN; ++j)
////			{
////				res[q.front()] = group + 1;//loser的排名为分组数量 + 1
////				index = w[index] > w[q.front()] ? index : q.front();
////				q.pop();
////			}
////			q.push(index);//存下小组冠军的序号
////		}
////	}
////	res[q.front()] = 1;//产生冠军
////	for (int i = 0; i < Np; ++i)
////		cout << res[i] << (i == Np - 1 ? "" : " ");
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<int>v(n), nums(n), temp, rank(n, 0);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	for (int i = 0; i < n; ++i)
//		cin >> nums[i];	
//	vector<vector<int>>res, array;
//	temp = nums;
//	res.push_back(temp);
//	while (temp.size() > 1)
//	{
//		int size = temp.size();
//		array.resize(size / k + (size % k == 0 ? 0 : 1));
//		for (int i = 0; i < temp.size(); ++i)
//			array[i / k].push_back(temp[i]);
//		temp.clear();
//		for (int i = 0; i < array.size(); ++i)
//		{
//			sort(array[i].begin(), array[i].end(), [=](int a, int b) {return v[a] > v[b]; });
//			temp.push_back(array[i][0]);
//		}
//		res.push_back(temp);
//		array.clear();
//	}
//	int r = 1;
//	for (int i = res.size() - 1; i >= 0; i--)
//	{		
//		int t = 0;
//		for (auto a : res[i])
//		{
//			if (rank[a] == 0)//未排等级
//			{
//				rank[a] = r;
//				t++;
//			}
//		}	
//		r += t;
//	}
//	for (int i = 0; i < n; ++i)
//		cout << (i == 0 ? "" : " ") << rank[i];
//	return 0;
//}