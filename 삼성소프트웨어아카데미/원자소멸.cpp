#include <cstdio>

struct Some
{
	int i;
	int j;
	int dir;
	int e;
	int depth;
};

int t, n, ans, c[2][4001][4001], li, lj, ldir, le, ldepth;
int dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 };
int front;
int rear;
Some q1[1001];

void queueInit(void)
{
	front = 0;
	rear = 0;
}

int queueIsEmpty(void)
{
	return (front == rear);
}

int queueIsFull(void)
{
	if ((rear + 1) % 1001 == front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueEnqueue(Some value)
{
	if (queueIsFull())
	{
		printf("queue is full!");
		return 0;
	}
	q1[rear] = value;
	rear++;
	if (rear == 1001)
	{
		rear = 0;
	}

	return 1;
}

int queueDequeue(Some *value)
{
	if (queueIsEmpty())
	{
		printf("queue is empty!");
		return 0;
	}
	*value = q1[front];
	front++;
	if (front == 1001)
	{
		front = 0;
	}
	return 1;
}




int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d %d", &li, &lj, &ldir, &le);
			queueEnqueue({ li * 2, lj * 2, ldir, le, 0});
			c[0][(li * 2) + 2000][(lj * 2) + 2000] = le;
		}

		while (!queueIsEmpty())
		{
			Some a;
			queueDequeue(&a);
			li = a.i;
			lj = a.j;
			le = a.e;
			ldir = a.dir;
			ldepth = a.depth;
			int ncnt = (ldepth + 1) % 2;
			int ni = li + dx[ldir];
			int nj = lj + dy[ldir];
			if (c[ldepth % 2][li + 2000][lj + 2000] == le)
			{
				if (ni >= -2000 && ni <= 2000 && nj >= -2000 && nj <= 2000)
				{
					if (c[ncnt][ni + 2000][nj + 2000] == 0)
					{
						c[ncnt][ni + 2000][nj + 2000] = le;
						queueEnqueue({ ni, nj, ldir, le, ldepth + 1});
					}
					else
					{
						ans += le;
						c[ncnt][ni + 2000][nj + 2000]++;
					}
				}
			}
			else
			{
				ans += le;
			}
			c[ldepth % 2][li + 2000][lj + 2000] = 0;
		}
		if (z > 1)
		{
			printf("\n");
		}
		printf("#%d %d", z, ans);
	}
}