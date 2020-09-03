#include "_000�⺯��.h"

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string>res;
		vector<string>lin;//һ�е��ʵĴ����
		int n = 0;//һ���ַ��ĳ���
		for (int i = 0; i < words.size(); ++i) {
			n += words[i].size();//���ʳ���
			lin.push_back(words[i]);
			if (n + lin.size() - 1 > maxWidth) {//���ȳ�����lin.size() - 1Ϊ��Ҫ�ӿո�ĳ���
				n -= words[i].size();
				lin.pop_back();//���һ�����ʷŲ���ȥ
				string str = "";
				int num = (lin.size() - 1) > 0 ? (lin.size() - 1) : (maxWidth - n + 1);//������ֹֻ��һ�����ʵ����
				int k = (maxWidth - n) % num;//����޷����֣�����ߵĿո�Ҫ����
				for (int j = 0; j < lin.size(); ++j) {
					str += lin[j];
					if (lin.size() == 1) {//ֻ��һ������
						str.insert(str.end(), k, ' ');
						break;
					}
					if (k - j > 0)str += " ";//��ߵĶ�ӿո�
					if (j < lin.size() - 1)
						str.insert(str.end(), (maxWidth - n) / num, ' ');
				}
				res.push_back(str);
				--i;
				n = 0;
				lin.clear();
			}
		}
		if (!lin.empty()) {//���һ�㵥����
			string str = "";
			for (int j = 0; j < lin.size(); ++j) {
				str += lin[j];
				if (j < lin.size() - 1)
					str += " ";//���һ��Ϊ����룬���ʼ�ֻ��Ҫ���һ���ո����
			}
			str.insert(str.end(), (maxWidth - n - lin.size() + 1), ' ');//�����ʣ��Ŀո���
			res.push_back(str);
		}
		return res;
	}
};


//������������࣬��������һ��˼��һ��
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> res;
		int i = 0;
		while (i < words.size()) {
			int j = i, len = 0;
			while (j < words.size() && len + words[j].size() + j - i <= L) {
				len += words[j++].size();
			}
			string out;
			int space = L - len;
			for (int k = i; k < j; ++k) {
				out += words[k];
				if (space > 0) {
					int tmp;
					if (j == words.size()) {
						if (j - k == 1) tmp = space;
						else tmp = 1;
					}
					else {
						if (j - k - 1 > 0) {
							if (space % (j - k - 1) == 0) tmp = space / (j - k - 1);
							else tmp = space / (j - k - 1) + 1;
						}
						else tmp = space;
					}
					out.append(tmp, ' ');
					space -= tmp;
				}
			}
			res.push_back(out);
			i = j;
		}
		return res;
	}
};

void T068() {
	Solution s;
	vector<string>v;
	v = { "aaaaaa","bbbbbb","This", "is", "an", "example", "of", "text", "justification." };
	v = s.fullJustify(v, 16);
	for (auto a : v)
		cout << a << endl;
	cout << endl;
	v = { "What","must","be","acknowledgment","shall","be"};
	v = s.fullJustify(v, 16);
	for (auto a : v)
		cout << a << endl;
	cout << endl;
	v = { "Science","is","what","we","understand","well","enough","to","explain",
		 "to","a","computer.","Art","is","everything","else","we","do" };
	v = s.fullJustify(v, 20);
	for (auto a : v)
		cout << a << endl;
	cout << endl;

}