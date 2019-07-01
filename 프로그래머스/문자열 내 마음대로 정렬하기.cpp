#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k = 0;

bool compare(string a, string b)
{
	return a[k] == b[k] ? a < b : a[k] < b[k];
}

vector<string> solution(vector<string> strings, int n) {
	k = n;
	sort(strings.begin(), strings.end(), compare);
	return strings;
}