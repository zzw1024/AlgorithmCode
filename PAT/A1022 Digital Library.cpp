////#include <iostream>
////#include <map>
////#include <unordered_map>
////#include <set>
////#include <string>
////using namespace std;
//////第一种方法
//////以时间换空间，就是个ID保留一组信息，查询时遍历查询
//////但可能导致时间复杂度过大
//////
//////第二种方法[推荐使用方法二]
//////以空间换时间，每种信息对应一个ID，查找时，时间复杂度为O(1)
//////但可能导致空间复杂度太大
//////
//////注意一些字符输入的细节
////
////方法一：
////struct node
////{
////	string name, author, keywords, publisher, year;
////};
////int main()
////{
////	int N, M;
////	string ID;
////	cin >> N;
////	map<string, node>data;
////	for (int i = 0; i < N; ++i)
////	{
////		node book;
////		cin >> ID;
////		getchar();//去除回车键
////		getline(cin, book.name);
////		getline(cin, book.author);
////		getline(cin, book.keywords);
////		getline(cin, book.publisher);
////		cin >> book.year;
////		data[ID] = book;
////	}
////	cin >> M;
////	getchar();//去除回车键
////	for (int i = 0; i < M; ++i)
////	{
////		string str;
////		bool is = true;
////		getline(cin, str);
////		cout << str << endl;
////		int index = str[0] - '0';
////		str.assign(str.begin() + 3, str.end());
////		for (auto ptr = data.begin(); ptr != data.end(); ++ptr)
////		{
////			switch (index)
////			{
////			case 1:
////				if (ptr->second.name == str)
////				{
////					is = false;
////					cout << ptr->first << endl;
////				}
////				break;
////			case 2:
////				if (ptr->second.author== str)
////				{
////					is = false;
////					cout << ptr->first << endl;
////				}
////				break;
////			case 3:
////				if (ptr->second.keywords.find(str) !=-1)
////				{
////					is = false;
////					cout << ptr->first << endl;
////				}
////				break;
////			case 4:
////				if (ptr->second.publisher == str)
////				{
////					is = false;
////					cout << ptr->first << endl;
////				}
////				break;
////			case 5:
////				if (ptr->second.year == str)
////				{
////					is = false;
////					cout << ptr->first << endl;
////				}
////				break;
////			default:
////				break;
////			}
////		}
////		if (is)
////			cout << "Not Found" << endl;		
////	}
////	return 0;
////}
////
//////方法二
////void findInfo(unordered_map<string, set<int>>&data,string &str)//传参一定要用引用，否则最后一组数据可能会超时
////{
////	if(data.find(str)==data.end())
////		printf("Not Found\n");
////	else
////	{
////		for (auto ptr = data.find(str)->second.begin(); ptr != data.find(str)->second.end(); ++ptr)
////			printf("%07d\n", *ptr);
////	}
////}
////int main()
////{
////	int N, M, ID;
////	scanf("%d", &N);
////	string til, aut, keys, pub, yea;
////	unordered_map<string, set<int>>title, author, keywords, publisher, year;//因为key不唯一
////	for (int i = 0; i < N; ++i)
////	{
////		scanf("%d\n", &ID);//不用清除回车键
////		getline(cin, til);
////		title[til].insert(ID);
////		getline(cin, aut);
////		author[aut].insert(ID);
////		while (cin >> keys)
////		{
////			keywords[keys].insert(ID);
////			char c = getchar();
////			if (c == '\n')break;
////		}
////		getline(cin, pub);
////		publisher[pub].insert(ID);
////		getline(cin, yea);
////		year[yea].insert(ID);
////	}
////	scanf("%d\n", &M);
////	for (int i = 0; i < M; ++i)
////	{
////		string str;
////		getline(cin, str);
////		cout << str << endl;
////		int index = str[0] - '0';
////		str.assign(str.begin() + 3, str.end());
////		if (index == 1) findInfo(title, str);
////		else if (index == 2) findInfo(author, str);
////		else if (index == 3) findInfo(keywords, str);
////		else if (index == 4) findInfo(publisher, str);
////		else if (index == 5) findInfo(year, str);
////		else printf("Not Found\n");
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <set>
//#include <sstream>
//#include <unordered_map>
//using namespace std;
//int n, m, k = 6;
//unordered_map<string, set<int>>map[6];
//int main()
//{
//	cin >> n;
//	int id;
//	string str, substr;
//	for (int i = 0; i < n; ++i)
//	{		
//		cin >> id;
//		getchar();
//		for (int j = 1; j < k; ++j)
//		{
//			getline(cin, str);
//			if (j == 3)
//			{
//				istringstream ss(str);
//				while (ss)
//				{
//					ss >> substr;
//					map[j][substr].insert(id);
//				}
//			}
//			map[j][str].insert(id);
//		}
//	}
//	cin >> m;
//	getchar();
//	while (m--)
//	{
//		getline(cin, str);
//		cout << str << endl;
//		id = str[0] - '0';
//		str.assign(str.begin() + 3, str.end());
//		if (map[id].find(str) == map[id].end())
//			cout << "Not Found" << endl;
//		else
//			for (auto ptr = map[id][str].begin(); ptr != map[id][str].end(); ++ptr)
//				printf("%07d\n", *ptr);
//	}
//	return 0;
//}
