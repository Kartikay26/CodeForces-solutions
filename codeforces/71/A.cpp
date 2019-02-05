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
void test()
{
	string s;
	cin >> s;
	if(s.length()>10) {
		cout << s[0] << s.length()-2 << s[s.length()-1] <<endl;
	} else {
		cout << s << endl;
	}
}
const int mod = 1e9+7;
const int N = 1e6+1;

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	while(t--)
		test();
	return 0;
}