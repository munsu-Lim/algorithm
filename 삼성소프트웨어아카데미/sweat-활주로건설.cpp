#include <cstdio>

int t, n, x, a[21][21], pnum, pcount, ans;
bool bPre, bNext;
int main()
{
	scanf("%d", &t);
	for (int lt = 1; lt <= t; lt++)
	{
		scanf("%d %d", &n, &x);
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			pnum = a[i][1];
			pcount = 1;
			bNext = false;
			for (int j = 2; j <= n; j++)
			{
				if (pnum == a[i][j])
				{
					pcount++;
					if (bNext && pcount >= x)
					{
						pcount -= x;
						bNext = false;
					}
				}
				else
				{
					if (pnum < a[i][j])
					{
						if (pcount < x || bNext)
						{
							break;
						}
					}
					else
					{
						if (bNext)
						{
							break;
						}
						bNext = true;
					}
					pnum = a[i][j];
					pcount = 1;
				}
				if (j == n && !bNext)
				{
					ans++;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			pnum = a[1][i];
			pcount = 1;
			bNext = false;
			for (int j = 2; j <= n; j++)
			{
				if (pnum == a[j][i])
				{
					pcount++;
					if (bNext && pcount >= x)
					{
						pcount -= x;
						bNext = false;
					}
				}
				else
				{
					if (pnum < a[j][i])
					{
						if (pcount < x || bNext || a[j][i] - pnum > 1)
						{
							break;
						}
					}
					else
					{
						if (bNext || pnum - a[j][i] > 1)
						{
							break;
						}
						bNext = true;
					}
					pnum = a[j][i];
					pcount = 1;
				}
				if (j == n && !bNext)
				{
					ans++;
				}
			}
		}
		printf("#%d %d\n", lt, ans);
	}
	return 0;
}