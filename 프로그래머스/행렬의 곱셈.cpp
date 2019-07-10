#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer(arr1.size());
	for (int i = 0; i < arr1.size(); i++) {
		for (int j = 0; j < arr2[0].size(); j++) {
			answer[i].push_back(0);
			for (int k = 0; k < arr1[i].size(); k++) {
				answer[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	return answer;
}