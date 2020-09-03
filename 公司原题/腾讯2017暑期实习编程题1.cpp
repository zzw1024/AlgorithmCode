#if 0
#include<iostream>
#include <string>
#include <algorithm>

using namespace std;


//����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
//�����Ҫɾ�����ַ�������
//
//�������� :
//
//���������ж��飬ÿ�����һ���ַ���s���ұ�֤:1 <= s.length <= 1000.
//
//
//
//������� :
//
//����ÿ�����ݣ����һ������������������Ҫɾ�����ַ�������
//ʾ��1
//����
//abcda
//google
//���
//2
//2
//
//
//������Ҫ��ɾ�������������ַ������ʿ���ʹ�ö�̬�滮�����Ĺ��������ַ�������Ҫ������

const int MAX = 1001;
int MaxLen[MAX][MAX]; //����������У���̬�滮��
int maxLen(string s1, string s2) {
	int length1 = s1.size();
	int length2 = s2.size();
	for (int i = 0; i < length1; ++i)
		MaxLen[i][0] = 0;
	for (int i = 0; i < length2; ++i)
		MaxLen[0][i] = 0;

	for (int i = 1; i <= length1; ++i)
	{
		for (int j = 1; j <= length2; ++j)
		{
			if (s1[i - 1] == s2[j - 1]) {
				MaxLen[i][j] = MaxLen[i - 1][j - 1] + 1;
			}
			else
			{
				MaxLen[i][j] = max(MaxLen[i - 1][j], MaxLen[i][j - 1]);
			}
		}
	}

	return MaxLen[length1][length2];
}

int main() {
	string s;
	while (cin >> s) {
		int length = s.size();
		if (length == 1) {
			cout << 1 << endl;
			continue;
		}
		//���û��Ĵ����ص�
		string s2 = s;
		reverse(s2.begin(), s2.end());
		int max_length = maxLen(s, s2);
		cout << length - max_length << endl;
	}
	return 0;
}



#endif