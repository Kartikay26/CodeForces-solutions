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
	int n, k; cin >> n >> k;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(all(a));

	if (k == 0) {
		if (a[0] == 1) {
			cout << -1 << endl;
		} else {
			cout << a[0] - 1 << endl;
		}
		return 0;
	}

	if (k == n) {
		cout << a[n-1] << endl;
		return 0;
	}

	k--;
	int x = a[k], y = a[k+1];
	if (x == y) {
		cout << -1 << endl;
	} else {
		cout << x << endl;
	}

}