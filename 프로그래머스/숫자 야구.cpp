#include <string>
#include <vector>

using namespace std;

int st, ball;
string str1, str2;
bool flag;

void check() {
	st = ball = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (str1[i] == str2[j]) {
				i == j ? st += 1 : ball += 1;
			}
		}
	}
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	for (int i = 111; i <= 999; i++) {
		flag = true;
		str1 = to_string(i);
		if (str1[0] == str1[1] || str1[1] == str1[2] || str1[0] == str1[2]) continue;
		if (str1[0] == '0' || str1[1] == '0' || str1[2] == '0') continue;
		for (int j = 0; j < baseball.size(); j++) {
			str2 = to_string(baseball[j][0]);
			check();
			if (baseball[j][1] != st || baseball[j][2] != ball) {
				flag = false;
				break;
			}
		}
		answer += flag ? 1 : 0;
	}
	return answer;
}