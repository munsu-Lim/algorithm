#include <string>

using namespace std;

string solution(string s) {
	for (int i = 0, l = s.size(), cnt = 0; i < l; i++) {
		if (s[i] == ' ') cnt = 0;
		else if (cnt++ % 2) s[i] = tolower(s[i]);
		else s[i] = toupper(s[i]);
	}
	return s;
}