//#include "head.h"
//
//class Solution {
//public:
//	bool isNumeric(char* string)
//	{
//		if (string == nullptr)return false;
//
//		bool numeric = scanInteger(&string);
//
//		// �������'.'�������������ֵ�С������
//		if (*string == '.')
//		{
//			++string;
//
//			// ����һ�д�����||��ԭ��
//			// 1. С������û���������֣�����.123����0.123��
//			// 2. С����������û�����֣�����233.����233.0��
//			// 3. ��ȻС����ǰ��ͺ�����������֣�����233.666
//			numeric = scanUnsignedInteger(&string) || numeric;
//		}
//
//		// �������'e'����'E'�����������ŵ������ֵ�ָ������
//		if (*string == 'e' || *string == 'E')
//		{
//			++string;
//
//			// ����һ�д�����&&��ԭ��
//			// 1. ��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣�����.e1��e1��
//			// 2. ��e��E����û������ʱ�������ַ������ܱ�ʾ���֣�����12e��12e+5.4
//			numeric = numeric && scanInteger(&string);
//		}
//
//		return numeric && *string == '\0';
//	}
//
//	bool scanUnsignedInteger(char** str)
//	{
//		const char* before = *str;
//		while (**str != '\0' && **str >= '0' && **str <= '9')
//			++(*str);
//
//		// ��str�д�������0-9������ʱ������true
//		return *str > before;
//	}
//
//	// �����ĸ�ʽ������[+|-]B��ʾ, ����BΪ�޷�������
//	bool scanInteger(char** str)
//	{
//		if (**str == '+' || **str == '-')
//			++(*str);
//		return scanUnsignedInteger(str);
//	}
//};
//
//
//int main()
//{
//	int a = 0;
//}