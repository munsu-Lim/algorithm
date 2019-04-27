#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[101], s, c[101], d[101];
vector <int> list;
vector <int> v;

void dfs(int i, int s, int depth)
{
	v.push_back(i);
	c[i] = s;
	d[i] = depth;
	int next = a[i];
	if (c[next] == 0)
	{
		dfs(next, s, depth + 1);
	}
	else if (c[next] == s)
	{
		for (int k = d[next]; k < v.size(); k++)
		{
			list.push_back(v[k]);
		}
	}
}

int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 0)
		{
			s++;
			dfs(i, s, 0);
			v.clear();
		}
	}
	sort(list.begin(), list.end());
	printf("%d\n", list.size());
	for (int i = 0; i < list.size(); i++)
	{
		printf("%d ", list[i]);
	}
	return 0;
}