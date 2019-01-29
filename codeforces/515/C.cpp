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
	string s; cin >> s;
	string ans;
	for(auto c : s){
		switch(c){
			case '0': case '1': break;
			case '2': ans += "2"; break;
			case '3': ans += "3"; break;
			case '4': ans += "223"; break;
			case '5': ans += "5"; break;
			case '6': ans += "35"; break;
			case '7': ans += "7"; break;
			case '8': ans += "2227"; break;
			case '9': ans += "2337"; break;
		}
	}
	sort(all(ans));
	reverse(all(ans));
	cout << ans << endl;
	return 0;
}