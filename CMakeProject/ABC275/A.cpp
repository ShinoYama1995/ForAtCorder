#include <bits/stdc++.h>
using namespace std;

//³‰ğ

int main()
{
	int N;
	vector<unsigned long long> H;

	cin >> N;

	int maxNum = 0;
	unsigned long long max = 0;
	for (size_t i = 1; i <= N; i++)
	{
		int h;
		cin >> h;
		
		if (max < h)
		{
			max = h;
			maxNum = i;
		}
	}

	cout << maxNum << endl;
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
