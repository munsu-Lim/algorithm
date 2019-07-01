#include <string>

using namespace std;

string solution(string s, int n) {
	for (int i = 0, l = s.size(); i < l; i++) {
		char cur = s[i];
		if (cur == ' ') continue;
		else if (cur >= 'a') cur -= 'a';
		else cur -= 'A';
		s[i] = s[i] >= 'a' ? (cur + n) % 26 + 'a' : (cur + n) % 26 + 'A';
	}
	return s;
}