#include <cstdio>
#include <vector>

using namespace std;
vector<int> a[20001];
int color[20001];

bool dfs(int node, int c)
{
	color[node] = c;
	for (int i = 0; i < a[node].size(); i++)
	{
		if (color[a[node][i]] == 0)
		{
			if (dfs(a[node][i], 3 - c) == false)
			{
				return false;
			}
		}
		else if (color[a[node][i]] == c)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int k, n, m, u, v;
	bool ans;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d %d", &n, &m);
		ans = true;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			color[i] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			if (color[i] == 0)
			{
				if (dfs(i, 1) == false)
				{
					ans = false;
					break;
				}
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}