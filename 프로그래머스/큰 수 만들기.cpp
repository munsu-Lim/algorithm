#include <string>
#include <vector>

using namespace std;


string solution(string number, int k) {
	string answer = "";
	bool flag = false;
	for (int i = 0, l = number.size(); i < l; i++) {
		for (int j = i + 1; j < number.size() && j < i + k + 1; j++) {
			if (number[i] < number[j]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			k--;
			flag = false;
		}
		else answer += number[i];
	}
	while (k > 0) {
		answer.pop_back();
		k--;
	}
	return answer;
}