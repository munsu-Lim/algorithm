#include <cstdio>
#include <cmath>

using namespace std;

int a[2][101], t, ans, m, an;
int dx[] = { 0, 0, 1, 0, -1 }, dy[] = { 0, -1, 0, 1, 0 };
int charge[4][9];

int main()
{
	scanf("%d", &t);
	for (int lt = 1; lt <= t; lt++)
	{
		scanf("%d %d", &m, &an);
		ans = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 1; i <= an; i++)
		{
			scanf("%d %d %d %d", &charge[0][i], &charge[1][i], &charge[2][i], &charge[3][i]);
		}
		int nx[2], ny[2];
		ny[0] = nx[0] = 1;
		ny[1] = nx[1] = 10;
		for (int j = 0; j <= m; j++)
		{
			int mPi[2][2] = { 0 };
			int mIn[2][2] = { 0 };
			for (int k = 0; k < 2; k++)
			{
				nx[k] += dx[a[k][j]];
				ny[k] += dy[a[k][j]];
				for (int i = 1; i <= an; i++)
				{
					int lx = charge[0][i];
					int ly = charge[1][i];
					int lcs = charge[2][i];
					int lpi = charge[3][i];
					if (abs(nx[k] - lx) + abs(ny[k] - ly) <= lcs)
					{

						if (lpi > mPi[k][1])
						{
							if (lpi > mPi[k][0])
							{
								mPi[k][1] = mPi[k][0];
								mIn[k][1] = mIn[k][1];
								mPi[k][0] = lpi;
								mIn[k][0] = i;
							}
							else
							{
								mPi[k][1] = lpi;
								mIn[k][1] = i;
							}
						}
					}
				}
			}
			if (mIn[0][0] == mIn[1][0])
			{
				if (mPi[0][1] > mPi[1][1])
				{
					ans += mPi[0][1];
					ans += mPi[1][0];
				}
				else
				{
					ans += mPi[0][0];
					ans += mPi[1][1];
				}
			}
			else
			{
				ans += mPi[0][0];
				ans += mPi[1][0];
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