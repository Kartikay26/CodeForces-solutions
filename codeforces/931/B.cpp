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
	int n,a,b; cin >> n >> a >> b;
	int z = (a-1)^(b-1);
	int ans = sizeof(int)*8 - __builtin_clzll(z);
	if (1<<ans == n) {
		cout << "Final!" << endl;
	} else {
		cout << ans << endl;
	}
}