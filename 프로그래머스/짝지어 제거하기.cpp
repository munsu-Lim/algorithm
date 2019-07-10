#include <stack>
#include <string>
using namespace std;

int solution(string s)
{
	stack <char> st;
	for (int i = 0, l = s.size(); i < l; i++) {
		(!st.empty() && st.top() == s[i]) ? st.pop() : st.push(s[i]);
	}
	return st.empty();
}