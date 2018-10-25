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

int32_t main(){
	fast_io();
	
	int n; cin >> n;

	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ptr = 0;
	set<int> bp;

	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (bp.count(x)) {
			cout << "0 ";
		} else {
			int ct = 0;
			while(a[ptr] != x){
				bp.insert(a[ptr]);
				ptr++;
				ct++;
			}
			bp.insert(a[ptr]);
			ptr++;
			ct++;
			cout << ct << " ";
		}
	}

	cout << endl;

}