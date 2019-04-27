#include <cstdio>

int t, d, w, k, a[14][21], c[14], ans;

void solve(int depth, int num)
{
	if (num > ans)
	{
		return;
	}
	if (depth > d)
	{
		for (int i = 1; i <= w; i++)
		{
			int pn = a[1][i];
			if (c[1] != 0)
			{
				pn = c[1] - 1;
			}
			int pcount = 1;
			for (int j = 2; j <= d; j++)
			{
				int cn = a[j][i];
				if (c[j] != 0)
				{
					cn = c[j] - 1;
				}
				if (pn == cn)
				{
					pcount++;
				}
				else
				{
					if (pcount >= k)
					{
						break;
					}
					pn = cn;
					pcount = 1;
				}
				if (pcount >= k)
				{
					break;
				}
			}
			if (pcount < k)
			{
				return;
			}
		}
		if (ans > num)
		{
			ans = num;
		}
		return;
	}
	c[depth] = 0;
	solve(depth + 1, num);
	c[depth] = 1;
	solve(depth + 1, num + 1);
	c[depth] = 2;
	solve(depth + 1, num + 1);
	c[depth] = 0;
}

int main()
{
	scanf("%d", &t);
	for (int lt = 1; lt <= t; lt++)
	{
		scanf("%d %d %d", &d, &w, &k);
		ans = k;
		for (int i = 1; i <= d; i++)
		{
			c[i] = 0;
			for (int j = 1; j <= w; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		solve(1, 0);
		if (lt > 1)
		{
			printf("\n");
		}
		printf("#%d %d", lt, ans);
	}
	return 0;
}