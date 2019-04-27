	#include <iostream>

using namespace std;

int ans, n, a[501][501], d[501][501];

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[j][i];
		}
	}
	d[1][1] = a[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				d[j][i] = d[j][i - 1] + a[j][i];
			}
			else
			{
				d[j][i] = max(d[j][i - 1], d[j - 1][i - 1]) + a[j][i];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans = max(d[i][n], ans);
	}
	cout << ans;
}