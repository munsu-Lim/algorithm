#include <string>
#include <vector>

using namespace std;

int d[20];
int ct, mi, sz;

void mfind(int cnt, int cur, int find) {
	if (cnt > mi || find == ct) {
		mi = mi > cnt ? cnt : mi;
		return;
	}
	for (int i = 1; i < sz - 1; i++) {
		if (d[cur + i % sz] == 1) {
			d[cur + i % sz] = 0;
			mfind(cnt + i, cur + i % sz, find + 1);
			d[cur + i % sz] = 1;
			break;
		}
	}
	for (int i = 1; i < sz - 1; i++) {
		int mcur = cur;
		if (cur - i < 0) mcur += sz;
		if (d[mcur - i] == 1) {
			d[mcur - i ] = 0;
			mfind(cnt + i, mcur - i, find + 1);
			d[mcur - i] = 1;
			break;
		}
	}
}

int solution(string name) {
	int answer = 0;
	mi = sz = name.size();
	for (int i = 0; i < sz; i++) {
		if (name[i] != 'A') {
			if (i > 0) {
				ct++;
				d[i] = 1;
			}
			answer += name[i] - 'A' < 'Z' - name[i] + 1 ? name[i] - 'A' : 'Z' - name[i] + 1;
		}
	}
	mfind(0, 0, 0);
	return answer + mi;
}