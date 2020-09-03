#include <iostream>
#include <cmath>
const int maxn=100010；bool is prime（int n）{//判断n是否为素数if（n==1）return false；int sqr=（int）sqrt（1.0*n）；for（inti=2；i<=sqr；i++）{if（n8i==0）return false；return true；int prime[maxn]，pNum=0；void Find Prime（）{//求素数表for（int i=1；i< maxn；i+{
if（is prime（i）==true）{
prime[pNum++]=i；
）struct factor{
int x，cnt；//x为质因子，cnt为其个数
]fac[10]；