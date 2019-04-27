#include <cstdio>

int d[101][10] = { 0 };
int a[101] = { 0 };

int main()
{
	int n;
	a[1] = 9;
	scanf("%d", &n);
	for (int i = 1; i < 10; i++)
	{
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				d[i][j] = d[i - 1][1];
			}
			else if (j == 9)
			{
				d[i][j] = d[i - 1][8];
			}
			else
			{
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
			}
			a[i] = (a[i] + d[i][j]) % 1000000000;
		}
	}
	printf("%d", a[n] % 1000000000);
	return 0;
}