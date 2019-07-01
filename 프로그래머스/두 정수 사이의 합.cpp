#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
	return a == b ? (long long)a : (long long)(a + b) * (max((a - b), (b - a)) + 1) / 2;
}