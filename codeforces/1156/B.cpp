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

bool check( string s ){
	for (int i = 0; i < s.size() - 1; ++i) {
		char c1 = s[i];
		char c2 = s[i+1];
		if(abs(c2-c1) == 1) return false;
	}
	return true;
}

void testcase(int t){
	string s;
	cin >> s;
	vi cnts(26);
	for(auto &i : s){
		cnts[i-'a']++;
	}
	string s1, s2;
	for (int i = 0; i < 26; ++i) {
		if(i&1){
			for (int j = 0; j < cnts[i]; ++j) {
				s1 += (i+'a');
			}
		} else {
			for (int j = 0; j < cnts[i]; ++j) {
				s2 += (i+'a');
			}
		}
	}
	if (check(s1+s2)) {
		cout << s1+s2 << endl;
	} else if (check(s2+s1)){
		cout << s2+s1 << endl;
	} else {
		cout << "No answer" << endl;
	}
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		testcase(i);
	}
	return 0;
}