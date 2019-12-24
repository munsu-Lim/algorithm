#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d[510];
int fail[510];

bool comp (const int& a, const int& b){
    long long A = (long long)d[b] * fail[a];
    long long B = (long long)d[a] * fail[b];
    if (A > B) {
        return true;
    }
    if (A==B) {
        return a < b ? true : false;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	for (int i = 0; i < stages.size(); i++) d[stages[i]] += 1;
	for (int i = N; i > 0; i--) {
        fail[i] = d[i];
		d[i] = d[i] + d[i+1];
        answer.push_back(i);
	}
	sort(answer.begin(), answer.end(), comp);
	return answer;
}