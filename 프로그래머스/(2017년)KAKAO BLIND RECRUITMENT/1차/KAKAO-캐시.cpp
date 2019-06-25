#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> li;
vector <string>::iterator iter;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	for (int i = 0; i < cities.size(); i++)
	{
		string cur = "";
		bool Bfind = false;
		for (int j = 0; j < cities[i].size(); j++)
		{
			cur += tolower(cities[i][j]);
		}
		for (iter = li.begin(); iter != li.end(); iter++)
		{
			if (*iter == cur)
			{
				Bfind = true;
				li.erase(iter);
				break;
			}
		}
		li.push_back(cur);
		Bfind ? answer++ : answer += 5;
		if (li.size() > cacheSize)
		{
			li.erase(li.begin());
		}
	}
	return answer;
}

int main()
{
	vector <string> test = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	cout << solution(3, test);
}