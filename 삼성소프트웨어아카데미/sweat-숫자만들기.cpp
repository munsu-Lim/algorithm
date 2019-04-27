#include <cstdio>

int t, a[4], n, max, min, arr[13];

void find(int depth, int num)
{
	if (depth >= n)
	{
		if (max < num)
		{
		 max = num;
		}
		if (min > num)
		{
		 min = num;
		}
		return;
	}
	if (a[0] > 0)
	{
		a[0]--;
		find(depth + 1, num + arr[depth + 1]);
		a[0]++;
	}
	if (a[1] > 0)
	{
		a[1]--;
		find(depth + 1, num - arr[depth + 1]);
		a[1]++;
	}
	if (a[2] > 0)
	{
		a[2]--;
		find(depth + 1, num * arr[depth + 1]);
		a[2]++;
	}
	if (a[3] > 0)
	{
		a[3]--;
		find(depth + 1, num / arr[depth + 1]);
		a[3]++;
	}
}

int main()
{
	scanf("%d", &t);
	for (int lt = 1; lt <= t; lt++)
	{
		max = -1000000001;
		min = 1000000001;
		scanf("%d", &n);
		for (int i = 0; i < 4; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}
		find(1, arr[1]);
		if (lt > 1)
		{
			printf("\n");
		}
		printf("#%d %d", lt, max - min);
	}
	return 0;
}