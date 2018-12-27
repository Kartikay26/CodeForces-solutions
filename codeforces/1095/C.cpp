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

int repr[64];

int32_t main(){
	fast_io();
	int n, k;
	cin >> n >> k;
	int lastpower = -1;
	for (int i = 0; i < 63; ++i) {
		repr[i] = bool(n&(1ll<<i));
		if(repr[i]) lastpower = i;
	}
	int cnt = accumulate(repr, repr+64, 0ll);
	if (cnt > k or k > n) {
		cout << "NO\n";
		return 0;
	} else {
		cout << "YES\n";
	}
	// increase cnt until it becomes = k
	// debug(lastpower);
	while(cnt != k){
		repr[lastpower]--;
		++(++repr[lastpower-1]);
		if(!repr[lastpower]) lastpower--;
		cnt++;
	}
	// debuga(repr, 7);
	for (int i = 0; i < 63; ++i) {
		for (int j = 0; j < repr[i]; ++j) {
			cout << (1<<i) << " ";
		}
	}
	cout << endl;
	return 0;
}