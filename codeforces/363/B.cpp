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
	int n, k; cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	int sum = accumulate(h.begin(), h.begin()+k, 0);
	int ans = sum, ansi = 0;
	for (int i = 0; i < n-k; ++i)
	{
		sum -= h[i];
		sum += h[i+k];
		tie(ans, ansi) = min(make_pair(ans, ansi), make_pair(sum, i+1));
		debug(sum, ansi);
	}
	cout << ansi+1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}