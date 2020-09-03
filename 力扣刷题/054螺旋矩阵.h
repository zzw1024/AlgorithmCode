#include "_000�⺯��.h"


//���Ƕ���p��qΪ��ǰ���ĸ߶ȺͿ�ȣ���p����qΪ1ʱ��
//��ʾ���һ����ֻ��һ�л���һ�У���������ѭ����
//������ѵ������±��ת���������ȷ��ת���±��ǽ����Ĺؼ���
//���ǿ��Զ����������3x3������������±����д���������£�
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int>res;
		if (matrix.empty() || matrix[0].empty())return res;
		int m = matrix.size(), n = matrix[0].size();
		int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
		int p = m, q = n;
		for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
			for (int col = i; col < i + q; ++col)//����ɨ��
				res.push_back(matrix[i][col]);
			for (int row = i + 1; row < i + p; ++row)//����ɨ��
				res.push_back(matrix[row][i + q - 1]);
			if (p == 1 || q == 1)break;
			for (int col = i + q - 2; col >= i; --col)//����ɨ��
				res.push_back(matrix[i + p - 1][col]);
			for (int row = i + p - 2; row > i; --row)//����ɨ��
				res.push_back(matrix[row][i]);
		}
		return res;
	}
};
	
//�����������������ķ�������Ҫ����Ҫȷ���������������ߵ�λ�ã�
//��ô��ʼ����ʱ���ϱ�up����0���±�down����m - 1�����left��0���ұ�right��n - 1��
//Ȼ�����ǽ���whileѭ�����ȱ����ϱߣ�������Ԫ�ؼ�����res��Ȼ���ϱ�����һλ��
//�����ʱ�ϱߴ����±ߣ�˵����ʱ�Ѿ���������ˣ�ֱ��break��ͬ������±ߣ���ߣ��ұߣ�
//���ν������Ӧ�Ĳ����������ͻ�ʹ��������й��ɣ����Ҳ��׳����μ��������£�

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int>res;
		if (matrix.empty() || matrix[1].empty())return res;
		int m = matrix.size(), n = matrix[0].size();
		int up = 0, down = m - 1, left = 0, right = n - 1;
		while (1) {
			for (int j = left; j <= right; ++j)res.push_back(matrix[up][j]);
			if (++up > down)break;
			for (int i = up; i <= down; ++i)res.push_back(matrix[i][right]);
			if (--right < left)break;
			for (int j = right; j >= left; --j)res.push_back(matrix[down][j]);
			if (--down < up)break;
			for (int i = down; i >= up; --i)res.push_back(matrix[i][left]);
			if (++left > right)break;
		}
		return res;
	}	
};



void T054() {
	Solution s;
	vector<int>v;
	vector<vector<int>>m;
	m = { {1,2,3},{4,5,6},{7,8,9} };
	v = s.spiralOrder(m);
	for (auto a : v)
		cout << a << "  ";
	cout << endl;
	m = { {1} };
	v = s.spiralOrder(m);
	for (auto a : v)
		cout << a << "  ";
	cout << endl;
	
}