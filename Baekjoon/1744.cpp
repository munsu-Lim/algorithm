#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, arr[10000];
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i += 2) {
		if (arr[i] >= 0)
		{
			break;
		}
		if (i + 1 < n && arr[i + 1] <= 0)
		{
			ans += arr[i] * arr[i + 1];
		}
		else
		{
			ans += arr[i];
		}
	}

	for (int i = n - 1; i >= 0; i -= 2) {
		if (arr[i] <= 0)
		{
			break;
		}
		if (i - 1 >= 0 && arr[i - 1] >= 1)
		{
			ans += arr[i] * arr[i - 1];
			if (arr[i - 1] == 1) i++;
		}
		else
		{
			ans += arr[i];
		}
	}
	printf("%lld\n", ans);
	scanf("%d", &arr[0]);
	return 0;
}