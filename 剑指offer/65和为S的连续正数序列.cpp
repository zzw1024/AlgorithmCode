//#include "head.h"
//
//
////��һ�ַ������ҹ���
////��num��ʼ����num+n���ɵ����к� == sum
////ô��ᷢ�֣�����Щ��ȫ����ȥ(num-1)�󹹳����� 1,2,3,4,5,,,,n,�����ǵĺ�Ϊn*(n+1)/2
////���������������б����㣺 n*(num-1) + n*(n+1)/2 == sum 
//class Solution01 {
//public:
//	vector<vector<int> > FindContinuousSequence(int sum) {
//		vector<vector<int> >res;
//		for (int i = 1; i < sum; ++i)
//		{
//			int theta = (2 * i - 1)*(2 * i - 1) + 8 * sum;
//			int gen = sqrt(theta);
//			if (gen*gen != theta)continue;
//			int a = (1 - 2 * i) + gen;
//			if (a % 2 != 0)continue;
//			vector<int>temp;
//			for (int j = 0; j < a / 2; ++j)
//				temp.push_back(i + j);
//			res.push_back(temp);
//		}
//		return res;
//	}
//};
//
////�ڶ��ַ�������������
////ʹ�û������ڣ��ʹ��ˣ�����ָ�����ƣ����³���������С�ˣ�����ָ�����ƣ���������
//class Solution {
//public:
//	vector<vector<int> > FindContinuousSequence(int sum) {
//		if (sum < 3)return{};
//		vector<vector<int> >res;
//		int L = 1, R = 2, S = 1 + 2;
//		while (L < R && R < sum){
//			if (S == sum){
//				vector<int>temp;
//				for (int j = L; j <= R; ++j)
//					temp.push_back(j);
//				res.push_back(temp);
//			}
//			if (S >= sum) {
//				S -= L;
//				++L;
//			}
//			else {
//				++R;
//				S += R;
//			}
//		}
//		return res;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<vector<int>>v = s.FindContinuousSequence(15);
//	for (auto a : v)
//	{
//		for (auto b : a)
//			cout << b << " ";
//		cout << endl;
//	}
//	return 0;
//}