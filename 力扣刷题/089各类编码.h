#include"_000�⺯��.h"

//ʹ�ö�����ת������
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int>res;
		for (int i = 0; i < pow(2, n); ++i) {//pow(2,n)�����
			res.push_back((i >> 1) ^ i);//������ת������
		}
		return res;
	}
};

//��������
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
//ά���ٿ��ϻ���һ���������������ֱ�����У�
//�Զ�����Ϊ0ֵ�ĸ�����Ϊ�������һ��ı����ұߵ�λԪ��
//�ڶ���ı������һ��Ϊ1��λԪ�����λԪ�������������ͬ��һ�����
//��˷������������г�n��λԪ�ĸ����롣������������Ҳ����д�����룬�������ǰ�����΢���ӣ�
//�������£�

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


//ʹ����ķ���
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