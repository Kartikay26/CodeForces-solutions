// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

void test()
{
	int n; cin >> n;
	vector<int> A(n);
	map<int, int> compress;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		compress[A[i]];
	}
	int i = 0;
	for (auto& [k, v] : compress) {
		v = i++;
	}
	for (auto& x : A) {
		x = compress[x];
	}
	// ================================================
	int dp[n][n];
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	for (auto& x : A) {
		for (int y = 0; y < n; ++y) {
			dp[y][x] = max(dp[y][x], dp[x][y] + 1);
			ans = max(ans, dp[y][x]);
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	test();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}