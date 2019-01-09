#include <cstdio>

int d[11] = { 0 };

int main()
{
	int n;
	int t;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	scanf("%d", &t);
	for (int j = 0; j < t; j++)
	{
		scanf("%d", &n);
		
		for (int i = 4; i <= n; i++)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		printf("%d\n", d[n]);
	}
	return 0;
}