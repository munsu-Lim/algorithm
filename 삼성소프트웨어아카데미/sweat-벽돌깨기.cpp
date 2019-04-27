#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int t,n, w, h, a[16][13], ans, sq[4], d[16][13];
int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 };
queue <pair<pair<int, int>, int>> list;

void printArr()
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
}

void bomb(int c)
{
	for (int i = 1; i <= h; i++)
	{
		if (d[i][c] > 1)
		{
			list.push(make_pair(make_pair(i, c), d[i][c]));
			d[i][c] = 0;
			break;
		}
		else if (d[i][c] == 1)
		{
			d[i][c] = 0;
			break;
		}
	}
	while (!list.empty())
	{
		int li = list.front().first.first;
		int lj = list.front().first.second;
		int cur = list.front().second;
		list.pop();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j < cur; j++)
			{
				int ni = li + (dy[i] * j);
				int nj = lj + (dx[i] * j);
				if (ni > 0 && nj > 0 && ni <= h && nj <= w)
				{
					if (d[ni][nj] > 1)
					{
						list.push(make_pair(make_pair(ni, nj), d[ni][nj]));
					}
					d[ni][nj] = 0;
				}
			}
		}
	}
}

void set()
{
	for (int j = 1; j <= w; j++)
	{
		for (int i = h; i > 0; i--)
		{
			bool bFind = true;
			if (d[i][j] == 0)
			{
				bFind = false;
				for (int k = i - 1; k > 0; k--)
				{
					if (d[k][j] > 0)
					{
						d[i][j] = d[k][j];
						d[k][j] = 0;
						bFind = true;
						break;
					}
				}
			}
			if (!bFind)
			{
				break;
			}
		}
	}
}

void cal()
{
	int lans = 0;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			d[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		bomb(sq[i]);
		set();
	}
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (d[i][j] > 0)
			{
				lans++;
			}
		}
	}
	ans = min(lans, ans);
}

int main()
{
	scanf("%d", &t);
	for (int lt = 1; lt <= t; lt++)
	{
		ans = 987987987;
		scanf("%d %d %d", &n, &w, &h);
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				for (int k = 1; k <= w; k++)
				{
					for (int l = 1; l <= w; l++)
					{
						sq[0] = i;
						sq[1] = j;
						sq[2] = k;
						sq[3] = l;
						cal();
						if (n < 4 || ans == 0)
						{
							break;
						}
					}
					if (n < 3 || ans == 0)
					{
						break;
					}
				}
				if (n < 2 || ans == 0)
				{
					break;
				}
			}
		}
		printf("#%d %d", lt, ans);
	}
	return 0;
}
