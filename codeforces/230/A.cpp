// kartikay26
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

void solve()
{
	// initial strength s
	int s, n; cin >> s >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i)
	{
		// strength need to kill - x, strength gain - y
		int x, y; cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
	{
		if (s > v[i].first)
		{
			s += v[i].second;
		}
		else
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}