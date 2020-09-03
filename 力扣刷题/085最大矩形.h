#include "_000�⺯��.h"


//��Ȼͨ���ˣ��һ���Ϊ�����
//ʹ�����Ͻ�ָ������½�ָ����ɾ�������ϽǺ����½�
//["1",     "0",    "1",    "0",   "0"],
//
//["1",     "0",    "1",    "1",   "1"],
//                   start->             //���ϽǴ�ÿ������d�˿�ʼ����
//["1",     "1",    "1",    "1",   "1"],
//                   end->               //���½Ǵ�start ���п�ʼÿ�б���
//["1",     "0",    "0",    "1",   "0"]
//Ϊ�˱��⽫0����ȥ����minPot��¼��start�����0�У����Ҳ಻���ٱ���

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int res = 0;
		for (int i = 0; i < matrix.size(); ++i) {//���ϽǱ�������
			for (int start = 0; start < matrix[0].size(); ++start) {//���ϽǴ�ÿ�е�����˿�ʼ����
				if (matrix[i][start] == '0')continue;
				int minRight = matrix[0].size();//��¼���½ǵ�λ�ã���ֹ����0������ȥ
				for (int j = i; j < matrix.size(); ++j) {//�����½ǵı�����
					for (int end = start; end < minRight; ++end) {//���½Ǵ����Ͻǵ��п�ʼ����
						if (matrix[j][end] == '0') {
							minRight = minRight > end ? end : minRight;
							break;
						}
						res = res > ((end - start + 1)*(j - i + 1)) ? res : ((end - start + 1)*(j - i + 1));
					}
				}
			}
		}
		return res;
	}
};

//�����Ķ�ά����ÿһ�����϶����Կ���һ��ֱ��ͼ����������ж����У��Ϳ����γɶ��ٸ�ֱ��ͼ
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int res = 0, m = matrix.size(), n = matrix[0].size();
		vector<int> height(n + 1, 0);
		for (int i = 0; i < m; ++i) {
			stack<int> s;
			for (int j = 0; j < n + 1; ++j) {
				if (j < n) {
					height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
				}
				while (!s.empty() && height[s.top()] >= height[j]) {
					int cur = s.top(); s.pop();
					res = max(res, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
				}
				s.push(j);
			}
		}
		return res;
	}
};

//�������ַ�����˼·�����height���������һ����
//�����left�����ʾ��߽���1��λ�ã�right�����ʾ�ұ߽���1��λ�ã�
//��ô��������һ�еĵ�j��λ�ã�����Ϊ(right[j] - left[j]) * height[j]��
//���Ǿٸ�������˵���������������Ϊ��
//[
//	[1, 1, 0, 0, 1],
//	[0, 1, 0, 0, 1],
//	[0, 0, 1, 1, 1],
//	[0, 0, 1, 1, 1],
//	[0, 0, 0, 0, 1]
//]
//��0�У�
//
//h : 1 1 0 0 1
//	l : 0 0 0 0 4
//	r : 2 2 5 5 5
//
//
//	��1�У�
//
//	h : 1 1 0 0 1
//	l : 0 0 0 0 4
//	r : 2 2 5 5 5
//
//
//	��2�У�
//
//	h : 0 0 1 1 3
//	l : 0 0 2 2 4
//	r : 5 5 5 5 5
//
//
//	��3�У�
//
//	h : 0 0 2 2 4
//	l : 0 0 2 2 4
//	r : 5 5 5 5 5
//
//
//	��4�У�
//
//	h : 0 0 0 0 5
//	l : 0 0 0 0 4
//	r : 5 5 5 5 5

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int res = 0, m = matrix.size(), n = matrix[0].size();
		vector<int> height(n, 0), left(n, 0), right(n, n);
		for (int i = 0; i < m; ++i) {
			int cur_left = 0, cur_right = n;
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1') {
					++height[j];
					left[j] = max(left[j], cur_left);
				}
				else {
					height[j] = 0;
					left[j] = 0;
					cur_left = j + 1;
				}
			}
			for (int j = n - 1; j >= 0; --j) {
				if (matrix[i][j] == '1') {
					right[j] = min(right[j], cur_right);
				}
				else {
					right[j] = n;
					cur_right = j;
				}
				res = max(res, (right[j] - left[j]) * height[j]);
			}
		}
		return res;
	}
};

void T085() {
	Solution s;
	vector<vector<char>>v;
	v = {
	  {'1','0','1','0','0'},
	  {'1','0','1','1','1'},
	  {'1','1','1','1','1'},
	  {'1','0','0','1','0'}
	};
	cout << s.maximalRectangle(v) << endl;

}