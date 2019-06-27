#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a1[5] = { 1,2,3,4,5 }, a2[8] = { 2,1,2,3,2,4,2,5 }, a3[10] = { 3,3,1,1,2,2,4,4,5,5 };
int score[3], maxN = 0;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	for (int i = 0, size = answers.size(); i < size; i++)
	{
		int cur = answers[i];
		if (a1[i % 5] == cur) score[0]++;
		if (a2[i % 8] == cur) score[1]++;
		if (a3[i % 10] == cur) score[2]++;
	}
	for (int i = 0; i < 3; i++)
	{
		if (maxN < score[i]) maxN = score[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (maxN == score[i]) answer.push_back(i + 1);
	}
	return answer;
}

int main()
{
	vector<int> answers = { 1,2,3,4,5 };
	solution(answers);
}