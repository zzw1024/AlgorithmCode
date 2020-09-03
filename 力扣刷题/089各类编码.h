#include"_000库函数.h"

//使用二进制转格雷码
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int>res;
		for (int i = 0; i < pow(2, n); ++i) {//pow(2,n)种情况
			res.push_back((i >> 1) ^ i);//二进制转格雷码
		}
		return res;
	}
};

//镜面排列
// Mirror arrangement
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res{ 0 };
		for (int i = 0; i < n; ++i) {
			int size = res.size();
			for (int j = size - 1; j >= 0; --j) {
				res.push_back(res[j] | (1 << i));
			}
		}
		return res;
	}
};
//维基百科上还有一条格雷码的性质是直接排列，
//以二进制为0值的格雷码为第零项，第一项改变最右边的位元，
//第二项改变右起第一个为1的位元的左边位元，第三、四项方法同第一、二项，
//如此反复，即可排列出n个位元的格雷码。根据这条性质也可以写出代码，不过相比前面的略微复杂，
//代码如下：

// Direct arrangement 
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res{ 0 };
		int len = pow(2, n);
		for (int i = 1; i < len; ++i) {
			int pre = res.back();
			if (i % 2 == 1) {
				pre = (pre & (len - 2)) | ((~pre) & 1);
			}
			else {
				int cnt = 1, t = pre;
				while ((t & 1) != 1) {
					++cnt;
					t >>= 1;
				}
				if ((pre & (1 << cnt)) == 0) pre |= (1 << cnt);
				else pre &= ~(1 << cnt);
			}
			res.push_back(pre);
		}
		return res;
	}
};


//使用最笨的方法
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res{ 0 };
		unordered_set<int> s;
		stack<int> st;
		st.push(0);
		s.insert(0);
		while (!st.empty()) {
			int t = st.top(); st.pop();
			for (int i = 0; i < n; ++i) {
				int k = t;
				if ((k & (1 << i)) == 0) k |= (1 << i);
				else k &= ~(1 << i);
				if (s.count(k)) continue;
				s.insert(k);
				st.push(k);
				res.push_back(k);
				break;
			}
		}
		return res;
	}
};