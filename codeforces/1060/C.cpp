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
	vi a(n), b(m); int a_s = 0, b_s = 0; vi as = {0}; vi bs ={0};
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; a_s += a[i]; as.push_back(a_s);
	}
	for (int j = 0; j < m; ++j) {
		cin >> b[j]; b_s += b[j]; bs.push_back(b_s);
	}
	int x; cin >> x;

	vi C(n+1), D(m+1);

	for (int l = 1; l <= n; ++l) {
		int z = 1e9;
		for (int i = 0; i <= n-l; ++i) {
			z = min(as[i+l]-as[i],z);
		}
		C[l] = z;
	}

	for (int l = 1; l <= m; ++l) {
		int z = 1e9;
		for (int j = 0; j <= m-l; ++j) {
			z = min(bs[j+l]-bs[j],z);
		}
		D[l] = z;
	}

	// debug(a);debug(b);debug(as);debug(bs);debug(C);debug(D);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if(C[i] * D[j] <= x) ans = max(ans, i*j);
		}
	}

	cout << ans << endl;

}