// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(...)
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef vector<int> vi; typedef long long int ll;

const int mod = 1e9+7;
const int N = 3e3+1;

int n;
int a[N];
int b[N];
int c[N];

int dp[N][2];

void solve(){
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int x : {0,1}) {
			int before = x ? b[i] : a[i];
			int after  = i ? (x ? c[i] : b[i]) : before;
			int ans = max(before + (i?dp[i-1][1]:0), after + (i?dp[i-1][0]:0));
			dp[i][x] = ans;
		}
	}

	cout << dp[n-1][0] << endl;
	debug(arr(dp,n));
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	solve();
	return 0;
}