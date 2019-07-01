#include <string>
using namespace std;

int a, b;

bool solution(string s)
{
	for (int i = 0, l = s.length(); i < l; i++)
	{
		if (s[i] == 'p' || s[i] == 'P') a++;
		if (s[i] == 'y' || s[i] == 'Y') b++;
	}
	return a == b;
}