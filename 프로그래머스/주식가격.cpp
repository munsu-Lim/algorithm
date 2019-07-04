#include <stack>
#include <vector>

using namespace std;

stack <pair<int, int>> s;

vector<int> solution(vector<int> prices) {
	s.push(make_pair(prices[0], 0));
	int l = prices.size();
	for (int i = 1; i < l; i++) {
		if (s.top().first <= prices[i]) {
			s.push(make_pair(prices[i], i));
		}
		while (!s.empty() && s.top().first > prices[i]) {
			prices[s.top().second] = i - s.top().second;
			s.pop();
		}
	}
	while (!s.empty()) {
		prices[s.top().second] = l - 1 - s.top().second;
		s.pop();
	}
	return prices;
}