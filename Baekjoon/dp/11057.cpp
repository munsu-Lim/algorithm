#include <cstdio>

int d[1001][10] = { 0 };
int a[1001] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
	{
		d[1][i] = 1;
	}
	a[1] = 10;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				d[i][j] = (d[i][j] + d[i - 1][k]) % 10007;
			}
			a[i] = (a[i] + d[i][j]) % 10007;
		}
	}
	printf("%d", a[n]);
	return 0;
}