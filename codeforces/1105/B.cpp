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

int n, k;

int level(string& s, char x){
	int l = 0;
	int cnt = 0;
	for(auto c : s){
		if(c == x){
			cnt ++;
			if(cnt == k){
				l ++;
				cnt = 0;
			}
		} else {
			cnt = 0;
		}
	}
	return l;
}

int32_t main(){
	fast_io();
	cin >> n >> k;
	string s;
	cin >> s;
	int l = 0;
	for (char i = 'a'; i <= 'z'; ++i) {
		// for each alphabet, check level
		l = max(l, level(s, i));
	}
	cout << l << endl;
	return 0;
}