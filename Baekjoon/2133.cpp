#include <cstdio>

int d[31] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);
	d[0] = 1;
	d[2] = 3;
	for (int i = 4; i <= n; i++)
	{
		d[i] = d[i - 2] * 3;
		for (int j = 2; 2 * j <= i; j++)
		{
			d[i] += d[i - 2 * j] * 2;
		}
	}
	printf("%d", d[n]);
	return 0;
}