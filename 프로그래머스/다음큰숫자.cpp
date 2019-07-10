int getCount(int num) {
	int res = 0;
	while (num > 0) {
		num % 2 == 1 ? res++ : res;
		num /= 2;
	}
	return res;
}

int solution(int n) {
	int cn = getCount(n);
	for (int i = n + 1; i <= 1000000; i++) {
		if (getCount(i) == cn) {
			return i;
		}
	}
	return -1;
}