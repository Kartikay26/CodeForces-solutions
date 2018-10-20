// kartikay26 | st0rmbring3r

#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#else
#define debug(x) 0
#endif
typedef long long int lli;
#define int lli
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e6+1;


int32_t main(){
	fast_io();
	int n; cin >> n;
	map<string, int> mp;
	map<string, string> ss;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		set<string> subs;
		for (int j = 0; j < s.size(); ++j) {
			for (int k = j; k < s.size(); ++k) {
				string sub = s.substr(j, k-j+1);
				subs.insert(sub);
			}
		}
		for(auto sub : subs){
			mp[sub]++;
			ss[sub] = s;
		}
	}

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		string p; cin >> p;
		if (mp.count(p)) {
			cout << mp[p] << " " << ss[p] << endl;
		} else {
			cout << 0 << " " << "-" << endl;
		}
	}
}