//#include "head.h"
//
//
////方法一：使用移动窗口
//string getLenghtSubstr(const string &str)
//{
//	if (str.length() < 2)return str;
//	string res, temp;
//	int L = 0, R = 1;
//	res.assign(str.begin() + L, str.begin() + R);
//	temp = res;
//	while (R < str.length())
//	{
//		if (temp.find(str[R])!=-1)
//		{
//			res = res.length() >= temp.length() ? res : temp;
//			L = R;
//			temp = "";
//		}
//		temp += str[R];
//		R++;
//	}
//	return res.length() >= temp.length() ? res : temp;
//}
//
////方法二：使用动态规划
////与移动窗口函数类似，只不过是用数组代替了string.find
//string DP(const string &str)
//{
//	if (str.length() <= 1)return str;
//	vector<int>word(26, -1);
//	string curStr = "", maxStr = "";
//	//int curL = 0, maxL = 0;
//	for (int i = 0; i < str.length(); ++i)
//	{
//		int index = word[str[i] - 'a'];
//		if (index<0 || i - index>curStr.length())//如果没出现过，或者出现的位置在我目前记录的子串的前面，那么第i个字母我可以添加
//			curStr += str[i];  //++curL
//		else //第i个字母重复在我目前记录的子串中
//		{
//			maxStr = curStr.length() > maxStr.length() ? curStr : maxStr;//先更新
//			//maxL = curL > maxL ? curL : maxL;
//			curStr += str[i];
//			curStr.erase(0, curStr.length() - (i - index));//删除重复节点
//			//curL = i-index;
//		}
//		word[str[i] - 'a'] = i;
//	}
//	return curStr.length() > maxStr.length() ? curStr : maxStr;
//	//return curL > maxL？ curL :maxL;
//}
//
//int main()
//{
//	cout << DP("a") << endl;
//	cout << DP("abcde") << endl;
//	cout << DP("arabcacfr") << endl;
//	return 0;
//}