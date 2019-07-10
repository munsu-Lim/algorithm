#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	for (int i = 1, j; i <= red; i++) {
		if (red % i == 0) {
			j = red / i;
			if ((i * 2 + j * 2 + 4) == brown) {
				return { j + 2, i + 2 };
			}
		}
	}
	return { -1, -1 };
}