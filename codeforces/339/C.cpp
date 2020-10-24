// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(...)
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef vector<int> vi; typedef long long int ll;

const int mod = 1e9+7;
const int N = 1e6+1;

void solve(){
	char c[11];
	for (int i = 1; i <= 10; ++i) {
		cin >> c[i];
	}

	int m; cin >> m;
	bool dp[m+1][11][11]; // turn, value, wt used
	memset(dp, 0, sizeof(dp));

	dp[0][0][0] = 1;

	for (int i = 0; i < m; ++i) {
		for (int v = 0; v < 11; ++v) {
			for (int w = 0; w < 11; ++w) {
				if (dp[i][v][w]) {
					for (int use_wt = 1; use_wt < 11; ++use_wt) {
						if (c[use_wt] == '1' and use_wt != w) {
							int new_v = use_wt - v;
							if (0 < new_v and new_v < 11){
								dp[i+1][new_v][use_wt] = 1;
							}
						}
					}
				}
			}
		}
	}

	// for (int i = 0; i <= m; ++i) {
	// 	for (int v = 0; v < 11; ++v) {
	// 		for (int w = 0; w < 11; ++w) {
	// 			cout << dp[i][v][w] <<  " ";
	// 		} cout << endl;
	// 	} cout << endl; cout << endl;
	// }

	auto find_wt = [&](int turn, int val, int last_w) -> int {
		for (int w = 0; w < 11; ++w) {
			if (w == last_w) continue;
			if (dp[turn][val][w]) {
				return w;
			}
		}
		return -1;
	};

	int final_v = 0, last_w = 0;

	for (int v = 1; v <= 10; ++v) {
		last_w = find_wt(m, v, 0);
		if (last_w != -1) {
			final_v = v;
		}
	}
	
	if (final_v == 0) {
		cout << "NO\n";
		return;
	}

	// debug(final_v, last_w);
	int cur_v = final_v;

	vi ans;

	last_w = 0;
	for (int i = m; i > 0; --i) {
		last_w = find_wt(i, cur_v, last_w);
		ans.push_back(last_w);
		cur_v = last_w - cur_v;
	}

	reverse(ans.begin(), ans.end());

	cout << "YES\n";
	for(auto &i : ans){
		cout << i << " ";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	solve();
	return 0;
}