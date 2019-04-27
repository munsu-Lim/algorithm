#include <cstdio>
#include <cstring>

using namespace std;

int t, d[2][100][100], a[2][100][100], dMax[2][100][100], n, m, k, ans;
int dx[] = { 0, -1, 0, 1 }, dy[] = { -1, 0, 1, 0 };

int setdir(int dir)
{
	switch (dir)
	{
	case 1 :
		return 0;
	case 2 :
		return 2;
	case 3 :
		return 1;
	case 4 :
		return 3;
	default:
		break;
	}
	return -1;
}

int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		ans = 0;
		memset(d, 0, sizeof(d));
		memset(a, 0, sizeof(a));
		memset(dMax, 0, sizeof(dMax));
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++)
		{
			int la, lb, lc, ld;
			scanf("%d %d %d %d", &la, &lb, &lc, &ld);
			a[0][la][lb] = lc;
			d[0][la][lb] = setdir(ld);
		}
		int cnt = 0;
		int ncnt = 0;
		for (int l = 0; l < m; l++)
		{
			ncnt = 1 - cnt;
			int ni, nj;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (a[cnt][i][j] > 0)
					{
						int dir = d[cnt][i][j];
						ni = i + dy[dir];
						nj = j + dx[dir];
						if (ni > 0 && nj > 0 && ni < n - 1 && nj < n - 1)
						{
							a[ncnt][ni][nj] += a[cnt][i][j];
							if (dMax[ncnt][ni][nj] < a[cnt][i][j])
							{
								dMax[ncnt][ni][nj] = a[cnt][i][j];
								d[ncnt][ni][nj] = d[cnt][i][j];
							}
						}
						else
						{
							a[ncnt][ni][nj] += a[cnt][i][j] / 2;
							if (dMax[ncnt][ni][nj] < a[cnt][i][j])
							{
								dMax[ncnt][ni][nj] = a[cnt][i][j];
								d[ncnt][ni][nj] = (d[cnt][i][j] + 2) % 4;
							}
						}
						dMax[cnt][i][j] = 0;
						a[cnt][i][j] = 0;
						d[cnt][i][j] = 0;
					}
				}
			}
			cnt = ncnt;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[cnt][i][j] > 0)
				{
					ans += a[cnt][i][j];
				}			
			}
		}
		if (z > 1)
		{
			printf("\n");
		}
		printf("#%d %d", z, ans);
	}
	return 0;
}