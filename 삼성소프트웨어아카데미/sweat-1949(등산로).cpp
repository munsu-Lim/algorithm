#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int t, n, k, a[9][9], hMax, a2[9][9], d[9][9], ans;
int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 };
vector<pair<int, int>> list;
queue <pair<int,int>> q;

void bfs()
{
	for (int i = 0; i < list.size(); i++)
	{
		q.push(make_pair(list[i].first, list[i].second));
		d[list[i].first][list[i].second] = 1;
	}
	while (!q.empty())
	{
		int li = q.front().first;
		int lj = q.front().second;
		if (d[li][lj] > ans)
		{
			ans = d[li][lj];
		}
		q.pop();
		for (int l = 0; l < 4; l++)
		{
			int ni = li + dy[l];
			int nj = lj + dx[l];
			if (ni > 0 && nj > 0 && ni <= n && nj <= n && a2[ni][nj] < a2[li][lj] && d[ni][nj] < d[li][lj] + 1)
			{
				d[ni][nj] = d[li][lj] + 1;
				q.push(make_pair(ni, nj));
			}
		}
	}
}

int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		ans = 0;
		list.clear();
		hMax = 0;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				a2[i][j] = a[i][j];
				if (a[i][j] > hMax)
				{
					hMax = a[i][j];
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] == hMax)
				{
					list.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int l = 0; l <= k; l++)
				{
					if (a2[i][j] > 0)
					{
						a2[i][j] -= l;
						bfs();
						memset(d, 0, sizeof(d));
						a2[i][j] = a[i][j];
					}
				}
			}
		}
		
		if (z > 1)
		{
			printf("\n");
		}
		
		printf("#%d %d", z, ans);
	}
}