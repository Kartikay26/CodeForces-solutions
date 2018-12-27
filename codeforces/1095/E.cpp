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
const int N = 1e6+2;

int a[N], mr[N], ml[N];

int32_t main(){
	fast_io();
	int n; cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i-1] + (s[i-1]=='('?1:-1);
	}
	int m = a[n];
	for (int i = n; i >= 0; --i) {
		m = min(m, a[i]);
		mr[i] = m;
	}
	m = a[0];
	for (int i = 0; i < n; ++i) {
		m = min(m, a[i]);
		ml[i+1] = m;
	}
	const char* x = s.c_str();
	debuga(x, n+1);
	debuga(a,n+1);
	debuga(ml,n+1);
	debuga(mr,n+1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if(s[i] == '('){
			if(a[n]-2 == 0 and mr[i+1]-2 >= 0 and ml[i+1] >= 0) ans++;
		} else if (s[i] == ')') {
			if(a[n]+2 == 0 and mr[i+1]+2 >= 0 and ml[i+1] >= 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}