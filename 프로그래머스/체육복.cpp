#include <string>
#include <vector>

using namespace std;

int d[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		d[i] = 1;
	}
	for (int i = 0, size = lost.size(); i < size; i++)
	{
		d[lost[i]] -= 1;
	}
	for (int i = 0, size = reserve.size(); i < size; i++)
	{
		d[reserve[i]] += 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] < 1 && d[i - 1] > 1)
		{
			d[i - 1] = 1;
			d[i] = 1;
		}
		else if (d[i] < 1 && d[i + 1] > 1)
		{
			d[i + 1] = 1;
			d[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] >= 1)
		{
			answer++;
		}
	}
	return answer;
}

int main()
{
	int n = 5;
	vector<int> lost = { 2, 4 };
	vector<int> reserve = { 1, 3, 5 };
	solution(n, lost, reserve);
}