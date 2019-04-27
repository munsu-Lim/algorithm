#include <cstdio>
#define MAX(a,b) (a > b) ? a : b 

int main()
{
	int arr[1001];
	int d[1001][2] = { 0 };
	int ans = 1;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	d[1][0] = 0;
	d[1][1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		d[i][1] = arr[i];
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j])
			{
				d[i][1] = MAX(d[i][1], d[j][1] + arr[i]);
			}
		}
		d[i][0] = MAX(d[i - 1][0], d[i - 1][1]);
	}
	ans = MAX(d[n][0], d[n][1]);
	printf("%d", ans);
	return 0;
}