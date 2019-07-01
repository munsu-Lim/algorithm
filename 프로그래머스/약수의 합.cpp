#include <string>

using namespace std;

int solution(int n) {
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer += n % i ? 0 : i;
	}
	return answer;
}