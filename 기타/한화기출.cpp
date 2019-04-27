#include <iostream>
#include <vector>

using namespace std;
int main(void) {

	int t = 0;
	vector<int> v;

	cin >> t;
	bool f = false;
	//input
	for (int i = 0; i < t; i++) {
		if (!f) {
			int a = 0, b = 0;
			cin >> a >> b;
			v.push_back(a + b);
		}
		else {
			cout << "# " << i + 1 << v[i] << endl;
		}
		if (i + 1 == t && !f) {
			i = -1;
			f = true;
		}

	}
	return 0;
}