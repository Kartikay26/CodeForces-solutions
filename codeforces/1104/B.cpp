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
	string s;
	cin >> s;
	stack<char> st;
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if (st.size() > 0 and st.top() == c){
			st.pop();
			cnt++;
		} else {
			st.push(c);
		}
	}
	cout << (cnt%2==1 ? "Yes" : "No") << endl;
	return 0;
}