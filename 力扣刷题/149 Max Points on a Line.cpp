//#include "000¿âº¯Êý.h"
//
//struct Point {
//    int x;
//    int y;
//    Point() : x(0), y(0) {}
//    Point(int a, int b) : x(a), y(b) {}
//};
//
//class Solution01 {
//public:
//	int maxPoints(vector<Point> &points) {	
//		int res = 0;
//		for (int i = 0; i < points.size(); ++i)
//		{
//			map<pair<int, int>, int>m;
//			int same = 1;
//			for (int j = i + 1; j < points.size(); ++j)
//			{
//				if (points[i].x == points[j].x && points[i].y == points[j].y)
//				{
//					++same;
//					continue;
//				}
//				int dy = points[j].y - points[i].y;
//				int dx = points[j].x - points[i].x;
//				int d = gcd(dx, dy);
//				++m[{dx / d, dy / d}];				
//			}		
//			res = max(res, same);
//			for (auto ptr = m.begin(); ptr != m.end(); ++ptr)
//				res = max(res, ptr->second + same);
//		}
//		return res;
//	}
//	int gcd(int a, int b)
//	{
//		return b == 0 ? a : gcd(b, a%b);
//	}
//};
//class Solution02 {
//public:
//	int maxPoints(vector<vector<int>>& points) {
//		if (points.size() < 3)return points.size();
//		int res = 0;
//		for (int i = 0; i < points.size(); ++i)
//		{
//			map<pair<int, int>, int>m;
//			int same = 1;
//			for (int j = i + 1; j < points.size(); ++j)
//			{
//				if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
//				{
//					++same;
//					continue;
//				}
//				int dy = points[j][1] - points[i][1];
//				int dx = points[j][0] - points[i][0];
//				int d = gcd(dx, dy);
//				++m[{dx / d, dy / d}];
//			}
//			res = max(res, same);
//			for (auto ptr = m.begin(); ptr != m.end(); ++ptr)
//				res = max(res, ptr->second + same);
//		}
//		return res;
//	}
//	int gcd(int a, int b)
//	{
//		return b == 0 ? a : gcd(b, a%b);
//	}
//};
//
//class Solution03 {
//public:
//	int maxPoints(vector<vector<int>>& points) {
//		if (points.size() < 3)return points.size();
//		int res = 0;		
//		for (int i = 0; i < points.size(); ++i)
//		{
//			int same = 1;
//			for (int j = i + 1; j < points.size(); ++j)
//			{
//				int cnt = 0;
//				long long int x1 = points[i][0], x2 = points[j][0];
//				long long int y1 = points[i][1], y2 = points[j][1];
//				if (x1 == x2 && y1 == y2) { ++same; continue; }
//				for (int k = 0; k < points.size(); ++k)
//				{
//					long long int x3 = points[k][0], y3 = points[k][1];
//					if ((x1*y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3) == 0)
//						++cnt;
//				}
//				res = max(res, cnt);
//			}
//			res = max(res, same);
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution01 s;
//	vector<Point> points = { {1,1}, {2,2}, {3,3} };
//	cout << s.maxPoints(points) << endl;
//	points = { {1,1}, {1,4},{2,3},{3,2},{4,1},{5,3}};
//	cout << s.maxPoints(points) << endl;
//	while (1);
//
//}