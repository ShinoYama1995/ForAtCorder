#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;

	vector<int> A(H * W, 0);
	vector<int> rowSum(H, 0);
	vector<int> colSum(W, 0);
	for (size_t i = 0; i < H; i++)
	{
		for (size_t j = 0; j < W; j++)
		{
			int Aij;
			cin >> Aij;
			A[i*W + j] = Aij;
			rowSum[i] += Aij;
			colSum[j] += Aij;
		}
	}

	auto calcSum = [&](int h, int w)
	{
		int sum = 0;
		sum += rowSum[h];
		sum += colSum[w];
		sum -= A[h*W + w];
		return sum;
	};

	for (size_t i = 0; i < H; i++)
	{
		for (size_t j = 0; j < W; j++)
		{
			cout << calcSum(i, j) << " ";
		}
		cout << endl;
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

2i”‚Å‚Ìi‚Ìjƒrƒbƒg–Ú‚Í0‚©H	i & (1 << j) == 0
2i”‚Å‚Ìi‚Ìjƒrƒbƒg–Ú‚Í1‚©H	i & (1 << j) == 1
*/
