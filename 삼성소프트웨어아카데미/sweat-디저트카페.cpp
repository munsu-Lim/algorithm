#include <cstdio>
#include <map>

using namespace std;

int n, a[21][21], t, dx[] = { -1, 1, 1, -1 }, dy[] = { 1, 1, -1, -1 };
int dr[] = { 0, 1, 0, -1 }, dd[] = { 1, 0, -1, 0 }, ans;

map <int, int> c[3];

void dfs(int i, int j, int down, int right, int con, int num)
{
	int lcnt = 1;
	int ni = i + dy[con];
	int nj = j + dx[con];
	if (con < 2)
	{
		c[con].clear();
		c[0][a[i][j]] = 1;
		while (ni > 0 && nj > 0 && ni <= n && nj <= n && c[con][a[ni][nj]] == 0)
		{
			if (con == 0 || c[0][a[ni][nj]] == 0)
			{
				c[con][a[ni][nj]] = 1;
				dfs(ni, nj, down + (dd[con] * lcnt), right + (dr[con] * lcnt), con + 1, num + lcnt);
				ni += dy[con];
				nj += dx[con];
				lcnt++;
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		c[2].clear();
		ni = i;
		nj = j;
		for (int k = 0; k < down; k++)
		{
			ni += dy[2];
			nj += dx[2];
			if (ni > 0 && nj > 0 && ni <= n && nj <= n && c[0][a[ni][nj]] == 0 && c[1][a[ni][nj]] == 0 && c[2][a[ni][nj]] == 0)
			{
				c[2][a[ni][nj]] = 1;
				num++;
			}
			else
			{
				return;
			}

		}
		for (int k = 0; k < right - 1; k++)
		{
			ni += dy[3];
			nj += dx[3];
			if (ni > 0 && nj > 0 && ni <= n && nj <= n && c[0][a[ni][nj]] == 0 && c[1][a[ni][nj]] == 0 && c[2][a[ni][nj]] == 0)
			{
				c[2][a[ni][nj]] = 1;
				num++;
			}
			else
			{
				return;
			}
		}
		if (ans < num)
		{

			ans = num;
		}
		return;
	}
}

int main()
{
	scanf("%d", &t);
	for (int lt = 1; lt <= t; lt++)
	{
		ans = -1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{

				dfs(i, j, 0, 0, 0, 1);
			}
		}
		if (lt > 1)
		{
			printf("\n");
		}
		printf("#%d %d", lt, ans);
	}
	return 0;
}