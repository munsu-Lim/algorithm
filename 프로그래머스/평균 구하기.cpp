#include <vector>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;
	for (int i = arr.size() - 1; i >= 0; i--) answer += arr[i];
	return answer / arr.size();
}