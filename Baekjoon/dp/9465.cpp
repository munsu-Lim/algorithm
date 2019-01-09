#include <cstdio>

long long d[3][100001] = { 0 };
long long max(long long i, long long j);

int main()
{
	int a[2][100001] = { 0 };
	int t;
	int n;
	long long ans;
	scanf("%d", &t);
	for (int j = 0; j < t; j++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[0][i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[1][i]);
		}
		for (int i = 1; i <= n; i++)
		{
			d[0][i] = max(d[0][i - 1], max(d[1][i - 1], d[2][i - 1]));
			d[1][i] = max(d[0][i - 1], d[2][i - 1]) + a[0][i];
			d[2][i] = max(d[0][i - 1], d[1][i - 1]) + a[1][i];
		}
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = max(max(ans, d[0][i]), max(d[1][i], d[2][i]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}

long long max(long long i, long long j)
{
	if (i >= j)
	{
		return i;
	}
	else
	{
		return j;
	}
}