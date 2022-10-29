#include <bits/stdc++.h>
using namespace std;

//³‰ð

int main()
{
	const unsigned long long MOD = 998244353;
	unsigned long long A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;

	A = A % MOD;
	B = B % MOD;
	C = C % MOD;
	D = D % MOD;
	E = E % MOD;
	F = F % MOD;

	unsigned long long left = A * B % MOD * C % MOD;
	unsigned long long right = D * E % MOD * F % MOD;

	unsigned long long answer;
	if (left < right)
	{
		unsigned long long diff = (left + MOD) - right;
		answer = diff % MOD;
	}
	else
	{
		unsigned long long diff = left - right;
		answer = diff % MOD;
	}

	cout << answer << endl;
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
