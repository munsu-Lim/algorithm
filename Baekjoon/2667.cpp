#include <cstdio>
#include <algorithm>
#include <vector>

bool a[26][26];
int d[26][26];
int n;
int di[] = { 1,-1,0,0 };
int dj[] = { 0,0,-1,1 };
int ans[25 * 25];

int dfs(int i,int j, int cnt, int k)
{
	d[i][j] = cnt;
	for (int l = 0; l < 4; l++)
	{
		int ni = i + di[l];
		int nj = j + dj[l];
		if (ni >= 1 && ni <= n && nj >= 1 && nj <= n)
		{
			if (a[ni][nj] == true && d[ni][nj] == false)
			{
				k = dfs(ni, nj, cnt, k + 1);
			}
		}
	}
	return k;
}

int main()
{
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == true && d[i][j] == false)
			{
				cnt++;
				ans[cnt] = dfs(i, j, cnt, 1);
			}
		}
	}
	printf("%d\n", cnt);
	std::sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}