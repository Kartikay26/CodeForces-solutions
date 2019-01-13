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
const int N = 1e2+1;

int tabtype[N];

int32_t main(){
	fast_io();
	int n, k; cin >> n >> k;
	// debug(n,k);
	int total_E = 0, total_S = 0;
	for (int i = 0; i < n; ++i) {
		cin >> tabtype[i];
		if(tabtype[i] == 1)
			total_E++;
		else
			total_S++;
	}
	int maxabsdiff = 0;
	// debuga(tabtype, n);
	for (int b = 0; b < k; ++b) {
		int tabs_del_S = 0;
		int tabs_del_E = 0;
		for (int i = b; i < n; i += k) {
			tabs_del_E += (tabtype[i] == 1);
			tabs_del_S += (tabtype[i] == -1);
		}
		int tabs_E = total_E - tabs_del_E;
		int tabs_S = total_S - tabs_del_S;
		// debug(b,tabs_del_E, tabs_del_S);
		maxabsdiff = max(abs(tabs_E - tabs_S), maxabsdiff);
	}
	cout << maxabsdiff << endl;
	return 0;
}