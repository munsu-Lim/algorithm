#include <cstdio>

int main()
{
	int n, m, k;
	long long ans = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &k);
	while (k--)
	{
		if (n == 0 || m == 0)
		{
			break;
		}
		if (m * 2 < n)
		{
			n--;
		}
		else
		{
			m--;
		}
	}
	if (k == -1)
	{
		if (n == 0 || m == 0)
		{
			ans = 0;
		}
		else if (m * 2 < n)
		{
			ans = m;
		}
		else
		{
			ans = n / 2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}