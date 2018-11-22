// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#else
#define debug(...) 0
#endif
typedef long long int ll;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5+1;
int a[N], f[N];
int dp[N][2];
int n;

int32_t main(){
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		f[a[i]]++;
	}
	for (int i = 1; i < N; ++i) {
		int c = i*f[i];
		dp[i][1] = dp[i-1][0] + c;
		dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
	}
	cout << max(dp[N-1][1], dp[N-1][0]) << endl;
}