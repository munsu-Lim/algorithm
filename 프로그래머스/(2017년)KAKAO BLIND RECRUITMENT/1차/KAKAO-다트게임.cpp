#include <iostream>
#include <string>

using namespace std;

int score[3], cnt, num;
bool Bchange = false;

void write()
{
	score[cnt] = num;
	num = 0;
	cnt++;
	Bchange = false;
}

int solution(string dartResult) {
	int answer = 0;
	for (int i = 0, size = dartResult.length(); i < size; i++)
	{
		int cur = dartResult[i];
		if (cur >= '0' && cur <= '9')
		{
			if (Bchange) write();
			num = num * 10 + (cur - '0');
		}
		else
		{
			Bchange = true;
			if (cur == 'D') num *= num;
			else if (cur == 'T') num = num * num * num;
			else if (cur == '*')
			{
				num *= 2;
				if (cnt > 0)
				{
					score[cnt - 1] *= 2;
				}
			}
			else if (cur == '#') num = -num;
		}
	}
	write();
	answer = score[0] + score[1] + score[2];
	return answer;
}

int main()
{
	string test = "1D2S#10S";
	cout << solution(test);
}