//#include "000�⺯��.h"
//
//- ��pΪ�գ���sҲΪ�գ����� true����֮���� false��
//
//- ��p�ĳ���Ϊ1����s����ҲΪ1������ͬ����pΪ '.' �򷵻� true����֮���� false��
//
//- ��p�ĵڶ����ַ���Ϊ * ������ʱsΪ�շ��� false�������ж����ַ��Ƿ�ƥ�䣬
//  �ҴӸ��Եĵڶ����ַ���ʼ���õݹ麯��ƥ�䡣
//
//- ��p�ĵڶ����ַ�Ϊ * ����������ѭ������������s��Ϊ�������ַ�ƥ�䣨���� p[0] Ϊ�㣩��
//  ���õݹ麯��ƥ��s��ȥ��ǰ�����ַ���p����������ԭ���Ǽ����ʱ���Ǻŵ���������ǰ��
//  ���ַ�����0�Σ���֤�Ƿ�ƥ�䣩����ƥ�䷵�� true������sȥ������ĸ����Ϊ��ʱ����ĸƥ���ˣ�
//  ���ǿ���ȥ��s������ĸ����p�����Ǻŵ����ã����������������ĸ�����Բ���Ҫȥ������
//  ��������ѭ����
//
//- ���ص��õݹ麯��ƥ��s��ȥ��ǰ�����ַ���p�Ľ������ô����ԭ���Ǵ����Ǻ��޷�ƥ������ݣ�
//  ���� s = "ab", p = "ab"��ֱ�ӽ��� while ѭ�������Ƿ��� "ab" �� "b" ��ƥ�䣬����s��� "b"��
//  ��ô��ʱ����ѭ���󣬾͵����� return ���Ƚ� "b" �� "b" �ˣ����� true���پٸ����ӣ�
//  ���� s = "", p = "a"������sΪ�գ���������κε� if �� while��ֻ�ܵ����� return ���Ƚ��ˣ�
//  ���� true����ȷ����
//
//
//
//class Solution {
//public:
//	bool isMatch(string s, string p) {
//		if (p.empty())return s.empty();
//		if (p.size() > 1 && p[1] == '*')//��ס����*����ͷû���κ��ô�
//		{
//			bool f1 = isMatch(s, p.substr(2));//��������*����Ϊ�����κ����ã�ֱ��ƥ�������ַ�
//			bool f2 = (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));//��һ��ƥ�����ˣ�֮���Բ�ȥ��p�ĵ�һ����ĸ������Ϊ��*�����Ե���0����һ����ĸƥ��
//			return f1 || f2;
//			//return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
//		}
//		else//�ڶ�����ĸ��Ϊ��*������ô��һ������Ҫ��ƥ��
//			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));		
//	}
//};
//
//DP�ⷨ��
//	����Ҳ������ DP ���⣬����һ����ά�� DP ���飬
//	���� dp[i][j] ��ʾ s[0, i) �� p[0, j) �Ƿ� match��
//	Ȼ�����������������
//1.  dp[i][j] = dp[i - 1][j - 1]�� if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//    ��,��ĸ����Ϊ��*�������ַ�ƥ������,�Ǿ;�����ǰ����ַ��Ƿ�ƥ������
//2.  dp[i][j] = dp[i][j - 2]��if p[j - 1] == '*' and the pattern repeats for 0 times;
//	  ����ǰ��ġ�*�������ϣ���Ϊ'*'ǰ����ַ�ƥ������
//3.  dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')��if p[j - 1] == '*' and the pattern repeats for at least 1 times.
//	  ������*����ǰ����ĸ���ʱ����ĸƥ�����ˣ���ô�ͽ���*��ǰ�����ĸ���ٸ���һ��
//
//class Solution2 {
//public:
//	bool isMatch(string s, string p) {
//		if (p.empty())return s.empty();
//		int m = s.size(), n = p.size();
//		vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, false));
//		dp[0][0] = true;//��Ϊ��ʱ
//		for (int i = 0; i < m + 1; ++i)
//		{
//			for (int j = 1; j < n + 1; ++j)
//			{
//				if (p[j - 1] != '*')
//					dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
//				else
//					dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//			}
//		}
//		return dp[m][n];
//	}
//};
//
//
//
//int main()
//{
//	char c[] = "123456";
//	char *p = c;
//	int m = 0;
//	while (p[m] != '\0')++m;
//	int a = 0;
//
//}
//
//int maxMethodsDp(vector<int>arr, int aim)
//{
//	vector<vector<int>>dp(arr.size() + 1, vector<int>(aim + 1, 0));
//	dp[arr.size()][0] = 1;
//	for (int i = arr.size() - 1; i >= 0; --i)
//	{
//		for (int j = 0; j <= aim; ++j)
//		{
//			dp[i][j] = dp[i + 1][j];//i����ֵȡ��0��
//			for (int subAim = j - arr[i]; subAim >= 0; subAim = subAim - arr[i])//i����ֵȡ��1��2.����
//				dp[i][j] = dp[i + 1][subAim];
//		}
//	}
//	return dp[0][aim];
//}
