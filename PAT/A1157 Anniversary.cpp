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
//	string id, oldGuset = "20201231", oldAlumni = "20201231", gusetId, alumniId;//�������ϵ����������ʹ�õ��������Ӧ�ÿ��Ե�
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> id;
//		map[id] = true;//��¼֪ͨ����
//	}
//	cin >> m;
//	while (m--)
//	{
//		cin >> id;
//		string str = id.substr(6, 8);//��ȡ��������
//		if (oldGuset > str)//����Խ�󣬳���ʱ��Խ��
//		{
//			oldGuset = str;
//			gusetId = id;
//		}
//		if (map[id])//�����ǹ��
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
