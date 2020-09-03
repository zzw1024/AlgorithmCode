#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <stdlib.h>
#include <time.h>

using namespace std;


void ttest(double data)
{
	cout << data << endl;
}

void TesTest()
{
	srand((unsigned)time(NULL));
	double data;
	long long int a = 11;
	while(1)
	{
		data = a++;
		ttest(data);
	}	

}