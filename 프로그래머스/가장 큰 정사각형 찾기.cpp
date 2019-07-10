#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	for (int i = 0, l = board.size(); i < l; i++) {
		for (int j = 0, lj = board[i].size(); j < lj; j++) {
			if (board[i][j] == 1) {
				if (i - 1 >= 0 && j - 1 >= 0) {
					board[i][j] = min(min(board[i - 1][j], board[i][j - 1]), board[i - 1][j - 1]) + 1;
				}
				answer = answer < board[i][j] ? board[i][j] : answer;
			}
		}
	}
	return answer * answer;
}