#include <vector>
#include <unordered_set>

using namespace std;

unordered_set <int> us;

int solution(vector<int> nums)
{
	int l = nums.size();
	for (int i = 0; i < l; i++) {
		if (us.find(nums[i]) == us.end()) {
			us.insert(nums[i]);
			if (us.size() >= l / 2) break;
		}
	}
	return us.size();
}