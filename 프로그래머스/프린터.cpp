#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

queue <pair<int, int>> q;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	for (int i = 0, l = priorities.size(); i < l; i++) {
		q.push(make_pair(priorities[i], i));
	}
	sort(priorities.begin(), priorities.end(), greater<int>());
	while (!q.empty()) {
		int lv = q.front().first;
		int li = q.front().second;
		q.pop();
		if (priorities[answer] != lv) {
			q.push(make_pair(lv, li));
		}
		else {
			answer++;
			if (li == location) return answer;
		}
	}
	return answer;
}