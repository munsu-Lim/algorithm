#include <string>
#include <vector>

using namespace std;

int num = 0,
mDay[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string rString[7] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };

string solution(int a, int b) {
	num = 0;
	for (int i = 0; i < a - 1; i++)
	{
		num += mDay[i];
	}
	num += b;
	return rString[num % 7];
}