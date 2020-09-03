#include "000�⺯��.h"

//��Ϊ���ͽ���
//p�����Ǻŵ�λ�ú���Ҫ����jStar����ʾ�������Ǻ�ƥ�䵽s���е�λ�ã�
//ʹ��iStart����ʾ������ iStar �� jStar ����ʼ��Ϊ - 1����ʾĬ���������û���Ǻŵġ�
//Ȼ��������������i��j�ֱ�ָ��ǰs����p���б�������λ�á�
//
//��ʼ����ƥ�䣬��iС��s���ĳ��ȣ�����whileѭ��������ǰ�����ַ���ȣ�
//����p�е��ַ����ʺţ���i��j�ֱ��1����p[j] ���Ǻţ���ô����Ҫ��¼�Ǻŵ�λ�ã�
//pStar��Ϊj����ʱj������1��iStar��Ϊi������ǰp[j] �����Ǻţ����Ҳ��ܸ�p[i] ƥ���ϣ�
//��ô��ʱ��Ҫ���Ǻ��ˣ���֮ǰ�Ǻ�û���ֹ�����ô��ֱ�ӹ򣬱��� s = "aa" �� p = "c*"��
//��ʱ s[0] �� p[0] �޷�ƥ�䣬��Ȼp[1] ���Ǻţ������ǹ�����Ǻ�֮ǰ���ֹ�������ǿ����һ������
//���� s = "aa" �� p = "*c"�������� s[1] �� p[1] �޷�ƥ��ʱ�����Ǻ���֮ǰ p[0] �������Ǻţ�
//���ǰ� s[1] ���� p[0] ���Ǻ�ȥƥ�䡣�������֪��֮ǰ��û���Ǻţ���ʱ���ܿ��� iStar �������ˣ�
//��Ϊ���ʼ��Ϊ - 1���������Ǻ�ʱ����ͻᱻ����Ϊi����ô����ֻҪ��� iStar ��ֵ��
//����֪���Ƿ����ʹ���Ǻ���������Ȼ�ɹ���������ƥ������s�е������ַ�������֮�����ǻ�Ҫ���p����
//��ʱûƥ�����p����ֻ��ʣ�Ǻţ��������������ַ������������ǺŹ��˵������j������p�ĳ��ȣ�
//�򷵻�false���μ��������£�


//60ms
class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, iStar = -1, jStar = -1;
		while (i < s.size()) {
			if (s[i] == p[j] || p[j] == '?') {
				++i; ++j;
			}
			else if (p[j] == '*') {
				iStar = i;
				jStar = j++;
			}
			else if (iStar >= 0) {
				i = ++iStar;
				j = jStar + 1;
			}
			else return false;
		}
		while (p[j] == '*') ++j;
		return j == p.size();
	}
};


//ʹ�ö�̬�滮
//260ms
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i) {
			if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
				else {
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};

//ʹ�õݹ�˼��
//�����ֲ�ͬ��״̬������0��ʾƥ�䵽��s����ĩβ������δƥ��ɹ���
//����1��ʾδƥ�䵽s����ĩβ��ʧ���ˣ�����2��ʾ�ɹ�ƥ�䡣
//��ôֻ�з���ֵ����1���ű�ʾ�ɹ�ƥ�䡣����Ϊ��ʧ�ܵ����Ҫ���࣬
//����Ϊ�˽��м�֦���ڵݹ麯���У���s����p����ƥ������ˣ�����״̬2��
//��s��ƥ������ˣ���p������ǰ�ַ������Ǻţ�����״̬0����s��δƥ���꣬
//p��ƥ�����ˣ�����״̬1����s����p����Ϊƥ���꣬�ҵ�ǰ�ַ��ɹ�ƥ��Ļ���
//����һ��λ�õ��õݹ顣������p����ǰ�ַ����Ǻţ���ô�������������������Ǻ�
//��Ȼ�����Ƿֱ����Ǻ�ƥ��մ���һ���ַ��������ַ���....��ֱ��ƥ��������s��
//����ÿ������ֱ���õݹ麯�����������������������ˣ�Ҳ�������õļ�֦��
//��ǰ����ֵΪ״̬0����2��ʱ�򣬷��أ��������������������ǽ�����״̬2��ʱ��ŷ��أ�
//��Ϊ������ֵΪ״̬0��ʱ���Ѿ�û�м���ѭ����ȥ�ı�Ҫ�ˣ��ǳ���Ҫ��һ����֦���μ��������£�


class Solution {
public:
	bool isMatch(string s, string p) {
		return helper(s, p, 0, 0) > 1;
	}
	int helper(string& s, string& p, int i, int j) {
		if (i == s.size() && j == p.size()) return 2;
		if (i == s.size() && p[j] != '*') return 0;
		if (j == p.size()) return 1;
		if (s[i] == p[j] || p[j] == '?') {
			return helper(s, p, i + 1, j + 1);
		}
		if (p[j] == '*') {
			if (j + 1 < p.size() && p[j + 1] == '*') {
				return helper(s, p, i, j + 1);
			}
			for (int k = 0; k <= (int)s.size() - i; ++k) {
				int res = helper(s, p, i + k, j + 1);
				if (res == 0 || res == 2) return res;
			}
		}
		return 1;
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {
		int sIndex = 0, pIndex = 0;
		int sLength = s.size();
		int pLength = p.size();
		int match = 0;//��¼����*��ʱ���Ѿ�ƥ�䵽���±�λ��
		int star = -1;//���*�ŵ�λ��
		//ɨ��s��
		while (sIndex < sLength) {
			if (pIndex < pLength && (s[sIndex] == p[pIndex] || p[pIndex] == '?')) {
				++sIndex;//�����ַ���ͬ�����ߣ���
				++pIndex;
			}
			else if (pIndex < pLength && p[pIndex] == '*') {
				star = pIndex;//����*�ţ����*�ŵ�λ��
				match = sIndex;//��¼�Ѿ�ƥ�䵽s�����±�λ��
				++pIndex;//���ȵ���ƥ����ַ���
			}
			else if (star != -1) {//�����ǵ���*�ţ�ִ�е���˵һ��û��ƥ��ɹ����˴����ٴζ�*�Ŵ���ķ������и���
				pIndex = star + 1;
				++match;//�˴�matchÿ������һ�Σ���ʾ*��ƥ����ַ�������һ������������һ�εĳ���
				sIndex = match;//����sIndexΪ*��ƥ��n���ַ�
			}
			else {
				return false;
			}
		}
		//��������*��
		while (pIndex < p.length() && p[pIndex] == '*') {
			++pIndex;
		}
		return pIndex == pLength;
	}
};
-------------------- -
���ߣ�hestyle
��Դ��CSDN
ԭ�ģ�https ://blog.csdn.net/qq_41855420/article/details/86772299 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
void T044() {
	Solution sl;
	string s, p;
	s = "abefcdgiescdfimde";
	p = "ab*cd?i*de";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;

	s = "cb";
	p = "?a";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;
	s = "adceb";
	p = "*a*b";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;
	s = "aa";
	p = "a";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;
	s = "aa";
	p = "*";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;
	s = "acdcb";
	p = "a*c?b";
	cout << s << endl << p << endl << sl.isMatch(s, p) << endl << "**********" << endl;

}