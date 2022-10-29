#include <bits/stdc++.h>
using namespace std;

int main()
{
	auto judge = [](tuple<int, int, int> p1, tuple<int, int, int> p2)
	{
		int t1 = get<0>(p1);
		int x1 = get<1>(p1);
		int y1 = get<2>(p1);
		int t2 = get<0>(p2);
		int x2 = get<1>(p2);
		int y2 = get<2>(p2);

		int time = (t2 - t1);
		int distanceX = abs(x2 - x1);
		int distanceY = abs(y2 - y1);
		int distance = distanceX + distanceY;

		bool canReach = distance <= time;
		bool canStop = (time - distance) % 2 == 0;

		return canReach && canStop;
	};

	unsigned int N;
    cin >> N;

	tuple<int, int, int> current = { 0,0,0 };
	for (size_t i = 0; i < N; i++)
	{
		int t, x, y;
		cin >> t >> x >> y;

		tuple<int, int, int> next = { t, x, y };
		
		if (false == judge(current, next))
		{
			cout << "No" << endl;
			return 0;
		}

		current = next;
	}

	cout << "Yes" << endl;
	return 0;
}