//#include "head.h"
//
//
//
//以第15位数字2为例（2隶属与12，两位数，位于12从左侧以0号开始下标为1的位置）
//步骤1：首先确定该数字是属于几位数的;
//	如果是一位数，n < 9; 
//	如果是两位数，n < 9 + 90 * 2 = 189;说明是两位数。
//步骤2：确定该数字属于哪个数。10 + (15 - 10) / 2 = 12。
//步骤3：确定是该数中哪一位。15 - 10 - (12 - 10) * 2 = 1, 所以位于“12”的下标为1的位置，即数字2。
//
//以第1001位数字7为例
//步骤1：首先确定该数字是属于几位数的;
//	如果是一位数，n < 9; 
//	如果是两位数，n < 9 + 90 * 2 = 189; 
//	如果是三位数，n < 189 + 900 * 3 = 2889;
//说明是三位数。
//步骤2：确定该数字属于哪个数。100 + (1001 - 190) / 3 = 370。
//步骤3：确定是该数中哪一位。1001 - 190 - (370 - 100) * 3 = 1, 所以位于“370”的下标为1的位置，即数字7。
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