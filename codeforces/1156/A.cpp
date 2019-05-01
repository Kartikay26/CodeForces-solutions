// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#else
#define debug(...)
#define debuga(arr, n)
#define debugg(grid, n) 
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
	int n; cin >> n;
	int points = 0;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		debug(a[i], points);
		if (i>=2 and a[i] == 2 and a[i-1] == 1 and a[i-2] == 3) { points += 2; continue; }
		if (a[i] == 2 and a[i-1] == 1) { points += 3; continue; }
		if (a[i] == 3 and a[i-1] == 1) { points += 4; continue; }
		if (a[i] == 1 and a[i-1] == 2) { points += 3; continue; }
		if (a[i] == 1 and a[i-1] == 3) { points += 4; continue; }
		cout << "Infinite\n";
		exit(0);
	}
	cout << "Finite\n";
	cout << points << endl;
	return 0;
}