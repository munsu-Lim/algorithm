#include <iostream>

using namespace std;

int maxnum ,n, a[501][501], d[501][501], dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

void clear()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[j][i] = 0;
		}
	}
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

void s(int i, int j, int l)
{
	if (d[i][j] < l)
	{
		d[i][j] = l;
		maxnum = max(l, maxnum);
		for (int k = 0; k < 4; k++)
		{
			int ni = i + dx[k];
			int nj = j + dy[k];
			if (ni > 0 && ni <= n && nj > 0 && nj <= n && a[i][j] < a[ni][nj] && d[ni][nj] < d[i][j] + 1)
			{
				s(ni, nj, l + 1);
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j][i];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(d[i][j] == 0)
			{ 
				s(i, j, 1);
			}
		}
	}
	cout << maxnum <<endl;
}