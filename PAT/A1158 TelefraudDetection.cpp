//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//int main()
//{
//	int k, n, m, t;
//	cin >> k >> n >> m;
//	vector<int>call(n + 1, 0), back(n + 1, 0);//�̵绰���ȥ�ļ�¼����Щ�˴�ؽ����ļ�¼
//	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));//�绰��¼,��ס��¼�����ۼƵ�ͨ��ʱ��
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		v[a][b] += c;//���ۼ�ͨ��ʱ���
//	}
//	for (int i =1; i <= n; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//		{
//			if (v[i][j]>0 && v[i][j] <= 5)//��ͨ��ʱ�����Ƕ̵绰
//			{
//				++call[i];//����i���ȥ������
//				if (v[j][i] > 0)//����j�ظ���i��
//					++back[i];//����ظ�i������
//			}			
//		}
//	}	
//	vector<int>suspect, team(n + 1, 0);//ͳ��թƭ���������ͳ�ʼ�����ǵ��ŶӺ�
//	for (int i = 1; i <= n; ++i)
//	{
//		if (call[i] > k && call[i] >= back[i]*5)//���ȥ������������ֵk���ص绰�����������ڴ��ȥ��20%,ע��
//		{
//			team[i] = i;//������ͬı��
//			suspect.push_back(i);
//		}
//	}	
//	for (int i = 0; i < suspect.size(); ++i)//������Ȼ��˫��ѭ��������թƭ������������С�ģ���������Ӧ�ò��ᳬʱ��ģ���Ȼ�����˵Ļ�������DFS����
//		for (int j = i + 1; j < suspect.size(); ++j)
//			if (v[suspect[i]][suspect[j]] > 0 && v[suspect[j]][suspect[i]] > 0)//������թƭ���໥����绰
//				team[suspect[j]] = team[suspect[i]];
//	map<int, vector<int>>res;
//	for (int i = 1; i <= n; ++i)
//		if (team[i] > 0)
//			res[team[i]].push_back(i);//������ͬһ���թƭ����һ��
//	if (suspect.size() == 0)
//		printf("None");
//	else
//	{
//		for (auto ptr = res.begin(); ptr != res.end(); ++ptr)
//		{
//			for (int i = 0; i < ptr->second.size(); ++i)//���ڱ����Ǵ�С����ģ����Բ�������
//				printf("%s%d", i == 0 ? "" : " ", ptr->second[i]);
//			printf("\n");
//		}
//	}
//	return 0;
//}