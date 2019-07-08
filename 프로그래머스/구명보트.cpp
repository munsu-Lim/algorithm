#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
	int ans = 0, l = people.size() - 1;
	sort(people.begin(), people.end(), greater<int>());
	for (; ans <= l; ans++) {
		people[ans] + people[l] <= limit ? l-- : l;
	}
	return ans;
}