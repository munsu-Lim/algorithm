#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	int minN = *min_element(arr.begin(), arr.end());
	int pos = find(arr.begin(), arr.end(), minN) - arr.begin();
	arr.erase(arr.begin() + pos);
	return arr.empty() ? vector <int>(-1) : arr;
}