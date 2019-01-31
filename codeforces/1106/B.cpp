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
const int N = 1e5+1;

int n, m;
int a[N];
int c[N];
int ind[N];
int t[N];
int d[N];

int32_t main(){
	fast_io();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> t[i] >> d[i];
		t[i]--;
	}
	/// ---------------
	for (int i = 0; i < n; ++i) {
		ind[i] = i;
	}
	sort(ind, ind+n, [=](int a, int b){return c[a] < c[b];});
	int cheap_x = 0;
	bool stopflag = 0;
	debuga(ind, n);
	for (int i = 0; i < m; ++i) {
		int total_cost = 0;
		// solve customer i
		// ordered t-th kind - d-i dishes
		if(stopflag){
			cout << 0 << endl;
			continue;
		}
		int serve = d[i]; int dish = t[i];
		// debug(serve, dish);
		// debuga(a, n);
		while (serve > 0){
			// debug(serve, dish, total_cost);
			if(a[dish] >= serve){
				a[dish] -= serve;
				total_cost += serve * c[dish];
				serve = 0;
			} else {
				// first finish this
				total_cost += a[dish] * c[dish];
				serve -= a[dish];
				a[dish] = 0;
				dish = ind[cheap_x];
				while (a[dish] == 0) {
					cheap_x++;
					dish = ind[cheap_x];
					if(cheap_x == n){
						stopflag = 1;
						total_cost = 0;
						break;
					}
				}
			}
			if(stopflag) break;
			// debug(serve, dish);
			// debuga(a, n);
		}
		// if(!stopflag)
		cout << total_cost << endl;
	}
	return 0;
}