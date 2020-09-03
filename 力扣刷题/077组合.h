#include "_000�⺯��.h"


//���������������
//�����ǰ�˳��ѡ���о��ܼ�
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n || n < 1 || k < 1)return{};
		vector<vector<int>>res;
		vector<int>Num;
		for (int i = 0; i < n; ++i)Num.push_back(i + 1);
		vector<bool>Index(k, 1);//����λǰ����Ϊѡ��״̬
		Index.insert(Index.end(), n - k, 0);//����� ����δ��ѡ��
		res.push_back(Print(Index, Num));//��������

		while (!hasDone(Index, n, k))
		{
			//������ɨ������
			for (int i = 0; i < n - 1; i++)
			{
				//�ҵ���һ����10����Ͻ�����"01"���
				if (Index[i] && !Index[i + 1])
				{
					Index[i] = false;
					Index[i + 1] = true;

					//��"01"�����ߵ�1�Ƶ������
					int count = 0;
					for (int j = 0; j < i; j++)
					{
						if (Index[j])
						{
							Index[j] = false;
							Index[count++] = true;
						}
					}
					res.push_back(Print(Index, Num));//��������
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

	//������k��λ���Ƿ���ȫ���0
	bool hasDone(vector<bool>index, int n, int k)
	{
		for (int i = n - 1; i >= n - k; i--)
			if (!index[i]) return false;
		return true;
	}
};


//ʹ�������������
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

//����������һ�ֵݹ��д�����˽ⷨû��helper���ݹ麯����
//���ǰѱ���͵����˵ݹ麯����д����ʮ�ֵļ�࣬Ҳ�Ƿǳ���Ȥ��һ�ֽⷨ��
//����ⷨ�õ���һ����Ҫ������ C(n, k) = C(n - 1, k - 1) + C(n - 1, k)��
//��Ӧ�������Ǹ���ʱ��ѧ������ϵ�ʱ��ѧ���ɣ�����Ҳ�ǲ����ˡ�
//��֮������һ�¾��ǣ���n������ȡk����������������
//������n - 1������ȡk - 1���������������ټ�����n - 1������ȡk��������������֮�͡�
//���ﲩ���Ͳ�֤���ˣ���Ϊ��Ҳ���ᣬ��ֱ�Ӿ���Ŀ�е�������˵���ɣ�
//C(4, 2) = C(3, 1) + C(3, 2)
//���ǲ���д�� C(3, 1) �����������[1], [2], [3]��
//���� C(3, 2) �����������[1, 2], [1, 3], [2, 3]��
//���Ƿ��ֶ��߼�����Ϊ6�������� C(4, 2) �ĸ���֮�͡�
//����������ϸ���ᷢ�֣�C(3, 2)��������������� C(4, 2) ֮�У�
//���� C(3, 1) ��ÿ�����ֻ��һ�����֣���������Ҫ�Ľ��k = 2��
//��ʵ�ܺð죬ÿ��������涼����4�����Ǳ���ˣ�[1, 4], [2, 4], [3, 4]��
//����C(3, 2) �����������[1, 2], [1, 3], [2, 3]�����þ͵õ��� n = 4, k = 2 ����������ˡ�
//�μ��������£�

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