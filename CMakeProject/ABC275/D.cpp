#include <bits/stdc++.h>
using namespace std;

//³‰ğ

unordered_map<unsigned long long, unsigned long long> answer;

unsigned long long func(unsigned long long n)
{
	if (0 == n) return 1;
	if (answer.find(n) != answer.end())
	{
		return answer.at(n);
	}

	unsigned long long n2 = n / 2;
	unsigned long long n3 = n / 3;
	unsigned long long sum = func(n2) + func(n3);

	answer[n] = sum;
	return sum;
}

int main()
{
	unsigned long long N;
	cin >> N;

	cout << func(N) << endl;
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

2i”‚Å‚Ìi‚Ìjƒrƒbƒg–Ú‚Í0‚©H	i & (1 << j) == 0
2i”‚Å‚Ìi‚Ìjƒrƒbƒg–Ú‚Í1‚©H	i & (1 << j) == 1
*/
