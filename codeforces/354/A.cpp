// kartikay26
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#endif

typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int N = 1e6+1;

int testcase(){
	int n, el, er, ql, qr;
	cin >> n >> el >> er >> ql >> qr;
	vector<int> w(n);
	for(auto &i : w){
		cin >> i;
	}
	int ans = LLONG_MAX;
	int tot = accumulate(all(w), 0ll);
	int p = 0;
	for (int i = 0; i <= n; ++i) {
		int extra = 0;
		int steps = 0;
		if (i < n-i) {
			steps = n-2*i - 1;
			extra = steps * qr;
		} else if (i > n-i) {
			steps = 2*i-n - 1;
			extra = steps * ql;
		}
		int cost = el * p + er * (tot-p) + extra;
		debug(cost, steps, extra);
		ans = min(ans, cost);
		if (i < n) p += w[i];
	}
	return ans;
}

int32_t main(){
	fast_io();
 	cout << testcase() << endl;
	return 0;
}