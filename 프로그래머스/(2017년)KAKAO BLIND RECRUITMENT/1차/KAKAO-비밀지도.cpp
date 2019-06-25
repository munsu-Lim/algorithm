#include <iostream>;
#include <string>
#include <vector>

using namespace std;
int a1[17][17], a2[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++)
	{
		string str = "";
		arr1[i] = arr1[i] | arr2[i];
		for (int j = 0; j < n; j++)
		{
			str = arr1[i] % 2 ? '#' + str : ' ' + str;
			arr1[i] /= 2;
		}
		answer.push_back(str);
	}
	return answer;
}

int main()
{
	int tn = 5;
	vector<string> re;
	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = { 30, 1, 21, 17, 28 };
	re = solution(tn, arr1, arr2);
	for (int i = 0; i < re.size(); i++)
	{
		cout << re[i];
	}
}