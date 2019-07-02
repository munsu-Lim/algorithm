#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
	sort(d.begin(), d.end());
	for (int i = 0, l = d.size(); i < l; i++) {
		if (budget - d[i] >= 0) budget = budget - d[i];
		else return i;
	}
	return d.size();
}