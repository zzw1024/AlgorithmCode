////#include <iostream>
////#include <string>
////
////using namespace std;
////
////
//////很简单，就是找到来的最早的人和回去最晚的人即可
////int getTime(string Time)
////{
////	//由于时间时标准输入，所以很好计算
////	return ((Time[0] - '0') * 10 + (Time[1] - '0')) * 60 * 60 +
////		((Time[3] - '0') * 10 + (Time[4] - '0')) * 60 + 
////		(Time[6] - '0') * 10 + (Time[7] - '0');
////	 
////}
////
////int main()
////{
////	int M;
////	cin >> M;
////	string firstMan, lastMan;
////	int firstTime, lastTime;
////	firstTime = 24 * 60*60 + 1;//24小时多一秒，属于第二天了
////	lastTime = -1;//属于前一天
////	string No, InTime, OutTime;
////	for (int i = 0; i < M; ++i)
////	{
////		cin >> No >> InTime >> OutTime;
////		if (firstTime > getTime(InTime))
////		{
////			firstTime = getTime(InTime);
////			firstMan = No;
////		}
////		if (lastTime < getTime(OutTime))
////		{
////			lastTime = getTime(OutTime);
////			lastMan = No;
////		}
////	}
////	cout << firstMan << " " << lastMan << endl;
////	return 0;
////}
//
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//struct Node
//{
//	string ID;
//	int in, out;
//};
//int main()
//{
//	int m, iH, iM, iS, oH, oM, oS;
//	string id;
//	vector<Node>students;
//	cin >> m;
//	while (m--)
//	{
//		cin >> id;
//		scanf("%d:%d:%d %d:%d:%d", &iH, &iM, &iS, &oH, &oM, &oS);
//		students.push_back({ id,iH * 3600 + iM * 60 + iS,oH * 3600 + oM * 60 + oS });
//	}
//	sort(students.begin(), students.end(), [](Node a, Node b) {return a.in < b.in; });
//	cout << students[0].ID << " ";
//	sort(students.begin(), students.end(), [](Node a, Node b) {return a.out > b.out; });
//	cout << students[0].ID;
//	return 0;
//}