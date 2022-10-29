#include <bits/stdc++.h>
using namespace std;

/*
�ŒZ����������2����炵��
�_A����ŒZ��������ԉ����_B�A����ŒZ��������ԉ����_�܂ł̋������؂̒��a
�

20/30��AC,����WA�������B�����ǂ���������킩��Ȃ�
*/


int main()
{
	vector<vector<int>> Graph;
	vector<int> distance;

	int N;
	cin >> N;
	for (size_t i = 0; i < N + 1; i++)
	{
		Graph.push_back({});
		distance.push_back(INT_MAX);
	}
	for (size_t i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	auto calcDistance = [&](int start)
	{
		for (size_t i = 0; i < N; i++)
			distance[i] = INT_MAX;

		queue<int> Q;
		Q.push(start);
		distance[start] = 0;

		while (!Q.empty())
		{
			int pos = Q.front();
			Q.pop();

			for (auto& next : Graph[pos])
			{
				if (distance[next] != INT_MAX)
					continue;

				distance[next] = distance[pos] + 1;
				Q.push(next);
			}
		}
	};

	calcDistance(1);
	int max1 = -1, maxId1 = -1;
	for (size_t i = 1; i <= N; i++)
	{
		if (max1 < distance[i])
		{
			max1 = distance[i];
			maxId1 = i;
		}
	}

	calcDistance(maxId1);
	int max2 = -1;
	for (size_t i = 1; i <= N; i++)
	{
		max2 = max(max2, distance[i]);
	}

	cout << max2 + 1 << endl;
	return 0;
}

/*
unsigned char			1byte	0~255
char					1byte	-128~127
unsgied short int		2byte	0�`65535
short int				2byte	-32768�`32767
unsigned int			4byte	0�`4294967295 < 10^9
int						4byte	-2147483648�`2147483647 < 10^9
long int				4byte	-2147483648�`2147483647 < 10^9
unsigned long long int	8byte	0�`18446744073709551615 < 10^19
long long int			8byte	-9223372036854775808�`9223372036854775807 < 10^18

float	4byte
double	8byte

2�i���ł�i��j�r�b�g�ڂ�0���H	i & (1 << j) == 0
2�i���ł�i��j�r�b�g�ڂ�1���H	i & (1 << j) == 1
*/