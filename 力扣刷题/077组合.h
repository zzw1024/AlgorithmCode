#include "_000库函数.h"


//就是排列组合问题
//但是是按顺序选，感觉很简单
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n || n < 1 || k < 1)return{};
		vector<vector<int>>res;
		vector<int>Num;
		for (int i = 0; i < n; ++i)Num.push_back(i + 1);
		vector<bool>Index(k, 1);//令标记位前三个为选中状态
		Index.insert(Index.end(), n - k, 0);//后面的 数字未被选中
		res.push_back(Print(Index, Num));//保存数据

		while (!hasDone(Index, n, k))
		{
			//从左到右扫描数组
			for (int i = 0; i < n - 1; i++)
			{
				//找到第一个“10”组合将其变成"01"组合
				if (Index[i] && !Index[i + 1])
				{
					Index[i] = false;
					Index[i + 1] = true;

					//将"01"组合左边的1移到最左边
					int count = 0;
					for (int j = 0; j < i; j++)
					{
						if (Index[j])
						{
							Index[j] = false;
							Index[count++] = true;
						}
					}
					res.push_back(Print(Index, Num));//保存数据
					break;
				}
			}
		}
		return res;
	}
	vector<int> Print(vector<bool>Index, vector<int>Num) {
		vector<int>v;
		for (int i = 0; i < Index.size(); ++i)
			if (Index[i])v.push_back(Num[i]);
		return v;
	}

	//检查最后k个位置是否已全变成0
	bool hasDone(vector<bool>index, int n, int k)
	{
		for (int i = n - 1; i >= n - k; i--)
			if (!index[i]) return false;
		return true;
	}
};


//使用深度搜索策略
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n || n < 1 || k < 1)return{};
		vector<vector<int>>res;
		vector<int>v;
		helper(n, k, 1, v, res);
		return res;
	}

	void helper(int n, int k, int level, vector<int>&v, vector<vector<int>>&res) {
		if (v.size() == k) {
			res.push_back(v);
			return;
		}
		for (int i = level; i <= n; ++i) {
			v.push_back(i);
			helper(n, k, i + 1, v, res);
			v.pop_back();
		}
	}
};

//我们再来看一种递归的写法，此解法没用helper当递归函数，
//而是把本身就当作了递归函数，写起来十分的简洁，也是非常有趣的一种解法。
//这个解法用到了一个重要的性质 C(n, k) = C(n - 1, k - 1) + C(n - 1, k)，
//这应该在我们高中时候学排列组合的时候学过吧，博主也记不清了。
//总之，翻译一下就是，在n个数中取k个数的组合项个数，
//等于在n - 1个数中取k - 1个数的组合项个数再加上在n - 1个数中取k个数的组合项个数之和。
//这里博主就不证明了，因为我也不会，就直接举题目中的例子来说明吧：
//C(4, 2) = C(3, 1) + C(3, 2)
//我们不难写出 C(3, 1) 的所有情况：[1], [2], [3]，
//还有 C(3, 2) 的所有情况：[1, 2], [1, 3], [2, 3]。
//我们发现二者加起来为6，正好是 C(4, 2) 的个数之和。
//但是我们仔细看会发现，C(3, 2)的所有情况包含在 C(4, 2) 之中，
//但是 C(3, 1) 的每种情况只有一个数字，而我们需要的结果k = 2，
//其实很好办，每种情况后面都加上4，于是变成了：[1, 4], [2, 4], [3, 4]，
//加上C(3, 2) 的所有情况：[1, 2], [1, 3], [2, 3]，正好就得到了 n = 4, k = 2 的所有情况了。
//参见代码如下：

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n || k < 0)return{};
		if (k == 0)return { {} };
		vector<vector<int>>res = combine(n - 1, k - 1);
		for (auto &a : res)a.push_back(n);
		for (auto &a : combine(n - 1, k))res.push_back(a);
		return res;
	}
};



void T077() {
	Solution s;
	vector<vector<int>>v;
	v = s.combine(4, 2);
	for (auto a : v) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
}