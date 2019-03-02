// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = "; _dbg(__VA_ARGS__);
#define debuga(arr, n) _dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
#endif
typedef long long int ll;
#define int ll
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 2e5+2;

int n, l, r;
int x[N], y[N], z[N];

int32_t main(){
	fast_io();
	cin >> n >> l >> r;
	int a = (r/3 - (l-1)/3)%mod;
	int b = ((r+1)/3 - (l)/3)%mod;
	int c = ((r+2)/3 - (l+1)/3)%mod;
	x[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int x_ = x[i-1], y_ = y[i-1], z_ = z[i-1];
		x[i] = (a*x_ + c*y_ + b*z_) % mod;
		y[i] = (b*x_ + a*y_ + c*z_) % mod;
		z[i] = (c*x_ + b*y_ + a*z_) % mod;
	}
	cout << x[n] << endl;
	return 0;
}