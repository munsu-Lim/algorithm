#include <cstdio>
#include <cstring>

int main()
{
	char c[51];
	int d = 0, t = 0;
	bool bMinus = false;
	scanf("%s", &c);
	for(unsigned int i = 0; i < strlen(c); i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			t *= 10;
			t += bMinus ? -(c[i] - '0') : c[i] - '0';
		}
		else 
		{
			d += t;
			t = 0;
			if (c[i] == '-')
			{
				bMinus = true;
			}
		}
	}
	d += t;
	printf("%d", d);
	scanf("%d", &t);
	return 0;
}