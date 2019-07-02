int solution(int num) {
	long long n = (long long)num;
	if (n == 1) return 0;
	for (int i = 1; i <= 500; i++)
	{
		n = n % 2 ? (n * 3) + 1 : n / 2;
		if (n == 1) return i;
	}
	return -1;
}