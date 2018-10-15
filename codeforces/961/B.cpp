#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
	#include "prettyprint.hpp"
	#define debug(x) cout << "debug: " << #x " = " << x << endl
#else
	#define debug(x) 0
#endif

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

int32_t main(){
	fast_io();
	int n,k; cin >> n; cin >> k;
	int a[n+1]; int t[n+1]; int d[n+1];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	// saved array
	int s[n+1];
	for (int i = 1; i <= n; ++i) {
		d[i] = a[i]*t[i];
		s[i] = a[i]*(1-t[i]);
	}
	int cur = accumulate(s+1, s+k+1, 0ll);
	int maxs = cur;
	for (int i = k+1; i <= n; ++i) {
		cur += s[i];
		cur -= s[i-k];
		maxs = max(maxs, cur);
	}
	int ss = accumulate(d+1, d+n+1, 0ll);
	cout << ss+maxs << endl;
}