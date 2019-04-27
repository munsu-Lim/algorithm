#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[12],c[4], minA = 1587987987, maxA = -1587987987;

void cal(int num, int depth)
{
	if (depth >= n - 1)
	{
		minA = min(minA, num);
		maxA = max(maxA, num);
		return;
	}
	if (c[0] > 0)
	{
		c[0]--;
		cal(num + a[depth + 1], depth + 1);
		c[0]++;
	}
	if (c[1] > 0)
	{
		c[1]--;
		cal(num - a[depth + 1], depth + 1);
		c[1]++;
	}
	if (c[2] > 0)
	{
		c[2]--;
		cal(num * a[depth + 1], depth + 1);
		c[2]++;
	}
	if (c[3] > 0)
	{
		c[3]--;
		cal(num / a[depth + 1], depth + 1);
		c[3]++;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &c[i]);
	}
	cal(a[0], 0);
	printf("%d\n%d", maxA, minA);
	return 0;
}