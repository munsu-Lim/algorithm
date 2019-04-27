#include <cstdio>

int a[51];

int main() {
	int n, s;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &s);
	for (int i = 0; i < n && s > 0; i++)
	{
		int index = 0, max = -1; 
		for (int j = i; j < n && j <= s + i; j++) {
			if (max < a[j]) 
			{ 
				max = a[j]; 
				index = j; 
			}
		}
		for (int j = index; j > i && s; j--) 
		{ 
			int temp;
			temp = a[j];
			a[j] = a[j - 1]; 
			a[j - 1] = temp;
			s--; 
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	scanf("%d", &n);
}
