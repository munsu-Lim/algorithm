#include <cstdio>

long long d1[33][33],d2[33][33],d3[33][33], n, a[33][33], ans;

int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%lld", &a[i][j]);
		}
	}
	d1[1][2] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == 0)
			{
				if (a[i][j - 1] == 0)
				{
					d1[i][j] += d1[i][j - 1];
					d1[i][j] += d3[i][j - 1];
				}
				if (a[i - 1][j] == 0)
				{
					d2[i][j] += d2[i - 1][j];
					d2[i][j] += d3[i - 1][j];
				}
				if (a[i - 1][j] == 0 && a[i][j - 1] == 0)
				{
					d3[i][j] += d1[i - 1][j - 1];
					d3[i][j] += d2[i - 1][j - 1];
					d3[i][j] += d3[i - 1][j - 1];
				}
			}
		}
	}
	ans = d1[n][n] + d2[n][n] + d3[n][n];
	printf("%lld", ans);
}