#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int n, s, a[200];
	scanf("%d %d", &n, &s);
	s--;
	for (int i = 1; i <= n; i++)
	{
		int k = 0;
		for (int j = 1; j <= n - i; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= i * 2 - 1; j++)
		{
			a[j] = s % 9 + 1;
			s++;
			k++;
		}
		if (i != 1 && i % 2 == 1)
		{
			for (int j = k; j >= 1; j--)
			{
				printf("%d", a[j]);
			}
		}
		else
		{
			for (int j = 1; j <= k; j++)
			{
				printf("%d", a[j]);
			}
		}
		printf("\n");
	}
	return 0;
}