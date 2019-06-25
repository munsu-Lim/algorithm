#include <string>
#include <iostream>

using namespace std;

int fr[2], mi[2];
int d[200];
int c[200];
bool bCon;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
	string answer = "";
	int size = sentence.length();
	bool bBlank = false;
	bool bFirst = true;
	bCon = false;
	int bc = 0;
	int bs = 0;
	for (int i = 0; i < size; i++)
	{
		c[sentence[i]]++;
	}
	for (int i = 0; i < size; i++)
	{
		int nc = sentence[i];
		if (nc == ' ')
		{
			return "invalid";
		}
		if (nc >= 'a' && nc <= 'z')
		{
			if (fr[0] == 0 && mi[0] == 0 && d[nc] == 0)
			{
				if (c[nc] == 2)
				{
					if (!bFirst)
					{
						bBlank = true;
					}
					fr[0] = 1;
					fr[1] = nc;
					d[nc] = 1;
				}
				else
				{
					mi[0] = 1;
					mi[1] = nc;
					d[nc] = 1;
					bs = 1;
				}
			}
			else if (fr[0] == 1)
			{
				if (fr[1] == nc && (bc - 1 == bs || mi[0] == 0))
				{
					fr[0] = 0;
					mi[0] = 0;
					bc = 0;
					bs = 0;
					bBlank = true;
				}
				else if (mi[0] == 0 && d[nc] == 0)
				{
					mi[0] = 1;
					mi[1] = nc;
					bs = 1;
				}
				else if (mi[0] == 1 && mi[1] == nc)
				{
					bs++;
				}
				else
				{
					return "invalid";
				}
			}
			else
			{
				if (mi[0] == 0 && d[nc] == 0)
				{
					mi[0] = 1;
					mi[1] = nc;
					d[nc] = 1;
					bs = 1;
				}
				else if (mi[0] == 1 && mi[1] == nc)
				{
					bs++;
				}
				else if (mi[0] == 1 && mi[1] != nc && d[nc] == 0 && bc - 1 == bs)
				{
					fr[0] = 1;
					fr[1] = nc;
					mi[0] = 0;
					d[nc] = 1;
					bc = 0;
					bs = 0;
					bBlank = true;
				}
				else
				{
					return "invalid";
				}
			}
			bCon = false;
		}
		else
		{
			if (bCon)
			{
				if (fr[0] == 0)
				{
					if (mi[0] == 1)
					{
						mi[0] = 0;
						bs = 0;
						bBlank = true;
					}
					bc = 1;
				}
			}
			else {
				bc++;
				if (fr[0] == 0 && mi[0] == 0)
				{
					bc = 1;
				}
			}
			if (bBlank)
			{
				answer += " ";
				bBlank = false;
			}
			answer += nc;
			bCon = true;
			bFirst = false;
		}
	}
	if ((bc - 1 == bs || mi[0] == 0) && fr[0] == 0)
	{
		return answer;
	}
	else
	{
		return "invalid";
	}
}
int main()
{
	string ans = "";
	ans = solution("HaEaLaLObWORLDb");
	cout << ans;
}