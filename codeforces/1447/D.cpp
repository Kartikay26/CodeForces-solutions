// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

void test ()
{
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int dp[n][m];
	memset(dp, 0, sizeof(dp));
	// idea: like kadane, keep track of
	// longest subarray that ends at (i);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i] == t[j]) {
				dp[i][j] = (i&&j?dp[i-1][j-1]:0) + 2;
			} else {
				dp[i][j] = max({
					0ll,
					i?dp[i-1][j]-1:0,
					j?dp[i][j-1]-1:0,
				});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// cout << dp[i][j] << ' ';
			ans = max(ans, dp[i][j]);
		}
		// cout << endl;
	}
	cout << ans << endl;
}

int32_t main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}