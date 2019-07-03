#include <queue>
#include <vector>

using namespace std;

queue <pair<int, int>> q;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int cW = 0, ct = 1;
	for (int i = 0, l = truck_weights.size(); i < l; i++) {
		if (cW + truck_weights[i] <= weight) {
			q.push(make_pair(ct + bridge_length, truck_weights[i]));
			cW += truck_weights[i];
		}
		else {
			while (cW + truck_weights[i] > weight) {
				ct = ct > q.front().first ? ct : q.front().first;
				cW -= q.front().second;
				q.pop();
			}
			q.push(make_pair(ct + bridge_length, truck_weights[i]));
			cW += truck_weights[i];
		}
		ct++;
	}
	return ct + bridge_length - 1;
}