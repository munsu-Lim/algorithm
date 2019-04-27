#include <cstdio>

int n, m, a[51][51], c[51][51], ci, cj, cd, ans;
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
bool bFind = false;

int turnLeft(int dir)
{
	int ldir = dir - 1;
	if (ldir >= 0)
	{
		return ldir;
	}
	return 3;
}
int turnback(int dir)
{
	return (dir + 2) % 4;
}

void Action(int i, int j, int dir, int cnt)
{
	int nDir, ni, nj;
	if (bFind)
	{
		return;
	}
	if (cnt >= 4)
	{
		nDir = turnback(dir);
		ni = i + dy[nDir];
		nj = j + dx[nDir];
		if (ni > 0 && nj > 0 && ni <= n && nj <= m && a[ni][nj] == 0)
		{
			Action(ni, nj, dir, 0);
		}
		else
		{
			bFind = true;
			return;
		}
	}
	if (c[i][j] == 0)
	{
		c[i][j] = ++ans;
	}
	nDir = turnLeft(dir);
	ni = i + dy[nDir];
	nj = j + dx[nDir];
	if (ni > 0 && nj > 0 && ni <= n && nj <= m && c[ni][nj] == 0 && a[ni][nj] == 0)
	{
		Action(ni, nj, nDir, 0);
	}
	Action(i, j, nDir, cnt + 1);
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &ci, &cj, &cd);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	Action(ci + 1, cj + 1, cd, 0);
	printf("%d", ans);
	return 0;
}