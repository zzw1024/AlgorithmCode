//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	int n, m, cnt = 0;
//	cin >> n;
//	unordered_map<string, bool>map;
//	string id, oldGuset = "20201231", oldAlumni = "20201231", gusetId, alumniId;//这里最老的人物的年龄使用的是明年的应该可以的
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> id;
//		map[id] = true;//记录通知的人
//	}
//	cin >> m;
//	while (m--)
//	{
//		cin >> id;
//		string str = id.substr(6, 8);//获取出生年月
//		if (oldGuset > str)//年龄越大，出生时间越早
//		{
//			oldGuset = str;
//			gusetId = id;
//		}
//		if (map[id])//此人是贵宾
//		{
//			++cnt;
//			if (oldAlumni > str)
//			{
//				oldAlumni = str;
//				alumniId = id;
//			}
//		}
//	}
//	printf("%d\n", cnt);
//	if (cnt > 0)
//		printf("%s\n", alumniId.c_str());
//	else
//		printf("%s\n", gusetId);	
//	return 0;
//}
//
