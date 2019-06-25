#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int d[2000];
int timeSet[] = {600,60, 10, 1};

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int st = 9 * 60;
	int lt = t;
	bool isEmtpy = true;
	int lastCnt = 0;
	int tn = timetable.size();
	sort(timetable.begin(), timetable.end());
	for (int i = 0; i < tn; i++)
	{
		d[i] = 0;
		for (int j = 0, cnt = 0; j < 5; j++)
		{
			if (j != 2)
			{
				d[i] += (timetable[i][j] - '0') * timeSet[cnt];
				cnt++;
			}
		}
	}
	for (int i = 0, cnt = 0; i < n; i++)
	{
		int lm = 0;
		int llt = st + lt * i;
		for (int j = cnt; j < tn; j++)
		{
			isEmtpy = true;
			if (llt < d[j])
			{
				break;
			}
			lm++;
			cnt++;
			if (lm >= m)
			{
				isEmtpy = false;
				lastCnt = cnt - 1;
				break;
			}
		}
 	}
	int anstime = 0;
	if (isEmtpy)
	{
		anstime = st + lt * (n - 1);
	}
	else 
	{
		anstime = d[lastCnt] - 1;
	}

	for (int k = 0; k < 4; k++)
	{
		if (k == 2)
		{
			answer += ':';
		}
		int ltt = anstime / timeSet[k];
		answer += to_string(ltt);
		if (ltt > 0)
		{
			anstime -= ltt * timeSet[k];
		}

	}
	return answer;
}


int main()
{
	vector<string> test = { "09:10", "09:09", "08:00" };
	cout << solution(2, 10, 2, test);
}