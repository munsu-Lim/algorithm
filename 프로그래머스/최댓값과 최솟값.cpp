#include <string>
#include <iostream>
#include <vector>

using namespace std;

int nMax = -2100000000, nMin = 2100000000, num = 0;
bool bMinus = false;

void update() {
	if (bMinus) {
		num *= -1;
	}
	nMax = nMax < num ? num : nMax;
	nMin = nMin > num ? num : nMin;
	num = 0;
	bMinus = false;
}

string solution(string s) {
	for (int i = 0, l = s.size(); i < l; i++) {
		if (s[i] == ' ') {
			update();
		}
		else if (s[i] == '-') {
			bMinus = true;
		}
		else {
			num *= 10;
			num += s[i] - '0';
		}
	}
	update();
	return to_string(nMin) + ' ' + to_string(nMax);
}

int main() {
	cout << to_string(-14);
}