using namespace std;

int d[1000001];

int solution(int n) {
	int answer = 0;
	for (int i = 2; i <= n; i++)
	{
		if (d[i] == 0)
		{
			answer++;
			for (int j = 2; i * j <= n; j++)
			{
				d[i * j] = 1;
			}
		}
	}
	return answer;
}