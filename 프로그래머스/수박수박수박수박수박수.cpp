#include <string>

using namespace std;

string solution(int n) {
	string answer = "";
	for (int i = 0; i < n; i++)
	{
		answer += i % 2 ? "¹Ú" : "¼ö";
	}
	return answer;
}