#include <cstdio>
#include <algorithm>

int t, n, a[16][16], d[16], c[16], ans, cnt1, cnt2;

void cal()
{
	int lsum1 = 0;
	int lsum2 = 0;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			int li = d[i];
			int lj = d[j];
			lsum1 += a[li][lj];
		}
	}
	for (int i = n / 2; i < n; i++)
	{
		for (int j = n / 2; j < n; j++)
		{
			int li = d[i];
			int lj = d[j];
			lsum2 += a[li][lj];
		}
	}
	if (ans > abs(lsum1 - lsum2))
	{
		ans = abs(lsum1 - lsum2);
	}
}
void getNum2(int depth, int num)
{
	if (num >= n/2)
	{
		cal();
		return;
	}
	if (ans <= 0 || depth >= n)
	{
		return;
	}
	if (c[depth] == 0)
	{
		c[depth] = 1;
		d[num + n/2] = depth;
		getNum2(depth + 1, num + 1);
		c[depth] = 0;
	}
	getNum2(depth + 1, num);
}

void getNum1(int depth, int num)
{
	if (num >= n / 2)
	{
//		getNum2(0, 0);
		cnt1++;
		return;
	}
	if (ans <= 0 || depth >= n)
	{
		return;
	}
	if (c[depth] == 0)
	{
		d[num] = depth;
		c[depth] = 1;
		getNum1(depth + 1, num + 1);
		c[depth] = 0;
	}
	getNum1(depth + 1, num);
}

void getNum(int depth)
{
	if (depth > n / 2)
	{
		cnt2++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (depth == 0) {
			c[i] = 1;
			d[depth] = i;
			getNum(depth + 1);
			c[i] = 0;
		}
		else {
			if (d[depth - 1] < i) {
				c[i] = 1;
				d[depth] = i;
				getNum(depth + 1);
				c[i] = 0;
			}
		}
	}
}

int main()
{
	n = 10;
	getNum1(0, 0);
	getNum(0);
	printf("%d %d", cnt1, cnt2);
	return 0;
}