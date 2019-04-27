#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int a[51][51], d[13][100],  n, m, dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 }, c[100], ans;
vector <pair<int, int>> ch, h;
vector <int> list, alist;

void cal()
{
	int lans = 0;
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 0; j < h.size(); j++)
		{
			if (c[j] > d[list[i]][j])
			{
				c[j] = d[list[i]][j];
			}
		}
	}
	for (int i = 0; i < h.size(); i++)
	{
		lans += c[i];
		c[i] = 987987987;
	}
	alist.push_back(lans);
}

void find(int cnt, int num)
{
	if (list.size() == m)
	{
		cal();
		return;
	}
	if (cnt > ch.size() - 1 || list.size() > m)
	{
		return;
	}
	list.push_back(cnt);
	find(cnt + 1, num + 1);
	list.pop_back();
	find(cnt + 1, num);
}

int main()
{
	ans = 987987987;
	scanf("%d %d", &n, &m);
	memset(c, 987987987, sizeof(c));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 2)
			{
				ch.push_back(make_pair(i, j));
			}
			else if (a[i][j] == 1)
			{
				h.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < ch.size(); i++)
	{
		for (int j = 0; j < h.size(); j++)
		{
			d[i][j] = abs(ch[i].first - h[j].first) + abs(ch[i].second - h[j].second);
		}
	}

	find(0, 0);
	for (int i = 0; i < alist.size(); i++)
	{
		if (ans > alist[i])
		{
			ans = alist[i];
		}
	}
	printf("%d", ans);
}