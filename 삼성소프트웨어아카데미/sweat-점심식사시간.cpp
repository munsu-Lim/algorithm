#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int t, n, dt[2], di[2], dj[2], ans, dl[3];
vector<pair<int, int>> list;
vector<int> r[2], d[2], c;

void dfs(int index)
{
	if (index == list.size())
	{
		int cnt[2] = { 0, 0 };
		for (int i = 0; i < 2; i++)
		{
			int dsize = 0;
			for (int j = 0; j < r[i].size(); j++)
			{
				c.push_back(r[i][j] + 1);
			}
			sort(c.begin(), c.end());
			int lcnt = 0;
			int s[3] = { -dt[i], -dt[i], -dt[i] };
			for (int j = 0; j < c.size(); j++)
			{
				if (s[lcnt] + dt[i] <= c[j])
				{
					s[lcnt] = c[j];
				}
				else
				{
					s[lcnt] = s[lcnt] + dt[i];
				}
				cnt[i] = s[lcnt];
				lcnt = (lcnt + 1) % 3;
			}
			if (cnt[i] > 0)
			{
				cnt[i] += dt[i];
			}
			c.clear();
		}

		if (cnt[0] > cnt[1])
		{
			ans = min(cnt[0], ans);
		}
		else
		{
			ans = min(cnt[1], ans);
		}
		return;
	}
	r[0].push_back(abs(list[index].first - di[0]) + abs(list[index].second - dj[0]));
	dfs(index + 1);
	r[0].pop_back();

	r[1].push_back(abs(list[index].first - di[1]) + abs(list[index].second - dj[1]));
	dfs(index + 1);
	r[1].pop_back();
}

int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		list.clear();
		scanf("%d", &n);
		ans = 987987987;
		dt[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int a;
				scanf("%d", &a);
				if (a == 1)
				{
					list.push_back(make_pair(i, j));
				}
				else if (a > 1)
				{
					if (dt[0] == 0)
					{
						dt[0] = a;
						di[0] = i;
						dj[0] = j;
					}
					else
					{
						dt[1] = a;
						di[1] = i;
						dj[1] = j;
					}
				}
			}
		}
		dfs(0);
		if (z > 1)
		{
			printf("\n");
		}
		printf("#%d %d", z, ans);
	}
	return 0;
}
