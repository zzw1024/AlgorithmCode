#include "_000库函数.h"

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string>res;
		vector<string>lin;//一行单词的存放量
		int n = 0;//一行字符的长度
		for (int i = 0; i < words.size(); ++i) {
			n += words[i].size();//单词长度
			lin.push_back(words[i]);
			if (n + lin.size() - 1 > maxWidth) {//长度超过了lin.size() - 1为需要加空格的长度
				n -= words[i].size();
				lin.pop_back();//最后一个单词放不进去
				string str = "";
				int num = (lin.size() - 1) > 0 ? (lin.size() - 1) : (maxWidth - n + 1);//用来防止只有一个单词的情况
				int k = (maxWidth - n) % num;//如果无法均分，则左边的空格要更多
				for (int j = 0; j < lin.size(); ++j) {
					str += lin[j];
					if (lin.size() == 1) {//只有一个单词
						str.insert(str.end(), k, ' ');
						break;
					}
					if (k - j > 0)str += " ";//左边的多加空格
					if (j < lin.size() - 1)
						str.insert(str.end(), (maxWidth - n) / num, ' ');
				}
				res.push_back(str);
				--i;
				n = 0;
				lin.clear();
			}
		}
		if (!lin.empty()) {//最后一点单词了
			string str = "";
			for (int j = 0; j < lin.size(); ++j) {
				str += lin[j];
				if (j < lin.size() - 1)
					str += " ";//最后一行为左对齐，单词间只需要添加一个空格就行
			}
			str.insert(str.end(), (maxWidth - n - lin.size() + 1), ' ');//最后拿剩余的空格顶替
			res.push_back(str);
		}
		return res;
	}
};


//方法二，更简洁，但跟方法一的思想一样
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