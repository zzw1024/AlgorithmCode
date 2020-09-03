#if 1
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Node
{
	string s;//整数据
	int l;//数字字符长度
	int c;//数字字符次幂
	Node(int l=1000)
	{
		s.resize(l);
	}
};

void cp(Node*& src, Node*& des, int st, int l)
{
	for (int i = st, j = 0; i < st + l; ++i, ++j)
		des->s[j] = src->s[i];
	des->l = l;
	des->c = st + src->c;//次幂，因为是倒序存放的数据，所以位数就是次幂数
}

void  add(Node* pa, Node* pb, Node* ans)
{
	Node* temp;
	if (pa->c < pb->c)//确保pa次幂保持为最大
	{
		temp = pa;
		pa = pb;
		pb = temp;
	}
	ans->c = pb->c;//结果的次幂为小次幂，就如同10000+100，结果的次幂为1
	int palen = pa->l + pa->c;//计算出加数的整体长度
	int pblen = pb->l + pb->c;
	int len = palen > pblen ? palen : pblen;//得到最长加数
	int k = pa->c - pb->c;//维持两位数的个十百千万位数对其，k为次幂较大的pa左边补齐0的个数

	//加法
	int cc = 0;//进位
	int i = 0;
	for (i = 0; i < len - ans->c; ++i)//科学计数法后还需计算的位数
	{
		int ta, tb;
		//从左向右一位一位的加数，ta为pa数的左边的低位，不够长0来凑
		//tb为pb右边的高位，不够长，0来补
		if (i < k)
			ta = 0;
		else
			ta = pa->s[i - k] - '0';
		if (i < pb->l)
			tb = pb->s[i] - '0';
		else
			tb = 0;
		if (i >= pa->l + k)//防止pb字符太长
			ta = 0;
		ans->s[i] = (ta + tb + cc) % 10 + '0';
		cc = (ta + tb + cc) / 10;
	}
	if (cc)
		ans->s[i++] = cc + '0';//最后将进步加上
	ans->l = i;
}

//相乘
void mul(Node* pa, Node* pb, Node*& ans)
{
	int ma = pa->l >> 1;//相当于初以2
	int mb = pb->l >> 1;
	Node* temp;
	if (!ma || !mb)//出现了一个长度为1的数，则直接可以相乘了
	{
		if (!ma)//保证pb为长度为1的数
		{
			temp = pa;
			pa = pb;
			pb = temp;
		}
		ans->c = pa->c + pb->c;//乘数答案
		int cc = 0;//进位
		int i = 0;
		for (i = 0; i < pa->l; ++i)//pb的个位逐位与pa相乘
		{
			ans->s[i] = ((pb->s[0] - '0') * (pa->s[i] - '0') + cc) % 10 + '0';
			cc = ((pb->s[0] - '0') * (pa->s[i] - '0') + cc) / 10;
		}
		if (cc)
			ans->s[i++] = cc + '0';
		ans->l = i;
		return;
	}
	//分支的核心
	Node *ah = new Node(pa->l - ma);
	Node *al = new Node(ma); 
	Node *bh = new Node(pb->l - mb);
	Node *bl = new Node(mb);
	cp(pa, ah, ma, pa->l - ma);
	cp(pa, al, 0, ma);
	cp(pb, bh, mb, pb->l - mb);
	cp(pb, bl, 0, mb);

	Node *ans1 = new Node; 
	Node *ans2 = new Node; 
	Node *ans3 = new Node; 
	Node *ans4 = new Node;
	Node *z = new Node;
	mul(ah, bh, ans1);
	mul(ah, bl, ans2);
	mul(al, bh, ans3);
	mul(al, bl, ans4);

	add(ans3, ans4, ans);
	add(ans2, ans, z);
	add(ans1, z, ans);
}

void Test()
{
	Node *pa = new Node;
	Node *pb = new Node; 
	Node *ans = new Node;
	pa->s = "123";
	pb->s = "123";
	
	pa->s.reserve();

	reverse(pa->s.begin(), pa->s.end());
	reverse(pb->s.begin(), pb->s.end());
	pa->c = 0;
	pb->c = 0;
	pa->l = pa->s.length();
	pb->l = pb->s.length();
	mul(pa, pb, ans);
	reverse(ans->s.begin(), ans->s.end());
	cout << "ans: " << ans->s << endl;
	return;
}
#endif

#if 0
//program 3-4
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

#define M 100

char sa[1000];
char sb[1000];

typedef struct _Node
{
	int s[M];
	int l;            //代表字符串的长度
	int c;
} Node, *pNode;

void cp(pNode src, pNode des, int st, int l)
{
	int i, j;
	for (i = st, j = 0; i < st + l; i++, j++)
	{
		des->s[j] = src->s[i];
	}
	des->l = l;
	des->c = st + src->c;  //次幂

}

/*
分治法 大数乘法
X = A*10^n + B
Y = C*10^m + D
X*Y = A*C*10^(n+m) + A*D*10^n + B*C*10^m + B*D
*/

void add(pNode pa, pNode pb, pNode ans)
{
	int i, cc, k, palen, pblen, len;
	int ta, tb;
	pNode temp;
	if ((pa->c < pb->c))   //保证Pa的次幂大
	{
		temp = pa;
		pa = pb;
		pb = temp;
	}
	ans->c = pb->c;
	cc = 0;
	palen = pa->l + pa->c;
	pblen = pb->l + pb->c;
	if (palen > pblen)
		len = palen;
	else
		len = pblen;
	k = pa->c - pb->c;
	for (i = 0; i < len - ans->c; i++) //结果的长度最长为pa，pb之中的最大长度减去最低次幂
	{
		if (i < k)
			ta = 0;
		else
			ta = pa->s[i - k];//次幂高的补0，大于低的长度后与0进行计算
		if (i < pb->l)
			tb = pb->s[i];
		else
			tb = 0;
		if (i >= pa->l + k)
			ta = 0;
		ans->s[i] = (ta + tb + cc) % 10;
		cc = (ta + tb + cc) / 10;
	}
	if (cc)
		ans->s[i++] = cc;
	ans->l = i;
}

void mul(pNode pa, pNode pb, pNode ans)
{
	int i, cc, w;
	int ma = pa->l >> 1, mb = pb->l >> 1; //长度除2
	Node ah, al, bh, bl;
	Node t1, t2, t3, t4, z;
	pNode temp;

	if (!ma || !mb) //如果其中个数为1
	{
		if (!ma)   //如果a串的长度为1，pa,pb交换，pa的长度大于等于pb的长度
		{
			temp = pa;
			pa = pb;
			pb = temp;
		}
		ans->c = pa->c + pb->c;
		w = pb->s[0];
		cc = 0;     //此时的进位为c
		for (i = 0; i < pa->l; i++)
		{
			ans->s[i] = (w*pa->s[i] + cc) % 10;
			cc = (w*pa->s[i] + cc) / 10;
		}
		if (cc)
			ans->s[i++] = cc; //如果到最后还有进位，则存入结果
		ans->l = i;          //记录结果的长度
		return;
	}
	//分治的核心
	cp(pa, &ah, ma, pa->l - ma);  //先分成4部分al,ah,bl,bh
	cp(pa, &al, 0, ma);
	cp(pb, &bh, mb, pb->l - mb);
	cp(pb, &bl, 0, mb);

	mul(&ah, &bh, &t1);     //分成4部分相乘
	mul(&ah, &bl, &t2);
	mul(&al, &bh, &t3);
	mul(&al, &bl, &t4);

	add(&t3, &t4, ans);
	add(&t2, ans, &z);
	add(&t1, &z, ans);
}

int Test()
{
	Node ans, a, b;
	cout << "输入大整数 a:" << endl;
	cin >> sa;
	cout << "输入大整数 b:" << endl;
	cin >> sb;
	a.l = strlen(sa);//sa,sb以字符串进行处理
	b.l = strlen(sb);
	int z = 0, i;
	for (i = a.l - 1; i >= 0; i--)
		a.s[z++] = sa[i] - '0';             //倒向存储
	a.c = 0;
	z = 0;
	for (i = b.l - 1; i >= 0; i--)
		b.s[z++] = sb[i] - '0';
	b.c = 0;
	mul(&a, &b, &ans);
	cout << "最终结果为：";
	for (i = ans.l - 1; i >= 0; i--)
		cout << ans.s[i];         //ans用来存储结果，倒向存储
	cout << endl;
	return 0;
}


#endif