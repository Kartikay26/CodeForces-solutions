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
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < n-2; ++i) {
		if (s[i] == 'x' and s[i+1]=='x' and s[i+2]=='x') {
			cnt++;
		}
	}
	cout << cnt << endl;
}