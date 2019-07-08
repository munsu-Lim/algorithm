#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	sort(citations.begin(), citations.end());
	for (int i = 0, l = citations.size(); i < l; i++)
	{
		if (l - i <= citations[i]) {
			return l - i;
		}
	}
	return 0;
}