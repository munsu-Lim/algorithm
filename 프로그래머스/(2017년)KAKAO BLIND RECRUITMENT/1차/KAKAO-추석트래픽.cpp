#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair <double, double>> list;

double time[] = { 36000.0, 3600.0, 600.0, 60.0, 10.0, 1.0, 0.1, 0.01, 0.001 };

int solution(vector<string> lines) {
	int answer = 0;
	for (int k = 0; k < lines.size(); k++)
	{
		double st = 0.0;
		double et = 0.0;
		for (int i = 11, cnt = 0; i < 23; i++)
		{
			if ('0' <= lines[k][i] && lines[k][i] <= '9')
			{
				et += (lines[k][i] - '0') * time[cnt];
				cnt++;
			}
		}
		for (int i = 24, cnt = 5; i < lines[k].length(); i++)
		{
			if ('0' <= lines[k][i] && lines[k][i] <= '9')
			{
				st += (lines[k][i] - '0') * time[cnt];
				cnt++;
			}
		}
		list.push_back(make_pair(et, et - st));
	}
	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++)
	{
		int num = 1;
		double eTime = list[i].first + 0.999;
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list[j].second < eTime)
			{
				num++;
			}
		}
		if (num > answer)
		{
			answer = num;
		}
	}

	return answer;
}

int main()
{
	vector<string> test = { "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" };
	cout << solution(test);
}