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
	int n; cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	sort(h.begin(), h.end());
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += abs(h[i] - (i+1));
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