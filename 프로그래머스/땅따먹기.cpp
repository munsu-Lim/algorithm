#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	int l = land.size();
	if (l == 1) {

	}
	for (int i = 1; i < l; i++) {
		for (int j = 0; j < 4; j++) {
			answer = 0;
			for (int k = 0; k < 4; k++) {
				if (k != j) {
					answer = answer < land[i - 1][k] ? land[i - 1][k] : answer;
				}
			}
			land[i][j] += answer;
		}
	}
	for (int i = 0; i < 4; i++) {
		answer = answer < land[l - 1][i] ? land[l - 1][i] : answer;
	}
	return answer;
}

/* ver 2
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	int l = land.size();
	if (l == 1) {

	}
	for (int i = 1; i < l; i++) {
		int max1 = 0;
		int max2 = 0;
		for (int j = 0; j < 4; j++) {
			if(max1 < land[i - 1][j]) {
				max2 = max1;
				max1 = land[i - 1][j];
			}
			else if (max2 < land[i - 1][j]) {
				max2 = land[i - 1][j];
			}
		}
		for (int j = 0; j < 4; j++) {
			if(max1 == land[i - 1][j]) {
				land[i][j] += max2;
			}
			else {
				land[i][j] += max1;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		answer = answer < land[l - 1][i] ? land[l - 1][i] : answer;
	}
	return answer;
}

*/