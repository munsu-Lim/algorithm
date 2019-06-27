#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int d[101], ssize = 0;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0, size = commands.size(); i < size; i++)
	{
		for (int j = commands[i][0] - 1, cnt = 0; j < commands[i][1]; j++, cnt++)
		{
			d[cnt] = array[j];
		}
		ssize = commands[i][1] - commands[i][0] + 1;
		sort(d, d + ssize);
		answer.push_back(d[commands[i][2] - 1]);
	}
	return answer;
}

int main()
{
	vector<int> arra = { 1, 5, 2, 6, 3, 7, 4 };
	vector<int> result;
	vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
	result = solution(arra, commands);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}