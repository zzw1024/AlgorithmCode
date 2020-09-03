#include "000�⺯��.h"

//�Խ⣻
//����� ��ͻ�ƿھ����ҵ�words��������
//Ȼ���������һһ�����Ƿ�����Ӵ�����Ҫ�Դ�ȥ�ء�������ͬ�Ӵ���ͬλ�ó��֣�����
//����ʱ������^_^�����ߣ�����һ��Сʱ
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		set<int> R;//���ԶԴ𰸽���ȥ�أ�
		vector<int>Res;
		vector<string>v;
		if (s.size() == 0)return Res;
		Permutation(v, words, 0, words.size() - 1);
		for (int i = 0; i < v.size(); ++i) {
			string sub;
			sub = v[i];
			int a = s.find(sub);
			while (a >= 0) {
				R.insert(a);
				if(a+1<s.size())
					a = s.find(sub,a+1);//�����ң���
			}			
		}
		Res.assign(R.begin(), R.end());
		return Res;

	}


	void swap(vector<string>& words, int k, int i) {
		string s;
		s = words[k];
		words[k] = words[i];
		words[i] = s;	
	}

	void Permutation(vector<string>&v, vector<string>&words,int k, int m)//ʹ�õݹ��words����ȫ����
	{
		if (k == m)
		{
			static int num = 1;  //�ֲ���̬����������ͳ��ȫ���еĸ���
			string s = "";
			for (int i = 0; i < words.size(); ++i)
				s += words[i];
			v.push_back(s);
			cout << "��" << num++ << "������Ϊ�� " << v[v.size() - 1] << endl;
		}
		else
		{
			for (int i = k; i <= m; i++)
			{
				swap(words, k,i);
				Permutation(v,words,k+1, m);
				swap(words, k, i);
			}
		}
	}


};

//���ʹ�
//�����������Ҫ�õ�������ϣ����һ����ϣ���Ȱ����еĵ��ʴ��ȥ��
//Ȼ��ӿ�ͷ��ʼһ����������ֹͣ����Ϊ��ʣ���ַ�����С�ڵ��ʼ��������ַ��ĳ��ȡ�
//��ʱ��������Ҫ����ڶ�����ϣ��Ȼ��ÿ���ҳ��������ʳ��ȵ��Ӵ��������Ƿ��ڵ�һ����ϣ���
//���û�У���break������У������ڶ�����ϣ������ͬ�Ĵ�ֻ�ܳ���һ�Σ�������ˣ�Ҳbreak��
//�������ƥ����������ʼ������еĵ��ʣ����i�������У�����μ��������£�
//400ms
 
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s.empty() || words.empty()) return res;
		int n = words.size(), m = words[0].size();
		unordered_map<string, int> m1;
		for (auto &a : words) ++m1[a];//�����ʴ����ϣ����
		for (int i = 0; i <= (int)s.size() - n * m; ++i) {//��������ѭ������
			unordered_map<string, int> m2;
			int j = 0;
			for (j = 0; j < n; ++j) {
				string t = s.substr(i + j * m, m);//��s��0λ��ʼ����ȡһ�����ʳ��ȵ��Ӵ�
				if (m1.find(t) == m1.end()) break;//δ�ҵ�
				++m2[t];//
				if (m2[t] > m1[t]) break;
			}
			if (j == n) res.push_back(i);
		}
		return res;
	}
};

//����⻹��һ��O(n)ʱ�临�ӶȵĽⷨ�����˼·�ǳ�������Ǹо����������������Ŀ�⻹δ��������ˮƽ��
//���ַ���������һ���ַ�һ���ַ��ı���������һ����һ���ʵı��������������Ŀ�е����ӣ��ַ���s�ĳ���nΪ18��
//words����������������(cnt = 2)��ÿ�����ʵĳ���len��Ϊ3����ô������˳��Ϊ0��3��6��8��12��15��
//Ȼ��ƫ��һ���ַ�1��4��7��9��13��16��Ȼ����ƫ��һ���ַ�2��5��8��10��14��17�������Ϳ��԰������������������
//���ǻ�������һ����ϣ��m1����¼words������дʣ�Ȼ�����Ǵ�0��ʼ��������left����¼��߽��λ�ã�
//count��ʾ��ǰ�Ѿ�ƥ��ĵ��ʵĸ�����Ȼ������һ������һ�����ʵı����������ǰ�����ĵ��ĵ���t��m1�д��ڣ�
//��ô���ǽ��������һ����ϣ��m2�У������m2�и���С�ڵ���m1�еĸ�������ô����count����1����������ˣ�
//��ô��Ҫ��һЩ�������������������, s = barfoofoo, words = { bar, foo, abc }, ���Ǹ�words���¼���һ��abc��
//Ŀ����Ϊ�˱�����barfoo����ֹͣ����ô���������ڶ�foo��ʱ��, m2[foo] = 2, ����ʱm1[foo] = 1�����Ǻ��Ѿ��������ˣ�
//��������Ҫ�ƶ���߽�left��λ�ã������Ȱѵ�һ����t1 = barȡ������Ȼ��m2[t1]�Լ�1�������ʱm2[t1] < m1[t1]�ˣ�
//˵��һ��ƥ��û�ˣ���ô��Ӧ��countҲҪ�Լ�1��Ȼ����߽���ϸ�len�������Ϳ����ˡ����ĳ��ʱ��count��cnt����ˣ�
//˵�����ǳɹ�ƥ����һ��λ�ã���ô����ǰ��߽�left������res�У���ʱȥ������ߵ�һ���ʣ�ͬʱcount�Լ�1��
//��߽�����len������ƥ�䡣�������ƥ�䵽һ������m1�еĴʣ���ô˵����ǰ���Ѿ��Ͽ��ˣ���������m2��countΪ0��
//��߽�left�Ƶ�j + len���μ��������£�


//�˽ⷨţ�ƣ�80ms

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (s.empty() || words.empty()) return {};
		vector<int> res;
		int n = s.size(), cnt = words.size(), len = words[0].size();
		unordered_map<string, int> m1;
		for (string w : words) ++m1[w];
		for (int i = 0; i < len; ++i) {//�ܹ�һ�����ʵĳ���
			int left = i, count = 0;//count
			unordered_map<string, int> m2;
			for (int j = i; j <= n - len; j += len) {//��Ϊn/len����λ���бȽ�
				string t = s.substr(j, len);
				if (m1.count(t)) {
					++m2[t];
					if (m2[t] <= m1[t]) {
						++count;
					}
					else {
						while (m2[t] > m1[t]) {
							string t1 = s.substr(left, len);
							--m2[t1];
							if (m2[t1] < m1[t1]) --count;
							left += len;
						}
					}
					if (count == cnt) {//�������ڵ��ʸ�����˵��ƥ��ɹ�
						res.push_back(left);
						--m2[s.substr(left, len)];
						--count;
						left += len;
					}
				}
				else {
					m2.clear();
					count = 0;
					left = j + len;
				}
			}
		}
		return res;
	}
};

void T030() {
	string s = "foobarfoobar";
	vector<string> words = { "foo", "bar" };
	vector<int>Res;
	Solution sol;
	Res = sol.findSubstring(s, words);
	for (auto i : Res)
		cout << i << endl;
	   
}