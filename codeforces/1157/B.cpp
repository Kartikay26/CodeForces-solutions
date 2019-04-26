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

int32_t main(){
	fast_io();
	int n; cin >> n;
	char a[n];
	int f[10];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= 9; ++i) {
		cin >> f[i];
	}
	set<int> decnum;
	set<int> incnum;
	for (int i = 1; i <= 9; ++i) {
		if(f[i] < i){
			decnum.insert(i);
		}
	}
	for (int i = 1; i <= 9; ++i) {
		if(f[i] > i){
			incnum.insert(i);
		}
	}
	bool flag=false;
	debug(decnum);
	debug(incnum);
	for (int i = 0; i < n; ++i) {
		int d = a[i] - '0';
		if(incnum.count(d))
			flag=true;
		if(flag && decnum.count(d))
			break;
		debug(d,flag);
		if(flag)
			a[i] = (f[d] + '0');
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i];
	}
	return 0;
}