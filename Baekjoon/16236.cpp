#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int shark = 2, n, a[21][21], ci, cj, d[21][21], dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 }, s, store;
queue <pair<int, int>> q;
bool eat = true;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 9)
			{
				ci = i;
				cj = j;
				a[i][j] = 0;
			}
		}
	}

	while (eat)
	{
		eat = false;
		if (store >= shark)
		{
			store -= shark;
			shark++;
		}
		q.push(make_pair(ci, cj));
		d[ci][cj] = 1;
		while (!q.empty())
		{
			int li = q.front().first;
			int lj = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++)
			{
				int ni = li + dy[k];
				int nj = lj + dx[k];
				if (ni > 0 && nj > 0 && ni <= n && nj <= n)
				{
					if (d[ni][nj] == 0 && a[ni][nj] <= shark)
					{
						d[ni][nj] = d[li][lj] + 1;
						q.push(make_pair(ni, nj));
					}
				}
			}
		}
		int lmin = 987987987;
		int ni, nj;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][j] > 1 && a[i][j] < shark &&lmin > d[i][j] && a[i][j] != 0)
				{
					eat = true;
					lmin = d[i][j];
					ni = i;
					nj = j;
				}
			}
		}
		if (eat)
		{
			s += d[ni][nj] - 1;
			store ++;
			a[ni][nj] = 0;
			ci = ni;
			cj = nj;
		}
		memset(d, 0, sizeof(d));
	}
	printf("%d", s);
	return 0;
}