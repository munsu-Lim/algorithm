#include <cstdio>
#include <queue>

using namespace std;

int a[2][500][500], c[500][500];
int t, n, m, k, ans, dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 };

queue <pair<int, int>> r[2], ac[2];

void cal()
{
	int cnt = 0;
	int ncnt;
	for (int i = 0; i < k; i++)
	{
		ncnt = 1 - cnt;
		while (!r[cnt].empty())
		{
			int li = r[cnt].front().first;
			int lj = r[cnt].front().second;
			c[li][lj] = -1;
			r[cnt].pop();
			if (a[0][li][lj] - 1 > 0)
			{
				a[0][li][lj] -= 1;
				r[ncnt].push(make_pair(li, lj));
			}
			else
			{
				a[0][li][lj] = a[1][li][lj];
				ac[ncnt].push(make_pair(li, lj));
			}
		}
		while (!ac[cnt].empty())
		{
			int li = ac[cnt].front().first;
			int lj = ac[cnt].front().second;
			ac[cnt].pop();
			if (a[1][li][lj] - 1 > 0)
			{
				a[1][li][lj] -= 1;
				ac[ncnt].push(make_pair(li, lj));
			}
			for (int k = 0; k < 4; k++)
			{
				int ni = li + dy[k];
				int nj = lj + dx[k];
				if (c[ni][nj] >= 0 && c[ni][nj] < a[0][li][lj])
				{
					if (c[ni][nj] == 0)
					{
						r[ncnt].push(make_pair(ni, nj));
					}
					c[ni][nj] = a[0][li][lj];
					a[0][ni][nj] = a[0][li][lj];
					a[1][ni][nj] = a[0][li][lj];
				}
			}
		}
		cnt = ncnt;
	}
	while (!r[cnt].empty())
	{
		r[cnt].pop();
		ans++;
	}
	while (!ac[cnt].empty())
	{
		ac[cnt].pop();
		ans++;
	}
}

int main()
{
	scanf("%d", &t);
	for (int lt = 1; lt <= t; lt++)
	{
		ans = 0;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < 500; i++)
		{
			for (int j = 0; j < 500; j++)
			{
				a[0][i][j] = 0;
				a[1][i][j] = 0;
				c[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[0][250 + i][250 + j]);
				a[1][250 + i][250 + j] = a[0][250 + i][250 + j];
				if (a[0][250 + i][250 + j] > 0)
				{
					r[0].push(make_pair(250 + i, 250 + j));
				}
			}
		}

		cal();
		if (lt > 1)
		{
			printf("\n");
		}
		printf("#%d %d", lt, ans);

	}
}