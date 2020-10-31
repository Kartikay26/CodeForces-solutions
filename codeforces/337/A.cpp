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
	// n - students, m - puzzles
	int n, m; cin >> n >> m;
	vector<int> f(m); // f - number of pieces in each puzzle
	for (int i = 0; i < m; ++i)
	{
		cin >> f[i];
	}
	// choose n puzzles such that range (highest-lowest) is minimum
	sort(f.begin(), f.end());
	int ans = INT_MAX;
	for (int i = 0; i < m - n + 1; ++i)
	{
		int range = f[n+i-1] - f[i];
		ans = min(ans, range);
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}