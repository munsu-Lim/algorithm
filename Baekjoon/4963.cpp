#include <cstdio>

bool a[51][51];
bool d[51][51];
int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int row, col;

void dfs(int x, int y)
{
	d[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= row && ny <= col)
		{
			if (d[nx][ny] == false && a[nx][ny] == true)
			{
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	while (true)
	{
		int cnt = 0;
		scanf("%d %d", &col, &row);
		if (row == 0 && col == 0)
		{
			break;
		}
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				scanf("%1d", &a[i][j]);
				d[i][j] = false;
			}
		}
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if ( d[i][j] == false && a[i][j] == true)
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}