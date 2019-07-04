#include <string>

using namespace std;

string solution(int n) {
	string answer = "";
	while (n > 0) {
		int l = n % 3;
		n /= 3;
		if (l == 0) {
			n--;
		}
		answer = "412"[l] + answer;
	}
	return answer;
}

int main() {
	solution(54);
}