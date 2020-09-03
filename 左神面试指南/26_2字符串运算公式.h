#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;


//【题目】
//	给定一个字符串str，str表示一个公式，公式里可能有整数、加减乘除符号和
//	左右括号，返回公式的计算结果。
//	【举例】
//	str = "48*((70-65)-43)+8*1"，返回 - 1816。
//	str = "3+1*4"，返回7。
//	str = "3+(1*4)"，返回7。
//	【说明】
//	1．可以认为给定的字符串一定是正确的公式，即不需要对str做公式有效性检
//	查。
//	2．如果是负数，就需要用括号括起来，比如"4*(-3)"。但如果负数作为公式的
//	开头或括号部分的开头，则可以没有括号，比如"-3*4"和"(-3）*4"都是合法的。
//	3．不用考虑计算过程中会发生溢出的情况
//	
//【解题】
//	一般是使用栈，因为栈处理括号问题很好
//	1、没有括号存在
//	使用栈：
//	首先使用栈对字符串str进行分解
//	当遇到数字，则数据开始，云算符结束，当遇到运算符，数据结束，字符开始
//	然后进行数据和运算符入栈，当栈顶为‘*’或‘ / ’时，将栈顶的运算符和下面的 那个数据拿出来与目前的数据进行运算，然后得到的结果压入栈中。
//	然后当字符串数据压入完毕，然后依次从栈出弹出数据以及运算符，进行运算即可
//	2、存在括号
//	定义函数fun(str, index)
//	表示计算从index开始的字符串数据，知道遇到右括号或者字符串尾部结束
//	即fun中实现的就是一个简单的括号内部无括号的运算操作



//使用单调函数
class calEquation
{
public:
	int cal(const string str)//计算
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
				data.push(sybol);//是运算符，加上
				num = 0;
			}
			else//是左括号
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
	
	int stringToNum(string str)//字符转数字
	{
		int num;
		stringstream ss;
		ss << str;
		ss >> num;
		return num;
	}

	string numToStr(int num)//数字转字符
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