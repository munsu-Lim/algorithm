#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<pair<int, int>> s;
	vector<int> answer(heights.size(), 0);
	s.push_back(make_pair(heights[heights.size() - 1], heights.size() - 1));
	for (int i = heights.size() - 2; i >= 0; i--) {
		while (s.size() > 0 && s[s.size() - 1].first < heights[i]) {
			answer[s[s.size() - 1].second] = i + 1;
			s.pop_back();
		}
		s.push_back(make_pair(heights[i], i));
	}
	return answer;
}