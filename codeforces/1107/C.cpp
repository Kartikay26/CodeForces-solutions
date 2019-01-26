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

int n, k;
int a[N];
string s;

int32_t main(){
	fast_io();
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> s;
	vi change = {0};
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i-1]){
			change.push_back(i);
		}
	}
	change.push_back(n);
	debug(change);
	debuga(a, n);
	for (int i = 1; i < change.size(); ++i) {
		sort(a + change[i-1], a + change[i]);
	}
	debuga(a, n);
	int dmg = 0;
	for (int i = 1; i < change.size(); ++i) {
		// change[i-1] to change[i]
		int l = change[i-1];
		int r = change[i];
		for (int i = r-1, ct = 0; i >= l and ct < k; --i, ct++) {
			dmg += a[i];
			debug(a[i]);
		}
	}
	cout << dmg << endl;
	return 0;
}