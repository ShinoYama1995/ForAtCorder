#include <bits/stdc++.h>
using namespace std;

/*
���������
2���T���炵��
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

	//score��K�ȏ�ɕ����ł��邩�H
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
	while (right  - left > 1) //�T���s�ɂȂ�ΏI��
	{
		mid = left + (right - left) / 2;
		if (scoreIsOk(mid)) //mid�ŕ����\�����T��
		{
			left = mid;
		}
		else//�����s������T��
		{
			right = mid;
		}
	}
	cout << left;
	return 0;
}