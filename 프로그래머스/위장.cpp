#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map <string, int> uMap;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	for (int i = 0; i < clothes.size(); i++) uMap[clothes[i][1]]++;

	for (auto it = uMap.begin(); it != uMap.end(); it++) answer *= (it->second + 1);
	return answer - 1;
}