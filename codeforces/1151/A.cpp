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
const int N = 1e6+1;

int32_t main(){
	fast_io();
	int mini = inf;
	int l; cin >> l;
	string inp; cin >> inp;
	for (int i = 0; i <= l - 4; ++i) {
		string str2 = inp.substr(i, 4);
		int m = 0, k = 0;
		k = ((str2[0] - 'A') - ('A' - 'A') + 26) % 26;
		m += min(k, 26 - k);
		k = ((str2[1] - 'A') - ('C' - 'A') + 26) % 26;
		m += min(k, 26 - k);
		k = ((str2[2] - 'A') - ('T' - 'A') + 26) % 26;
		m += min(k, 26 - k);
		k = ((str2[3] - 'A') - ('G' - 'A') + 26) % 26;
		m += min(k, 26 - k);
		mini = min(mini, m);
	}
	cout << mini << endl;
	return 0;
}