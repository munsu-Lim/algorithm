#include <cstdio>

int t, k, a[4][8], c[4], s[4] = { 1, 2, 4, 8 }, ans;

void turn(int dir, int num)
{
	if (dir == 1)
	{
		int pre = a[num][7];
		int cur;
		for (int i = 0; i < 8; i++)
		{
			cur = pre;
			pre = a[num][i];
			a[num][i] = cur;
		}
	}
	else
	{
		int pre = a[num][0];
		int cur;
		for (int i = 7; i >= 0; i--)
		{
			cur = pre;
			pre = a[num][i];
			a[num][i] = cur;
		}
	}
}
void move(int dir, int num)
{
	c[num] = 1;
	int lleft = a[num][6];
	int lright = a[num][2];

	turn(dir, num);
	if (num > 0)
	{
		if (c[num - 1] == 0 && a[num - 1][2] != lleft)
		{
			move(-dir, num - 1);
		}
	}
	if (num < 3)
	{
		if (c[num + 1] == 0 && a[num + 1][6] != lright)
		{
			move(-dir, num + 1);
		}
	}
}

int main()
{
	scanf("%d", &t);
	for (int lt = 1; lt <= t; lt++)
	{
		ans = 0;
		scanf("%d", &k);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				c[j] = 0;
			}
			int ld, lnum;
			scanf("%d %d", &lnum, &ld);
			move(ld, lnum - 1);
		}

		for (int i = 0; i < 4; i++)
		{
			if (a[i][0])
			{
				ans += s[i];
			}
		}
		if (lt > 1)
		{
			printf("\n");
		}
		printf("#%d %d", lt, ans);
	}
	return 0;
}