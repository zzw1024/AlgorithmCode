#include "000�⺯��.h"




//ʹ�û��ݷ�����������������������������������Է���������
void recall(vector<string>&bracket, string s, int left, int right) {//bracketʹ�����ã�ȷ����仯�ᱻ����
	if (left > right)return;
	if (left == 0 && right == 0)bracket.push_back(s);
	else {
		if (left > 0)recall(bracket, s + '(', left-1, right);
		if (right > 0)recall(bracket, s + ')', left, right-1);
	}
	
}

vector<string> generateParenthesis(int n) {
	vector<string>bracket;
	if (n < 1)return bracket;
	recall(bracket, "",n, n);
	return bracket;
		
}

ÿ�ҵ�һ�������ţ�����������һ�����������ţ�������ڿ�ͷ��һ��()�����γ������е������
��Ҫע����ǣ���ʱ�������ظ������������������set���ݽṹ���ô�����������ظ��������뵽�����
��������ٰ�setתΪvector����

vector<string> generateParenthesis(int n) {
	set<string>t;
	if (n == 0)t.insert("");
	else {
		vector<string>pre = generateParenthesis(n - 1);
		for (auto a : pre) {
			for (int i = 0; i < a.size(); ++i) {
				if (a[i] == '(') {
					a.insert(a.begin() + i + 1, '(');
					a.insert(a.begin() + i + 2, '��');
					t.insert(a);
					a.erase(a.begin() + i + 1, a.begin() + i + 3);
				}
			}
			t.insert("()" + a);
		}
		
	}
	return vector<string>(t.begin(), t.end());//ǿ������ת��

}


void T022() {
	vector<string>Res;
	Res = generateParenthesis(3);
	for (int i = 0; i < Res.size(); ++i)
		cout << Res[i] << endl;

}
