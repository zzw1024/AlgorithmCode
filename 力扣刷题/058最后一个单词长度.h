#include "000�⺯��.h"

//��stringAPI
class Solution {
public:
	int lengthOfLastWord(string s) {
		int i = s.rfind(' ');//���ҿո�
		if(i==-1)return s.size();//�޿ո������ַ�����Ϊһ�����ʣ��������ַ�
		if (i == s.size() - 1) {//���Ϊ�ո�����ǰ�ҿո�
			s.erase(i, 1);//ɾ�����һ���ո���ȥ��
			return lengthOfLastWord(s);
		}
		return s.size() - i - 1;
	}
};

//�����õݹ飬��ӳ�ʱ��Ϳռ�
//��һ���ո��־����
//�ðɣ��������ʱ�临�Ӷȸߣ����ռ临�Ӷ�С
class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (i > 0 && s[i] != ' '&&s[i - 1] == ' ')
				len = 0;//������һ�����ʣ����¼���
			if (s[i] != ' ')
				len++;//����õ��ʵĳ���
		}
		return len;//���صļ�¼��ʹ���һ�����ʳ���
	}
};



//���ǹ��ĵ���Ҫ�Ƿǿո���ַ�����ô����ʵ�����ڱ����ַ�����ʱ��
//��������ǿո���ַ�������ֻ��Ҫ�ж���ǰ��һ��λ�õ��ַ��Ƿ�Ϊ�ո�
//����ǵĻ�����ô��ǰ�϶���һ���´ʵĿ�ʼ��������������Ϊ1��������ǵĻ���
//˵������ͳ��һ���ʵĳ��ȣ�����������1���ɡ�������Ҫע����ǣ���i = 0��ʱ��
//�޷�����ǰһ���ַ��������������Ҫ�ر��ж�һ�£���Ϊ����������1���ࡣ�μ��������£�


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



//��������ֻ�������һ�����ʵĳ��ȣ����Կ�ͷ�ж��ٸ��ո���ʼ���ǲ������⣬
//���Ǵ��ַ���ĩβ��ʼ���Ƚ�ĩβ�Ŀո�ȥ����Ȼ��ʼ�ҷǿո���ַ��ĳ��ȼ��ɣ��μ��������£�



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