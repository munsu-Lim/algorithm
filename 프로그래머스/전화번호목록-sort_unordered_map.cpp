#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

unordered_set <string> um;

bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0, l = phone_book.size(); i < l; i++) {
		string str = "";
		for (int j = 0, jl = phone_book[i].size(); j < jl; j++) {
			str += phone_book[i][j];
			auto iter = um.find(str);
			if (iter != um.end()) {
				return false;
			}
		}
		um.insert(phone_book[i]);
	}
	return true;
}
