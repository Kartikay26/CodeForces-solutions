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
	cout << "debug: " << s << " = [";
	while(n--){cout << *a++ << (n?", ":"");} cout << "]\n";
}
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e4+1;

int a[N];

int32_t main(){
	fast_io();
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < n*m; ++i) {
		cin >> a[i];
	}
	int z = a[0];
	for (int i = 0; i < n*m; ++i) {
		if(a[i]%d!=z%d){
			cout << -1 << endl;
			return 0;
		}
		a[i] = a[i]/d;
	}
	sort(a, a+n*m);
	int idx = (n*m-1)/2;
	int elm = a[idx];
	int ans = 0;
	for (int i = 0; i < n*m; ++i) {
		ans += abs(a[i]-elm);
	}
	cout << ans << endl;
}