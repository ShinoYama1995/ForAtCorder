#include <bits/stdc++.h>
using namespace std;

//ïsê≥â

int main()
{
	const unsigned int len = 9;
	using point = std::pair<int, int>;

	vector<vector<bool>> board;
	vector<point> truePoints;
	for (size_t i = 0; i < len; i++)
	{
		board.push_back(vector<bool>(len, false));
	}

	for (size_t i = 0; i < len; i++)
	{
		string s;
		cin >> s;
		for (size_t j = 0; j < len; j++)
		{
			board[i][j] = s[j] == '#';
			if (s[j] == '#')
			{
				truePoints.push_back({ i, j });
			}
		}
	}

	int count = 0;

	auto calcDistance = [&](point p1, point p2)
	{
		int x = abs(p1.first - p2.first);
		int y = abs(p1.second - p2.second);
		double distance = sqrt(pow(x, 2) + pow(y, 2));
		return distance;
	};

	auto check = [&](point p1, point p2, point p3, point p4)
	{
		double l1 = calcDistance(p1, p2);
		double l2 = calcDistance(p1, p3);
		double l3 = calcDistance(p1, p4);
		cout << l1 << " " << l2 << " " << l3 << endl;

		if (l1 == l2)
		{
			cout << "l1==l2" << endl;
			if (calcDistance(p2, p4) == calcDistance(p3, p4))
			{
				count += 1;
			}
		}
		else if (l2 == l3)
		{
			cout << "l2==l3" << endl;
			if (calcDistance(p2, p3) == calcDistance(p2, p4))
			{
				count += 1;
			}
		}
		else if (l1 == l3)
		{
			cout << "l1==l3" << endl;
			if (calcDistance(p2, p3) == calcDistance(p3, p4))
			{
				count += 1;
			}
		}
	};

	for (size_t i = 0; i < truePoints.size(); i++)
	{
		for (size_t j = i + 1; j < len; j++)
		{
			for (size_t k = j + 1; k < len; k++)
			{
				for (size_t l = k + 1; l < len; l++)
				{
					auto p1 = truePoints[i];
					auto p2 = truePoints[j];
					auto p3 = truePoints[k];
					auto p4 = truePoints[l];

					check(p1, p2, p3, p4);
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}

/*
unsigned char			1byte	0~255
char					1byte	-128~127
unsgied short int		2byte	0Å`65535
short int				2byte	-32768Å`32767
unsigned int			4byte	0Å`4294967295 < 10^9
int						4byte	-2147483648Å`2147483647 < 10^9
long int				4byte	-2147483648Å`2147483647 < 10^9
unsigned long long int	8byte	0Å`18446744073709551615 < 10^19
long long int			8byte	-9223372036854775808Å`9223372036854775807 < 10^18

float	4byte
double	8byte

2êiêîÇ≈ÇÃiÇÃjÉrÉbÉgñ⁄ÇÕ0Ç©ÅH	i & (1 << j) == 0
2êiêîÇ≈ÇÃiÇÃjÉrÉbÉgñ⁄ÇÕ1Ç©ÅH	i & (1 << j) == 1
*/
