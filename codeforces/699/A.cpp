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
	int n; cin >> n;
	char a[n];
	int x[n];
	for (int i = 0; i < n; ++i) {
		char c; cin>>c;
		a[i] = c;
	}
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	int ans = LLONG_MAX;
	for (int i = 0; i < n-1; ++i) {
		if (a[i]=='R' and  a[i+1]=='L') {
			ans = min( (x[i+1] - x[i])/2 , ans);
		}
	}
	if (ans == LLONG_MAX) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}