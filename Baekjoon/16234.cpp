#include <cstdio>
#include <cmath>

int a[51][51], n, l, r, d[51][51], c[2501][2], dn, ans;
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

void dfs(int i, int j)
{
	d[i][j] = dn;
	c[dn][0] += a[i][j];
	c[dn][1] += 1;
	for (int k = 0; k < 4; k++)
	{
		if (i + dx[k] > 0 && i + dx[k] <= n && j + dy[k] <= n && j + dy[k] > 0 && d[i + dx[k]][j + dy[k]] == 0)
		{
			int t = abs(a[i][j] - a[i + dx[k]][j + dy[k]]);
			if (t >= l && t <= r)
			{
				dfs(i + dx[k], j + dy[k]);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[j][i]);
		}
	}
	for (int t = 1; t <= 2000; t++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = 0;
			}
		}
		dn = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!d[i][j])
				{
					dn++;
					c[dn][0] = 0;
					c[dn][1] = 0;
					dfs(i, j);
				}
			}
		}
		if (dn >= n * n)
		{
			break;
		}
		ans++;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int l = d[i][j];
				{
					a[i][j] = c[l][0] / c[l][1];
				}
			}
		}
	}
	printf("%d", ans);
}