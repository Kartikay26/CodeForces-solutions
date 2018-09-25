#include <bits/stdc++.h>
// #include "prettyprint.hpp"
using namespace std;

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int32_t main(){
	fast_io();

	int n, m; cin >> n >> m; int ans = 0; int cur_loc = 1;
	while(m--){
		int x; cin >> x;
		if(x >= cur_loc){
			ans += (x - cur_loc);
		} else {
			ans += (n-cur_loc)+x;
		}
		cur_loc = x;
	}

	cout << ans << endl;

}