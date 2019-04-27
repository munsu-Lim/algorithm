#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int t, n, m, ans, kc[50];
vector <pair <int, int>> v;

int main()
{
	scanf("%d", &t);
	for (int i = 1; i < 50; i++)
	{
		kc[i] = i * i + (i - 1) * (i - 1);
	}
	for (int lt = 1; lt <= t; lt++)
	{
		ans = 0;
		v.clear();
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int lnum;
				scanf("%d", &lnum);
				if (lnum)
				{
					v.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (ans >= v.size())
			{
				break;
			}
			for (int j = 1; j <= n; j++)
			{
				if (ans >= v.size())
				{
					break;
				}
				for (int k = 1; k < 50; k++)
				{
					int count = 0;
					for (int l = 0; l < v.size(); l++)
					{
						int li = v[l].first;
						int lj = v[l].second;
						if ((abs(i - li) + abs(j - lj)) < k)
						{
							count++;
						}
					}
					if (m * count >= kc[k])
					{
						if (ans < count)
						{
							ans = count;
						}
					}
					if (count >= v.size())
					{
						break;
					}
				}
			}
		}
		if (lt > 1)
		{
			printf("\n");
		}
		printf("#%d %d", lt, ans);

	}
}