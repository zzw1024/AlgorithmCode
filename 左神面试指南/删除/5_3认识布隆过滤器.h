#pragma once

#include <iostream>
#include <vector>

using namespace std;

//Problem:
//	   制作一个布隆过滤器
//	   有一个失误率：即宁可杀错一千，不可放过一个的一个产生失误率的机制。
//	   其结构如下所示：
//		   public class Test
//	   {
//		   public static void main（string[]args）
//		   {
//			   long[]arr = new long[1eee]；//s求eep 
//			   int index = 3eeee；
//			   int intIndex = index / 32；
//			   int bitIndex = index % 32
//			   arr[intIndex] = （arr[intIndex]I（1 << bitIndex））；
//		   }
//	   }
//
//Solution：
//	使用K个hash_map,对于每个hash_map使用不同的存储方式
//	每个hash_map如同一个数组空间，比如：int a[1000], 或者长一些long int b[100000];
//	然后将输入的值value进行操作：
//	value / size;    //找到该值将存放的地址即a[index]
//	value%size;   //将a[index]中的mod值的二进制数的位置进行“抹黑”置0或者置1操作。
//	使用不同的hash函数将数据存入不同的K个hash表中
//	然后查询时，同样查验每一个空间是否“抹黑”只要存在一个不存在"抹黑"的空间, 则表示该值不存在表中。
//
//	

//本代码使用一个数组来现小型布隆过滤器

#define N 32

class Blong
{
public:
	void Add(int a);
	void Find(int a);

private:
	int data[N] = {0};
};

void Blong::Add(int a)
{
	int index = a % N;
	int pot = a % N;
	this->data[index] = data[index] | (1 << pot);//置位
}

void Blong::Find(int a)
{
	int index = a % N;
	int pot = a % N;
	int i = 1;
	i = i << pot;
	if (this->data[index] == i)
		cout << "the num is already existence!" << endl;
	else
		cout << "the num is not existence!" << endl;

}


void Test()
{
	Blong B;
	B.Add(125);
	B.Add(15413);
	B.Add(12345);

	B.Find(123);
	B.Find(1234);
	B.Find(12345);

}
