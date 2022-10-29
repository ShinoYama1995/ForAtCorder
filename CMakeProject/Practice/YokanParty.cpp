#include <bits/stdc++.h>
using namespace std;

/*
解説を見た
2文探索らしい
*/

int main()
{
	int K, N;
	long long int L;
	std::vector<long long int> A;
	cin >> N >> L;
	cin >> K;
	for (size_t i = 0; i < N; i++)
	{
		long long int a;
		cin >> a;
		A.push_back(a);
	}

	//scoreでK個以上に分割できるか？
	auto scoreIsOk = [&](long long int score)
	{
		int count = 0;
		long long int lastA = 0;
		for (auto& a : A)
		{
			if (a - lastA >= score && L - a >= score)
			{
				count += 1;
				lastA = a;
			}
		}

		return count >= K;
	};

	long long int left, right, mid;
	left = 0;
	right = L;
	mid = L / 2;
	while (right  - left > 1) //探索不可になれば終了
	{
		mid = left + (right - left) / 2;
		if (scoreIsOk(mid)) //midで分割可能→上を探索
		{
			left = mid;
		}
		else//分割不可→下を探索
		{
			right = mid;
		}
	}
	cout << left;
	return 0;
}