#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	int a = n; int b = m;
	while (a % b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	answer.push_back(b);
	answer.push_back(n * m / b);
	return answer;
}