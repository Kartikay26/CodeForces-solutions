// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#else
#define debug(...) 0
#endif
typedef long long int ll;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e6+1;
map<string, int> db;

int32_t main(){
	fast_io();
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		if (!db.count(s)) {
			db[s] = 1;
			cout << "OK\n";
		} else {
			int i = db[s]++;
			db[s+to_string(i)] = 1;
			cout << s+to_string(i) << endl;
		}
	}
}