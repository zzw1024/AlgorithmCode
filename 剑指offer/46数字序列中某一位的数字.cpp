//#include "head.h"
//
//
//
//�Ե�15λ����2Ϊ����2������12����λ����λ��12�������0�ſ�ʼ�±�Ϊ1��λ�ã�
//����1������ȷ�������������ڼ�λ����;
//	�����һλ����n < 9; 
//	�������λ����n < 9 + 90 * 2 = 189;˵������λ����
//����2��ȷ�������������ĸ�����10 + (15 - 10) / 2 = 12��
//����3��ȷ���Ǹ�������һλ��15 - 10 - (12 - 10) * 2 = 1, ����λ�ڡ�12�����±�Ϊ1��λ�ã�������2��
//
//�Ե�1001λ����7Ϊ��
//����1������ȷ�������������ڼ�λ����;
//	�����һλ����n < 9; 
//	�������λ����n < 9 + 90 * 2 = 189; 
//	�������λ����n < 189 + 900 * 3 = 2889;
//˵������λ����
//����2��ȷ�������������ĸ�����100 + (1001 - 190) / 3 = 370��
//����3��ȷ���Ǹ�������һλ��1001 - 190 - (370 - 100) * 3 = 1, ����λ�ڡ�370�����±�Ϊ1��λ�ã�������7��
//class DigitsInSequence {
//	int digitAtIndex(int index) {
//		if (index < 0)
//			return -1;
//		if (index < 10)
//			return index;
//		int curIndex = 10, length = 2;
//		int boundNum = 10;
//		while (curIndex + lengthSum(length) < index) {
//			curIndex += lengthSum(length);
//			boundNum *= 10;
//			length++;
//		}
//		int addNum = (index - curIndex) / length;
//		int curNum = boundNum + addNum;
//		return to_string(curNum)[index - curIndex - addNum * length] - '0';
//	}
//	int lengthSum(int length) {
//		int count = 9;
//		for (int i = 1; i < length; i++)
//			count *= 10;
//		return count * length;
//	}
//};