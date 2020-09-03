//#include "000库函数.h"
//
//注意输入的字母排序是按照倒着的N排序的，然后让你根据这个倒置的N的图形进行按行排序输出
//按照半个N，即:一个竖和一个行的循环将数据输入到每一行中
//比如输入：0，1，2，3，4，5，6，7，8，9，10；4行
//其形状为
//0			6
//1		5	7
//2	4		8	10
//3			9
//按照半个N，即0，1，2，3 与4，5 为循环，然后确定半个N的大小为size = 2 * numRows - 2 = 6
//半个N的下竖为, 存入行[i%size]，上斜存入[size - i % size];
//
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		if (s.length() < 2 || numRows < 2)return s;
//		string res = "";
//		vector<string>rows(numRows, "");
//		int size = 2 * numRows - 2;//半个N的大小
//		for (int i = 0; i < s.length(); ++i)
//		{
//			int id = i % size;
//			if (id < numRows)//竖下
//				rows[id] += s[i];
//			else//斜上
//				rows[size - id] += s[i];
//		}
//		for (auto str : rows)
//			res += str;
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.convert("PAYPALISHIRING", 3) << endl;
//	cout << s.convert("PAYPALISHIRING", 4) << endl;
//	return 0;
//}