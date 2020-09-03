#include "000库函数.h"

//用stringAPI
class Solution {
public:
	int lengthOfLastWord(string s) {
		int i = s.rfind(' ');//查找空格
		if(i==-1)return s.size();//无空格，整个字符串即为一个单词，包括空字符
		if (i == s.size() - 1) {//最后为空格，再向前找空格
			s.erase(i, 1);//删除最后一个空格再去找
			return lengthOfLastWord(s);
		}
		return s.size() - i - 1;
	}
};

//不该用递归，会加长时间和空间
//给一个空格标志就行
//好吧，比上面的时间复杂度高，但空间复杂度小
class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (i > 0 && s[i] != ' '&&s[i - 1] == ' ')
				len = 0;//遇到下一个单词，重新计算
			if (s[i] != ' ')
				len++;//计算该单词的长度
		}
		return len;//返回的记录即使最后一个单词长度
	}
};



//我们关心的主要是非空格的字符，那么我们实际上在遍历字符串的时候，
//如果遇到非空格的字符，我们只需要判断其前面一个位置的字符是否为空格，
//如果是的话，那么当前肯定是一个新词的开始，将计数器重置为1，如果不是的话，
//说明正在统计一个词的长度，计数器自增1即可。但是需要注意的是，当i = 0的时候，
//无法访问前一个字符，所以这种情况要特别判断一下，归为计数器自增1那类。参见代码如下：


class Solution {
public:
	int lengthOfLastWord(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != ' ') {
				if (i != 0 && s[i - 1] == ' ') res = 1;
				else ++res;
			}
		}
		return res;
	}
};



//由于我们只关于最后一个单词的长度，所以开头有多少个空格起始我们并不在意，
//我们从字符串末尾开始，先将末尾的空格都去掉，然后开始找非空格的字符的长度即可，参见代码如下：



class Solution {
public:
	int lengthOfLastWord(string s) {
		int right = s.size() - 1, res = 0;
		while (right >= 0 && s[right] == ' ') --right;
		while (right >= 0 && s[right] != ' ') {
			--right;
			++res;
		}
		return res;
	}
};


void T058() {
	Solution sv;
	string s;
	s = "";
	cout << s << endl << sv.lengthOfLastWord(s) << endl;
	s = " ";
	cout << s << endl << sv.lengthOfLastWord(s) << endl;
	s = " asdff afd ";
	cout << s << endl << sv.lengthOfLastWord(s) << endl;
	s = "asd asdfa asdafsgasagsds";
	cout << s << endl << sv.lengthOfLastWord(s) << endl;
}