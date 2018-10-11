#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#include "prettyprint.hpp"
	#define debug(x) cout << "debug: " << #x " = " << x << endl
#else
	#define debug(x) 0
#endif

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

int32_t main(){
	fast_io();
	int n, k; cin >> n >> k;
	vi hs(n); for (int i = 0; i < n; ++i) {
		cin >> hs[i];
	}
	int minh = *min_element(all(hs));
	for (int i = 0; i < n; ++i) {
		hs[i] -= minh;
	}
	int maxh = *max_element(all(hs));
	vi elms_diff_arr(maxh+1);
	for (int i = 0; i < n; ++i) {
		int x = hs[i];
		elms_diff_arr[0] += 1;
		elms_diff_arr[x] -= 1;
	}
	
	vi elms(maxh+1);
	int cnt = 0;
	for (int i = 0; i < maxh; ++i) {
		cnt += elms_diff_arr[i];
		elms[i] = cnt;
	}
	
	int ans = 0, taken = 0;
	int q = elms.size();
	for (int i = 0; i < q;) {
		int x = elms[q-i-1];
		if(taken+x<k){
			taken += x;
			i++;
		}
		else if (taken+x==k) {
			ans++;
			taken = 0;
			i++;
		}
		else if (taken+x>k) {
			ans++;
			taken = x;
			i++;
		}
	}
	if (taken > 0) {
		ans++;
	}
	cout << ans << endl;
}