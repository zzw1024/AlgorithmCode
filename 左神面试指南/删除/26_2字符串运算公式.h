#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;


//����Ŀ��
//	����һ���ַ���str��str��ʾһ����ʽ����ʽ��������������Ӽ��˳����ź�
//	�������ţ����ع�ʽ�ļ�������
//	��������
//	str = "48*((70-65)-43)+8*1"������ - 1816��
//	str = "3+1*4"������7��
//	str = "3+(1*4)"������7��
//	��˵����
//	1��������Ϊ�������ַ���һ������ȷ�Ĺ�ʽ��������Ҫ��str����ʽ��Ч�Լ�
//	�顣
//	2������Ǹ���������Ҫ������������������"4*(-3)"�������������Ϊ��ʽ��
//	��ͷ�����Ų��ֵĿ�ͷ�������û�����ţ�����"-3*4"��"(-3��*4"���ǺϷ��ġ�
//	3�����ÿ��Ǽ�������лᷢ����������
//	
//�����⡿
//	һ����ʹ��ջ����Ϊջ������������ܺ�
//	1��û�����Ŵ���
//	ʹ��ջ��
//	����ʹ��ջ���ַ���str���зֽ�
//	���������֣������ݿ�ʼ�����������������������������ݽ������ַ���ʼ
//	Ȼ��������ݺ��������ջ����ջ��Ϊ��*���� / ��ʱ����ջ���������������� �Ǹ������ó�����Ŀǰ�����ݽ������㣬Ȼ��õ��Ľ��ѹ��ջ�С�
//	Ȼ���ַ�������ѹ����ϣ�Ȼ�����δ�ջ�����������Լ���������������㼴��
//	2����������
//	���庯��fun(str, index)
//	��ʾ�����index��ʼ���ַ������ݣ�֪�����������Ż����ַ���β������
//	��fun��ʵ�ֵľ���һ���򵥵������ڲ������ŵ��������



//ʹ�õ�������
class calEquation
{
public:
	int cal(const string str)//����
	{
		if (str.length() == 0)
			return 0;
		return calFunc(str, 0)[0];
	}

private:
	vector<int> calFunc(const string str, int index)
	{
		stack<string>data;
		int num = 0;
		vector<int>v;
		while (index < str.length() && str[index] != ')')
		{
			if (str[index] >= '0'&&str[index] <= '9')
				num = num * 10 + str[index++] - '0';
			else if (str[index] != '(')
			{
				addNum(data, num);
				string sybol = "";
				sybol = str[index++];
				data.push(sybol);//�������������
				num = 0;
			}
			else//��������
			{
				v = calFunc(str, index + 1);
				num = v[0];
				index = v[1] + 1;
			}
		}
		addNum(data, num);
		return { getNum(data), index };
	}

	void addNum(stack<string>&data, int num)
	{
		if (!data.empty())
		{
			if (data.top() == "*" || data.top() == "/")
			{
				string add = data.top();
				data.pop();
				int b = stringToNum(data.top());
				data.pop();
				num = add == "*" ? b * num : b / num;
			}
		}
		data.push(numToStr(num));
	}


	int  getNum(stack<string>&data)
	{
		int sum = 0;
		bool flag = true;
		while (!data.empty())
		{
			string str = data.top();
			data.pop();
			if (str == "+")
				flag = true;
			else if (str == "-")
				flag = false;
			else
				sum += flag ? stringToNum(str) : -stringToNum(str);
		}
		return sum;
	}
	
	int stringToNum(string str)//�ַ�ת����
	{
		int num;
		stringstream ss;
		ss << str;
		ss >> num;
		return num;
	}

	string numToStr(int num)//����ת�ַ�
	{
		string str;
		stringstream ss;
		ss << num;
		ss >> str;
		return str;
	}
};


void Test()
{
	string str;
	calEquation* p = new calEquation;
	str = "3+4";
	cout << str << "=  " << p->cal(str) << endl;

	str = "3+4*5+2";
	cout << str << "=  " << p->cal(str) << endl;

	str = "3+2+3*(1+3)";
	cout << str << "=  " << p->cal(str) << endl;
}