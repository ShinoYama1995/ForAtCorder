#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N; //N‚Í20‚Ü‚Å

	char left = '(';
	char right = ')';

	auto isOK = [&](string str)
	{
		int count = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (left == str[i])
				count += 1;
			else
				count -= 1;

			if (count < 0)
				return false;
		}
		return count == 0;
	};

	auto makeStr = [&](int num)
	{
		string str = "";
		for (size_t i = 0; i < N; i++)
		{
			bool is0 = (num & 1 << i) == 0;
			str = ( is0 ? "(" : ")" ) + str;
		}
		return str;
	};

	for (size_t i = 0; i < pow(2, N); i++)
	{
		string str = makeStr(i);
		if (isOK(str))
			cout << str << endl;
	}
	return 0;
}

/*
unsigned char			1byte	0~255
char					1byte	-128~127
unsgied short int		2byte	0`65535
short int				2byte	-32768`32767
unsigned int			4byte	0`4294967295 < 10^9
int						4byte	-2147483648`2147483647 < 10^9
long int				4byte	-2147483648`2147483647 < 10^9
unsigned long long int	8byte	0`18446744073709551615 < 10^19
long long int			8byte	-9223372036854775808`9223372036854775807 < 10^18

float	4byte
double	8byte
*/