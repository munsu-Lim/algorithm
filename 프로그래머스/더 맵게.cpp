#include <queue>
#include <vector>

using namespace std;

priority_queue< int, vector<int>, greater<int> > q;

int solution(vector<int> scoville, int K) {
	int answer = 0, a, b;
	for (int i = 0, l = scoville.size(); i < l; i++) q.push(scoville[i]);
	while (!q.empty() && q.top() < K) {
		answer++;
		a = q.top();
		q.pop();
		if (q.empty()) return -1;
		b = q.top();
		q.pop();
		q.push(a + b * 2);
	}
	return answer;
}