#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct man {
	int k;
	int i;
	int t;
};

int t, n, m, k, fa, fb, a[21], b[21], ak[21], bk[21], at[1001], bt[1001], cur, ans;
vector <man> list;
bool cmp(man a, man b)
{
	if (a.t < b.t)
	{
		return true;
	}
	else if (a.t == b.t)
	{
		if (a.i < b.i)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d", &t);
	for (int lt = 1; lt <= t; lt++)
	{
		list.clear();
		ans = 0;
		scanf("%d %d %d %d %d", &n, &m, &k, &fa, &fb);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			ak[i] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &b[i]);
			bk[i] = 0;
		}
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &cur);
			int lmin = 987987987;
			int lindex = 0;
			for (int j = 1; j <= n; j++)
			{
				if (ak[j] < lmin)
				{
					lmin = ak[j];
					lindex = j;
					if (lmin <= cur)
					{
						break;
					}
				}
			}
			if (lmin > cur)
			{
				cur = lmin;
			}
			ak[lindex] = cur + a[lindex];
			list.push_back({ i, lindex,cur + a[lindex] });
			at[i] = lindex;
		}
		sort(list.begin(), list.end(), cmp);
		for (int i = 0; i < k; i++)
		{
			cur = list[i].t;
			int lmin = 987987987;
			int lindex = 0;
			for (int j = 1; j <= m; j++)
			{
				if (bk[j] < lmin)
				{
					lmin = bk[j];
					lindex = j;
					if (lmin <= cur)
					{
						break;
					}
				}
			}
			if (lmin > cur)
			{
				cur = lmin;
			}
			bk[lindex] = cur + b[lindex];
			bt[list[i].k] = lindex;
		}
		for (int i = 1; i <= k; i++)
		{
			if (at[i] == fa && bt[i] == fb)
			{
				ans += i;
			}
		}
		if (ans == 0)
		{
			ans = -1;
		}
		if (lt > 1)
		{
			printf("\n");
		}
		printf("#%d %d", lt, ans);
	}
}