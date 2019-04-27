#include <cstdio>

using namespace std;

int d[6][4] = { {2, 3, 1, 4}, {2, 3, 5, 0}, {5, 0, 1, 4}, {0, 5, 1, 4}, {2, 3, 0, 5}, {2, 3, 4, 1} };
int n, m, k, a[20][20], o[1000], cur, ci, cj, dice[6];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, -1, 1 };

int reverse(int dir)
{
	if (dir == 0 || dir == 2)
	{
		return dir + 1;
	}
	else
	{
		return dir - 1;
	}
}

int main()
{
	scanf("%d %d %d %d %d", &n, &m,&ci, &cj,  &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &o[i]);
		o[i]--;
	}

	cur = 0;

	for (int i = 0; i < k; i++)
	{
		int ni = ci + dy[o[i]];
		int nj = cj + dx[o[i]];
		if (ni >= 0 && nj >= 0 && ni < n && nj < m)
		{
			if (a[ni][nj] == 0)
			{
				a[ni][nj] = dice[d[cur][o[i]]];
			}
			else
			{
				dice[d[cur][o[i]]] = a[ni][nj];
			}
			int rd = reverse(o[i]);
			cur = d[cur][rd];
			printf("%d\n", cur + 1);
			ci = ni;
			cj = nj;
		}
	}
	
}