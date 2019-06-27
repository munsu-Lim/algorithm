#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	int imax = participant.size();
	int jmax = completion.size();
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < jmax; i++)
	{
		if (participant[i] != completion[i])
		{
			return participant[i];
		}
	}
	return participant[imax - 1];
}

int main()
{
	vector<string> participant = { "leo", "kiki", "eden" };
	vector<string> completion = { "eden", "kiki" };
	cout <<solution(participant, completion);
}