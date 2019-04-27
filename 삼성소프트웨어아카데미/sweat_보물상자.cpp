#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int t, n, k, a[28];
map <int, int> m;
vector <int> v;

int main()
{
	scanf("%d", &t);
	for (int time = 1; time <= t; time++)
	{
		scanf("%d %d", &n, &k);
		v.clear();
		m.clear();
		getchar();
		for (int i = 0; i < n; i++)
		{
			scanf("%1x", &a[i]);
		}

		int lsize = n / 4;
		for (int i = 0; i < lsize; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				int mul = pow(16, lsize - 1);
				int lsum = 0;
				for (int j = 0; j < lsize; j++)
				{
					int now = j + k * lsize;
					lsum += a[now] * mul;
					mul /= 16;
				}
				if (m[lsum] == 0)
				{
					m[lsum] = 1;
					v.push_back(lsum);
				}
			}
			int temp = a[0];
			for (int j = 0; j < n; j++)
			{
				int ltemp = a[(j + 1) % n];
				a[(j + 1) % n] = temp;
				temp = ltemp;
			}
		}
		if (time > 1)
		{
			printf("\n");
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		printf("#%d %d ", time, v[k - 1]);
	}
	return 0;
}