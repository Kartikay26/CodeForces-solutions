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

	int n, m; cin >> n >> m;
	int amin, amax;
	amin = max(0ll,n-2*m);
	amax = n;
	if (m == 0) {
		cout << n << " " << n << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if ((i*(i-1))/2 < m){amax = n - i - 1;}
		else if ((i*(i-1))/2 == m){amax = n - i;}
		else { break; }
	}
	cout << amin << " " << amax << endl;
}