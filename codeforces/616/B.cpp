#include <bits/stdc++.h>
// #include "prettyprint.hpp"
using namespace std;

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int32_t main(){
	fast_io();

	int n, m;
	cin >> n >> m;
	int a[n]; // stores min of each street
	for (int i = 0; i < n; ++i) {
		a[i] = 1e9;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			a[i] = min(x, a[i]);
		}
	}

	cout << *max_element(a, a+n) << endl;
}