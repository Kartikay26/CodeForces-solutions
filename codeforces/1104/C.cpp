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
	string s; cin >> s;
	int i = 0;
	int j = 0;
	for(auto c : s){
		if (c == '0'){
			switch (i){
				case 0: cout << "1 1\n"; break;
				case 1: cout << "3 1\n"; break;
			}
			i ++; i %= 2;
		}
		if (c == '1'){
			switch (j){
				case 0: cout << "1 3\n"; break;
				case 1: cout << "2 3\n"; break;
				case 2: cout << "3 3\n"; break;
				case 3: cout << "4 3\n"; break;
			}
			j ++; j %= 4;
		}
	}
	return 0;
}