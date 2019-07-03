#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int days = 0, c = -1;
	for (int i = 0; i < progresses.size(); i++) {
		if (days && progresses[i] + speeds[i] * days >= 100) {
			answer[c]++;
			continue;
		}
		days = (100 - progresses[i]) / speeds[i];
		if (days * speeds[i] + progresses[i] < 100) days++;
		answer.push_back(1);
		c++;
	}
	return answer;
}

int main() {
	solution({ 93, 30, 55 }, { 1, 30, 5 });
}