int d[2];

int solution(int n) {
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i % 2] = (d[0] + d[1]) % 1234567;
	}
	return d[n % 2];
}