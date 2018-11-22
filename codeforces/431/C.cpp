// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#define debuga(arr, n) dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
#endif
typedef long long int ll;
#define int ll
template<typename T> void dbga(T* a, int n, string s){
	cout << "debug: " << s << "= [";
	while(n--){cout << *a++ << (n?", ":"");} cout << "]\n";
}
#define F first
#define S second
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;
int paths_k[N];
int paths_d[N];

int32_t main(){
	fast_io();
	int n, k, d;
	cin >> n >> k >> d;
	paths_k[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for(int z = 1; z <= k; z++)
			if(i>=z) {paths_k[i] += paths_k[i-z]; paths_k[i] %= mod;}
	}
	paths_d[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for(int z = 1; z <= d-1; z++)
			if(i>=z) {paths_d[i] += paths_d[i-z]; paths_d[i] %= mod;}
	}
	debuga(paths_k, n+1);
	debuga(paths_d, n+1);
	cout << (paths_k[n] - paths_d[n] + mod)%mod << endl;
}