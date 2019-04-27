#include <cstdio>
#define MAX(a,b) (a > b) ? a : b 

int main()
{
	int arr[1001];
	int d[1001][2];
	int ans = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		d[i][0] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				d[i][0] = MAX(d[i][0], d[j][0] + 1);
			}
		}
	}
	for (int i = n; i >= 1; i--)
	{
		d[i][1] = 1;
		for (int k = n; k > i; k--)
		{
			if (arr[i] > arr[k])
			{
				d[i][1] = MAX(d[i][1], d[k][1] + 1);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans = MAX(ans, d[i][0] + d[i][1] - 1);
	}
	printf("%d", ans);
	return 0;
}