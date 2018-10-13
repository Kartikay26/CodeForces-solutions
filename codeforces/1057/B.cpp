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

	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vi pr_a(n);
	int s = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i];
		pr_a[i] = s;
	}
	int m = 0;
	for (int l = 0; l < n; ++l) {
		for (int r = l; r < n; ++r) {
			int cur_sum = pr_a[r] - (l>0?pr_a[l-1]:0);
			if (cur_sum > 100*(r-l+1)) {
				m = max(m, r-l+1);
			}
		}
	}
	cout << m << endl;
}