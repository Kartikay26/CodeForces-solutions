#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
	#include "prettyprint.hpp"
	#define debug(x) cout << "debug: " << #x " = " << x << endl
#else
	#define debug(x) 0
#endif

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

int32_t main(){
	fast_io();
	int n, k, m; cin >> n >> k >> m;
	multiset<int> mst;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		mst.insert(x);
	}
	vector<vi> rems(m);
	bool done = false; int done_idx = -1;
	for(auto i : mst){
		rems[i%m].push_back(i);
		if (rems[i%m].size()==k) {
			done = true;
			done_idx = i%m;
			break;
		}
	}
	if (done) {
		cout << "Yes\n";
		int i = done_idx;
		for (int j = 0; j < k; ++j) {
			cout << rems[i%m][j] << " ";
		}
		cout << endl;
	} else {
		cout << "No" <<endl;
	}
}