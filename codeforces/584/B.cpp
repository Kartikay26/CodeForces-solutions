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

int modexp(int n, int k){
	int res = 1;
	while(k>0){
		if(k&1){
			res *= n; res %= mod;
		}
		n = n*n; n %= mod;
		k /= 2;
	}
	return res;
}

int32_t main(){
	fast_io();
	int n; cin >> n;
	int ans = (modexp(27,n) - modexp(7,n) + mod)%mod;
	cout << ans;
	return 0;
}