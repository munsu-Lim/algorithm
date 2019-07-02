#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	for (int i = arr1.size() - 1; i >= 0; i--) {
		for (int j = arr1[i].size() - 1; j >= 0; j--) {
			arr1[i][j] += arr2[i][j];
		}
	}
	return arr1;
}