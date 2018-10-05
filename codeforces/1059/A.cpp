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

	int n, l, a;
	cin >> n >> l >> a;

	if(n==0){
		cout << l/a << endl;
		return 0;
	}

	vector<pii> custs;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		custs.push_back({a,b});
	}
	sort(all(custs));

	int ans = 0;

	ans += custs[0].first/a;
	for (int i = 1; i < n; ++i) {
		ans += (custs[i].first - (custs[i-1].first + custs[i-1].second))/a;
	}
	ans += (l - (custs[n-1].first + custs[n-1].second))/a;

	cout << ans << endl;

}