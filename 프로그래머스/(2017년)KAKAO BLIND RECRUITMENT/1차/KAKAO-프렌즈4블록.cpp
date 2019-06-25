#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[] = { 0, 1, 0, 1 };
int dy[] = { 0, 0, 1, 1 };
vector <pair<int, int>> v;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	while(1)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i + 1 < m && j + 1 < n)
				{
					for (int k = 0; k < 4; k++)
					{
						int li = i + dy[k];
						int lj = j + dx[k];
						if (board[li][lj] == 0 || (board[li][lj] != board[i][j]))
						{
							break;
						}
						if (k == 3)
						{
							v.push_back(make_pair(i, j));
						}
					}
				}
			}
		}
		if (v.size() == 0)
		{
			break;
		}
		for (int i = v.size() - 1; i >= 0; i--)
		{
			int li = v[i].first;
			int lj = v[i].second;
			for (int j = 0; j < 4; j++)
			{
				if (board[li + dy[j]][lj + dx[j]] != 0)
				{
					board[li + dy[j]][lj + dx[j]] = 0;
					answer++;
				}
			}
			v.pop_back();
		}
		for (int j = 0; j < n; j++)
		{
				for (int i = m - 1; i > 0; i--)
				{
					if (board[i][j] == 0)
					{

						for (int k = i - 1; k >= 0; k--)
						{
							if (board[k][j] != 0)
							{
								board[i][j] = board[k][j];
								board[k][j] = 0;
								break;
							}
						}
					}
				}
		}
	}
	return answer;
}

int main()
{
	int m = 6;
	int n = 6;
	vector<string> test = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << test[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << solution(m,n,test);
}