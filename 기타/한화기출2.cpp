#include <iostream>
#include <string>

using namespace std;

string Num1[] = { "¿µ", "ÀÏ", "ÀÌ", "»ï", "»ç", "¿À", "À°", "Ä¥", "ÆÈ", "±¸" };
string Num2[] = { "","½Ê", "¹é", "Ãµ"};
string Num3[] = { "", "¸¸", "¾ï", "Á¶", "ÇØ", "°æ" };
string snum;

int main()
{
	cin >> snum;
	bool bTrue = false;
	for (int i = 0; i < snum.size(); i++)
	{
		
		int cur = snum[i] - '0';
		if((snum.size() - i - 1) % 4 == 0)
		{
			int now = (snum.size() - i - 1) / 4;
			if (((bTrue || cur > 1) && (cur != 0)) || snum.size () == 1)
			{
				cout << Num1[cur];
			}
			cout << Num3[now];
			bTrue = false;
		}
		else if (cur > 0)
		{
			if (cur > 1)
			{
				cout << Num1[cur];
			}
			cout << Num2[(snum.size() - i - 1) %4];
			bTrue = true;
		}
	}
	return 0;
}