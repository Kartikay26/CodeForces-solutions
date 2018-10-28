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

const int N = 1e3+1;
bool flips[N];
string s;
int n;

string dp_min[N];
string dp_max[N];
int dp_ptr_min[N];
int dp_ptr_max[N];

string solve(){
	dp_min[0] = s[0];
	dp_max[0] = s[0];
	for (int i = 1; i < n; ++i) {
		char c = s[i];
		// string: abc,d
		string last_min = dp_min[i-1];
		string last_max = dp_max[i-1];
		string rev_last_min = last_min;
		string rev_last_max = last_max;
		string &new_min = dp_min[i], &new_max = dp_max[i];
		reverse(all(rev_last_min));
		reverse(all(rev_last_max));
		if (last_min+c <= c+rev_last_max) {
			new_min = last_min+c;
			dp_ptr_min[i] = 0;
		} else {
			new_min = c+rev_last_max;
			dp_ptr_min[i] = 1;
		}
		if (last_max+c >= c+rev_last_min) {
			new_max = last_max+c;
			dp_ptr_max[i] = 0;
		} else {
			new_max = c+rev_last_min;
			dp_ptr_max[i] = 1;
		}
	}
	return dp_min[n-1];
}


int32_t main(){
	fast_io();
	cin >> s;
	n = s.size();
	string got = solve();
	// debug(got);
	int follow = 0;
	int* following = dp_ptr_min;
	// // debug
	// for (int i = 0; i < n; ++i) {
	// 	cout << dp_min[i] << ", ";
	// }
	// cout << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cout << dp_max[i] << ", ";
	// }
	// cout << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cout << dp_ptr_min[i] << ", ";
	// }
	// cout << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cout << dp_ptr_max[i] << ", ";
	// }
	// cout << endl;
	// // ----------
	vi ans;
	for (int i = n-1; i >= 0; --i) {
		if (follow == 1) {
			following = (following == dp_ptr_min ? dp_ptr_max : dp_ptr_min);
		}
		follow = following[i];
		ans.push_back(follow);
	}
	reverse(all(ans));
	for(auto i : ans){
		cout << i << " ";
	}
	cout << endl;
}