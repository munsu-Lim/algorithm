#include <cstdio>

long long d[91][2] = { 0 };
long long a[91] = { 0 };

int main()
{
	
	int n;
	d[1][1] = 1;
	a[1] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n ; i++)
	{
		d[i][0] = (d[i - 1][0] + d[i - 1][1]);
		d[i][1] = d[i - 1][0];
		a[i] = (d[i][0] + d[i][1]);
	}
	printf("%lld", a[n]);
	return 0;
}
