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
const int N = 1e3+1;

int n, s;
int v[N];

int32_t main(){
	fast_io();
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v, v+n);
	int v0 = v[0];
	// make all equal to v0
	for (int i = n-1; i >= 1; --i) {
		s -= (v[i] - v0);
		if(s <= 0){
			cout << v0 << endl;
			return 0;
		}
	}
	// if still s is left, remove n units at a time
	// i.e. (s/n)*n units can be recovered, v0 - ceil(s/n) should be answer
	// if v0 * n > s
	if (v0 * n < s){
		cout << -1 << endl;
		return 0;
	}
	int ans =  v0 - ceil(double(s)/n);
	cout << ans << endl;
	return 0;
}
