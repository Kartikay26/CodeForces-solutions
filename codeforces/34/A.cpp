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

int diff(pii x){
	auto [a,b] = x;
	return abs(a-b);
}

int32_t main(){
	fast_io();
	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	pii ans = {a[0],a[1]};
	pii idx = {0,1};
	for (int i = 0; i < n; ++i){
		int j = (i+1) % n;
		if (diff(ans) > diff({a[i],a[j]})){
			ans = {a[i], a[j]};
			idx = {i,j};
		}
	}
	cout << idx.first + 1 << ' ' << idx.second + 1 << '\n';
	return 0;
}