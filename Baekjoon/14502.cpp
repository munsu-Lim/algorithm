#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, a[9][9], c[9][9], dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 }, ans, cnt;
vector <pair<int, int>> v;
queue <pair<int, int>> q;

void cal()
{
	int lans = 0;
	memset(c, 0, sizeof(c));
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]);
	}
	while (!q.empty())
	{
		int li = q.front().first;
		int lj = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ni = li + dy[i];
			int nj = lj + dx[i];
			if (ni > 0 && nj > 0 && ni <= n && nj <= m)
			{
				if (c[ni][nj] == 0 && a[ni][nj] == 0)
				{
					c[ni][nj] = 1;
					q.push(make_pair(ni, nj));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == 0 && a[i][j] == 0)
			{
				lans++;
			}
		}
	}
	ans = max(ans, lans);
}

void find(int i, int j, int num)
{
	if (num >= 3)
	{
		cal();
		return;
	}
	if (j > m)
	{
		find(i + 1, 1, num);
		return;
	}
	if (i > n)
	{
		return;
	}
	if (a[i][j] == 0)
	{
		a[i][j] = 1;
		find(i, j + 1, num + 1);
		a[i][j] = 0;
	}
	find(i, j + 1, num);
}

int main()
{
	ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 2)
			{
				v.push_back(make_pair(i, j));
			}
		}
	}
	find(1, 1, 0);
	printf("%d", ans);
}