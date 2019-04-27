#include <cstdio>
#define MAX(a, b) (a > b) ? a : b

long long d[100001];
int a[100001];

int main()
{
	int n;
	long long ans;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	d[1] = a[1];
	ans = d[1];
	for (int i = 2; i <= n; i++)
	{
		d[i] = MAX(d[i - 1] + a[i], a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		ans = MAX(ans, d[i]);
	}
	printf("%lld", ans);
	scanf("%lld", ans);
	return 0;
}