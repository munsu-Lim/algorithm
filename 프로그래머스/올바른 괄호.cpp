#include <string>

using namespace std;

bool solution(string s)
{
	int count = 0;
	for (int i = 0, l = s.size(); i < l; i++) {
		if (s[i] == '(') {
			count++;
		}
		else {
			count--;
		}
		if (count < 0) return false;
	}
	return count == 0;
}