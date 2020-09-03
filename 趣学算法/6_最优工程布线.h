#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//ʹ�õݹ�

//void Back(int i, int j, int n, int &res)//�����������Ҷ��ߵģ�������ԭ��̤���ģ�Ӧ���з������Ե�
//{
//	if (i == n && j == n)
//	{
//		res++;
//		return;
//	}
//	if (i == n)
//		Back(i, j + 1, n, res);//������
//	else if (j == n)
//		Back(i + 1, j, n, res);//������
//	else
//	{
//		Back(i, j + 1, n, res);//������
//		Back(i + 1, j, n, res);//������
//	}
//}
//

struct Node
{
	int x;
	int y;
	Node(int a = 0, int b = 0) :x(a), y(b) {}
};

void Test()
{
	int N = 8;
	vector<vector<int>>map(N, vector<int>(N, -1));
	map[1][6] = -2;
	map[2][3] = -2;
	map[3][4] = -2;
	map[3][5] = -2;
	map[5][1] = -2;
	Node S(2, 1);
	Node E(4, 6);
	if (S.x == E.x && S.y == E.y)
		return;
	int minCos = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (i == 0 || j == 0 || i==N || j==N)//��ΧΪ-2��
				map[i][j] = -2;
	queue<Node>q;
	q.push(S);
	int M[4][2] = { {0,-1} ,{0,1}, {-1,0}, {1,0} };
	map[S.x][S.y] = 0;
	Node p;
	Node next;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			next.x = p.x + M[i][0];
			next.y = p.y + M[i][1];
			if (map[next.x][next.y] == -1)
			{
				map[next.x][next.y] = map[p.x][p.y] + 1;
				q.push(next);
			}
			if ((next.x == E.x) && (next.y == E.y))//�����յ�
				break;
		}
		if ((next.x == E.x) && (next.y == E.y))//�����յ�
			break;
	}
	minCos = map[E.x][E.y];
	vector<Node>path;
	path.resize(minCos);
	p = E;
	for (int i = minCos - 1; i >= 0; --i)
	{
		path[i] = p;
		for (int j = 0; j < 4; ++j)
		{
			next.x = p.x + M[j][0];
			next.y = p.y + M[j][1];
			if (map[next.x][next.y] == i)
				break;//�ҵ���ͬ������
		}
		p = next;
	}
	cout << minCos << endl;
	for (auto a : path)
		cout << a.x << "  " << a.y << endl;
}

