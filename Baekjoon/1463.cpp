#include <cstdio>

int d[1000001] = { 0 };
int min(int a, int b, int c);

int main()
{
	int n;
	scanf("%d", &n);
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		int a = 1000001, b = 100001, c = 100001;
		if (i % 3 == 0)
		{
			a = d[i / 3] + 1;
		}
		if (i % 2 == 0)
		{
			b = d[i / 2] + 1;
		}
		c = d[i - 1] + 1;
		d[i] = min(a, b, c);

	}
	printf("%d", d[n]);
	return 0;
}

int min(int a, int b, int c)
{
	if (a <= b && a <= c)
	{
		return a;
	}
	else if (b <= c)
	{
		return b;
	}
	else
	{
		return c;
	}
}