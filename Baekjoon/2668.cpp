#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[101], ans, cnt, ln, n, d[101];
vector <int> lv, av;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (lv.size() > 0)
		{
			lv.clear();
		}
		if (d[i] != -1)
		{
			lv.push_back(i);
			int next = arr[i];
			while (d[next] != -1 && d[next] != i)
			{
				if (next == i)
				{
					for (int j = 0; j < lv.size(); j++)
					{
						d[lv[j]] = -1;
						av.push_back(lv[j]);
					}
					ans += lv.size();
					break;
				}
				d[next] = i;
				lv.push_back(next);
				next = arr[next];
			}
		}
	}
	sort(av.begin(), av.end());
	cout << ans;
	for (int i = 0; i < av.size(); i++)
	{
		cout << "\n" << av[i];
	}
	return 0;
}