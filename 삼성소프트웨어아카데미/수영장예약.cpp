#include <cstdio>
#include <algorithm>

using namespace std;

int t, ans, p[3], a[13];

void dfs(int y, int price)
{
	if(y > 12)
	{
		ans = min(ans, price);
		return;
	}
	if (a[y] > 0)
	{
		dfs(y + 1, price + a[y] * p[0]);
		dfs(y + 1, price + p[1]);
		dfs(y + 3, price + p[2]);
	}
	else
	{
		dfs(y + 1, price);
	}
}

int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &p[i]);
		}
		scanf("%d", &ans);
		for (int i = 1; i <= 12; i++)
		{
			scanf("%d", &a[i]);
		}
		dfs(1, 0);
		if (z > 1)
		{
			printf("\n");
		}
		printf("#%d %d", z, ans);
	}
}