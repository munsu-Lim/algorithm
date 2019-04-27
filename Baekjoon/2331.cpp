#include <cstdio>
#include <vector>

using namespace std;

int check[1000000];

int pow(int n, int p)
{
	int res = 0;
	while (n > 0)
	{
		int a = n % 10;
		for (int i = 0; i < p; i++)
		{
			a *= a;
		}
		res += a;
		n /= 10;
	}
	return res;
}

int dfs(int node,int p, int cnt)
{
	int res = cnt;
	check[node] = cnt;
	int next = pow(node, p);
	if (check[next] != 0)
	{
		return res;
	}
	return dfs(next, p, cnt + 1);
}

int main()
{
	int n, p;
	scanf("%d %d", &n, &p);
	printf("%d\n",dfs(n, p, 0) - 1);
	return 0;
}