#include <string>

using namespace std;

int solution(string s) {
	int answer = 0;
	for (int i = s.length() - 1, n = 1; i >= 0; i--, n *= 10)
	{
		if (s[i] >= '0' && s[i] <= '9') answer += (s[i] - '0') * n;
	}
	if (s[0] == '-') answer *= -1;
	return answer;
}