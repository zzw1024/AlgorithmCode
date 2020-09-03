//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Person
//{
//	int arriveTime, serverTime, popTime;
//};
//
//int N, K;
//
//int main()
//{
//	cin >> N >> K;
//	vector<Person*>window(K);//就排一个人办业务，不需要用队列
//	vector<Person*>data;
//	double waitTime = 0.0;
//	for (int i = 0; i < N; ++i)
//	{
//		int hh, mm, ss, tt;
//		Person* one = new Person;		
//		scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
//		one->arriveTime = hh * 3600 + mm * 60 + ss;
//		one->serverTime = tt * 60;
//		if (one->arriveTime <= (17 * 3600))//下班了，不算
//			data.push_back(one);
//	}
//	sort(data.begin(), data.end(), [](Person* a, Person* b) {return a->arriveTime < b->arriveTime; });
//	for (int i = 0; i < data.size(); ++i)
//	{
//		if (i < K)
//		{
//			if (data[i]->arriveTime < (8 * 3600))//来早了
//				waitTime += 8 * 3600 - data[i]->arriveTime; 
//			data[i]->popTime = data[i]->serverTime + (data[i]->arriveTime < (8 * 3600) ? 8 * 3600 : data[i]->arriveTime);
//			window[i%K] = data[i];
//		}
//		else
//		{
//			int index = 0, minTime = window[0]->popTime;
//			for (int j = 0; j < K; ++j)
//			{
//				if (minTime > window[j]->popTime)
//				{
//					index = j;
//					minTime = window[j]->popTime;
//				}
//			}
//			waitTime += data[i]->arriveTime < minTime ? (minTime - data[i]->arriveTime) : 0;//早到就等待
//			data[i]->popTime = data[i]->serverTime + (data[i]->arriveTime < minTime ? minTime : data[i]->arriveTime);
//			window[index] = data[i];
//		}
//	}
//	if (data.size() == 0)
//		printf("0.0\n");
//	else
//		printf("%0.1f\n", (waitTime / (60 * data.size())));
//	return 0;
//}
//
