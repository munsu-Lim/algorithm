#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	for (int i = 0, cnt = 0; i < k; i++) {
		if (i >= dates[cnt]) {
			pq.push(supplies[cnt++]);
		}
		if (stock < 1) {
			stock += pq.top();
			pq.pop();
			answer++;
		}
		stock -= 1;
	}
	return answer;
}

int main() {
	solution(4, { 4, 10, 15 }, { 20, 5, 10 }, 30);
}