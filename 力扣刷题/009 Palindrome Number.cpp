//
//
////ˮ�⿩
//bool isPalindrome(int x) {
//	if (x == 0)return true;
//	if (x < 0 || (x % 10 == 0))return false;//������β��Ϊ0�����ǻ�������
//	double num = 0;
//	int s = x;
//	while (x > 0) {
//		num = 10 * num + x % 10;
//		x = x / 10;
//	}
//	if (num == s)return true;
//	else return false;
//}