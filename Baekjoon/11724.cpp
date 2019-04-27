#include <iostream>
#include <vector>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node)
{
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++)
	{
		if (check[a[node][i]] == false)
		{
			dfs(a[node][i]);
		}
	}
}

int main() {
	int n, m, u, v, ans;
	ans = 0;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false) 
		{
			dfs(i);
			ans += 1;
		}
	}
	printf("%d", ans);
	return 0;
}