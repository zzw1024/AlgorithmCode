#include "000�⺯��.h"

//һ��64������
void hanota(char a, char b, char c,int n) {
	
	if (n == 1)
		cout << a << "->" << c << endl; //����64����a,�Ƶ�c
	else {
		hanota(a, c, b, n - 1);//�Ƚ�����63�������Ƶ�b
		hanota(a, b, c, 1);//Ȼ�󽫵�64����a,�Ƶ�c
		hanota(b, a, c, n - 1);//���b�ϵ�63���Ƶ�c
	}
}


void T014() {
	char a = 'x';
	char b = 'y';
	char c = 'z';
	hanota(a, b, c, 3);

}