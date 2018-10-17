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
	int n; cin >> n;
	vi arr(n);
	map<int, int> f;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		f[arr[i]]++;
	}
	vi	ans;
	for (int i = 0; i < n; ++i) {
		f[arr[i]]--;
		if(!f[arr[i]]) ans.push_back(arr[i]);
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i << " ";
	}
	cout << endl;

}