#include <string>
#include <stack>

using namespace std;

stack <char> s;

int solution(string arrangement) {
	int answer = 0;
	for (int i = 0, l = arrangement.size(); i < l; i++) {
		if (arrangement[i] == '(') {
			s.push('(');
		}
		else if (arrangement[i - 1] == '(') {
			s.pop();
			answer += s.size();
		}
		else {
			s.pop();
			answer++;
		}
	}
	return answer;
}