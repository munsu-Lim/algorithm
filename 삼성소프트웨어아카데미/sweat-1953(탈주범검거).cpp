#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int t, n, m, ans, a[50][50], c[50][50];
int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 };
int p[4][4] = { {1, 2, 5, 6},{1, 2, 4, 7},{1, 3, 4, 5}, {1, 3, 6, 7} };
bool s[7][4] = { {1, 1, 1, 1}, {1,1, 0, 0}, {0, 0, 1, 1}, {1, 0, 0, 1}, {0, 1, 0, 1}, {0, 1, 1, 0}, {1, 0, 1, 0} };

queue <pair <int, int>> q;

int main()
{
	scanf("%d", &t);
	for (int cnt = 1; cnt <= t; cnt++)
	{
		int si, sj, l;
		memset(c, 0, sizeof(c));
		ans = 0;
		scanf("%d %d", &n, &m);
		scanf("%d %d", &si, &sj);
		q.push(make_pair(si, sj));
		c[si][sj] = 1;
		scanf("%d", &l);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		while (!q.empty())
		{
			int li = q.front().first;
			int lj = q.front().second;
			int now = a[li][lj] - 1;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				if (s[now][i])
				{
					int ni = li + dy[i];
					int nj = lj + dx[i];
					if (ni >= 0 && nj >= 0 && ni <= n && nj <= m)
					{
						if (a[ni][nj] > 0 && c[ni][nj] == 0)
						{
							for (int k = 0; k < 4; k++)
							{
								if (p[i][k] == a[ni][nj])
								{
									c[ni][nj] = c[li][lj] + 1;
									q.push(make_pair(ni, nj));
									break;
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] > 0 && c[i][j] <= l)
				{
					ans++;
				}
			}
		}
		if (cnt > 1)
		{
			printf("\n");
		}
		printf("#%d %d", cnt, ans);
	}
}