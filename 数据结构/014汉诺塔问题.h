#include "000库函数.h"

//一共64个盘子
void hanota(char a, char b, char c,int n) {
	
	if (n == 1)
		cout << a << "->" << c << endl; //将第64个从a,移到c
	else {
		hanota(a, c, b, n - 1);//先将上面63个盘子移到b
		hanota(a, b, c, 1);//然后将第64个从a,移到c
		hanota(b, a, c, n - 1);//最后将b上的63个移到c
	}
}


void T014() {
	char a = 'x';
	char b = 'y';
	char c = 'z';
	hanota(a, b, c, 3);

}