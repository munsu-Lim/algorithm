int d[10001];

int solution(int n) {
	int answer = 1;
	for (int i = 1; i <= n; i++) {
		d[i] += i + d[i - 1];
	}
	for (int i = 1; i < n; i++) {
		int s = d[i - 1];
		for (int j = i + 1; j < n; j++) {
			if (d[j] - s == n) {
				answer++;
				break;
			}
			if (d[j] - s > n) break;
		}
	}
	return answer;
}