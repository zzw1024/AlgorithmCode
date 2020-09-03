#include "_000�⺯��.h"


//��������
//һ����Ϊ4��
//ÿ�����ݲ�������λ
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string>res;
		for(int a = 1; a<4;++a)
			for(int b=1;b<4;++b)
				for(int c =1;c<4;++c)
					for(int d=1;d<4;++d)
						if (a + b + c + d == s.size()) {
							int A = stoi(s.substr(0, a));//ȡ�Ӵ���תΪ����
							int B = stoi(s.substr(a, b));
							int C = stoi(s.substr(a+b, c));
							int D = stoi(s.substr(a+b+c, d));
							if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
								string str = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
								if (str.size() == (s.size() + 3))//ȥ��010�������
									res.push_back(str);
							}
						}
		return res;

	}
};


//ʹ�õݹ�
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string>res;
		helper(s, 0, "",res);
		return res;
	}
	void helper(string s, int n, string out, vector<string>&res) {
		if (n == 4) {
			if (s.empty())res.push_back(out);//ȫ�����4��IP���
		}
		else {
			for (int k = 1; k < 4; ++k) {
				if (s.size() < k)break;
				int val = stoi(s.substr(0, k));//ȡ�Ӵ�ת��Ϊ����
				if (val > 255 || k != to_string(val).size())//�����ִ���255�����010��������
					continue;
				helper(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), res);
			}
		}
	}
};


void T093() {
	Solution s;
	string str;
	vector<string>v;
	str = "11111";
	v = s.restoreIpAddresses(str);
	for (auto a : v)
		cout << a << endl;
	cout << "************************" << endl;

	str = "101010101";
	v = s.restoreIpAddresses(str);
	for (auto a : v)
		cout << a << endl;
	cout << "************************" << endl;


}