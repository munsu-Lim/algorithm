#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
	int a = s.length();
	if (a != 4 && a != 6) return false;
	for (int i = 0; i < a; i++)
	{
		if (s[i] < '0' || s[i] > '9') return false;
	}
	return true;
}