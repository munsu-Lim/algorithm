#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	bool flag = true;
	for (int i = 0, l = s.size(); i < l; i++) {
		if (s[i] == ' ') flag = true;
		else if (flag) {
			(s[i] >= 'a' && s[i] <= 'z') ? s[i] -= 'a' - 'A' : s[i];
			flag = false;
		}
		else (s[i] >= 'A' && s[i] <= 'Z') ? s[i] += 'a' - 'A' : s[i];
	}
	return s;
}