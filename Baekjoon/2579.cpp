#include <cstdio>
#include <algorithm>

using namespace std;

long long d[301][2];
int a[301];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	d[0][0] = 0;
	d[0][1] = 0;
	d[1][0] = a[1];
	d[1][1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = max(d[i - 2][0], d[i - 2][1]) + a[i];
		d[i][1] = d[i - 1][0] + a[i];
	}
	printf("%lld", max(d[n][0], d[n][1]));
}