//#pragma once
//#include <iostream>
//#include <stack>
//#include <string>
//#include <vector>
//
//using namespace std;
////�����⡿
////��ŵ������ȽϾ��䣬�����޸�һ����Ϸ����
////�������Ʋ��ܴ���������ֱ���ƶ������Ҳ࣬Ҳ���ܴ����Ҳ�ֱ���ƶ�������࣬
////���Ǳ��뾭���м䡣������N���ʱ�򣬴�ӡ�����ƶ����̺������ƶ��ܲ�����
////���磬������Ϊ����ʱ�����ϲ������Ϊ1�����²������Ϊ2�����ӡ��
////Move 1 from left to mid 
////Move 1 from mid to right 
////Move 2 from left to mid
////Move 1 from right to mid 
////Move 1 from mid to left 
////Move 2 from mid to right 
////Move 1 from left to mid
////Move 1 from mid to right 
////It will move 8 steps.
//
////����һ��
////ʹ�õݹ�ķ���
////���۶��ٲ㣬�����������㣬����һ��(����ΪX)��(N - 1)��ϲ���������Ϊһ��(����ΪY)��Ŀ���ǽ�X�ƶ������Ҳ࣬Ȼ���ٰ�Y�ƶ������Ҳࡣ
////Y��A���ƶ���B��
////Y��B���ƶ���C��
////X��A���ƶ���B��
////Y��C���ƶ���B��
////Y��B���ƶ���A��
////X��B���ƶ���C��
////��Y����X�������ݹ��ƶ�
//
//
//
//void Hanota(string l, string m, string r, int n)
//{
//	if (n == 1)//��Ϊһ��ʱ���������ֱ���ƶ������Ҷ�
//	{
//		cout << n << ": " << l << "->" << m << endl;
//		cout << n << ": " << m << "->" << r << endl;
//		return;
//	}
//	//����n-1����һ������Y
//	Hanota(l, m, r, n - 1);//Yֱ���ƶ������Ҷ�
//	cout << n << ": " << l << "->" << m << endl;//X�ƶ����м�
//	Hanota(r, m, l, n - 1);//Y�ƶ��������
//	cout << n << ": " << m << "->" << r << endl;//n�ƶ������Ҷ�
//	Hanota(l, m, r, n - 1);//Y�ƶ������Ҷ�
//}
//
//
//
//
////����ջ��ʵ��
////������ջ��ʵ�֣�����ջ�ֱ�ΪLs,Ms,Rs
////Ϊ�˲�Υ����ŵ���д���ѹС�ķ���
////����ջ����ά��С�����ϣ���������
////����
////����һ��Ϊ��LM����һ�������������
////
////ִ��LM��Υ��Сѹ��ԭ��
////ִ��ML��Υ���淴ԭ��
////ִ��MR����RM������Сѹ��ԭ������������ǻ���ģ�ֻ�ܰ�������ѡһ
////�����������ƣ�ʡ��...
//void Help(string &pre, string preMove, string nowMove, stack<int>&Fs, stack<int>&Ts)
//{
//	if (!Fs.empty() && pre != nowMove && Fs.top() < Ts.top())
//	{
//		Ts.push(Fs.top());
//		Fs.pop();
//		cout << preMove << endl;
//		pre = preMove;
//	}
//}
//
//
//void stackToHanota(int n, string l, string m, string r)
//{
//	stack<int>Ls, Ms, Rs;
//	//Ϊ�˷���Ƚ�ջ��Ԫ�أ��������ȶ�ÿ��ջ��ѹ��һ���ϴ���
//	Ls.push(INT_MAX);
//	Ms.push(INT_MAX);
//	Rs.push(INT_MAX);
//	string pre = "LoM";
//	for (int i = n; i > 0; --i)
//		Ls.push(i);//������ջ
//	int layerSize = Ls.size();
//	while (layerSize != Rs.size())
//	{//������->������
//		Help(pre, "LoM", "MoL", Ls, Ms);
//		Help(pre, "MoR", "RoM", Ms, Rs);
//		Help(pre, "RoM", "MoR", Rs, Ms);
//		Help(pre, "MoL", "LoM", Ms, Ls);
//	}
//}
//
//
//
//
//int main()
//{
//	string l = "��";
//	string m = "��";
//	string r = "��";
//	//Hanota(l, m, r, 3);
//	stackToHanota(3, l, m, r);
//	while (1);
//}