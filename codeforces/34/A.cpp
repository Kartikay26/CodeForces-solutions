// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifdef LOCAL
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
	vi a(n); for(auto &i : a){ cin >> i; }
	vector<pii> p;
	for (int i = 0; i < n; ++i) {
		p.push_back({i,(i+1)%n});
	}
	auto key = [=](pii x){ return abs(a[x.first] - a[x.second]); };
	pii ans = *max_element(all(p),
		[=](pii a, pii b){return key(a) > key(b);});
	cout << ans.first+1 << ' ' << ans.second+1;
	return 0;
}