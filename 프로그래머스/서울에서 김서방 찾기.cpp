#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	for (int i = 0, l = seoul.size(); i < l; i++)
	{
		if (seoul[i] == "Kim") return "�輭���� " + to_string(i) + "�� �ִ�";
	}
}