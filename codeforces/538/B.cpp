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

const int N = 2e6;
vi qb_nums = {};
int dp[N];
int dp_par[N];

int dec2bin(int n){
	int ans = 0;
	int place = 1;
	while(n){
		ans += place*(n&1);
		n/=2; place *= 10;
	}
	return ans;
}

int32_t main(){
	fast_io();
	fill(dp, dp+N, -1);
	fill(dp_par, dp_par+N, -1);
	for (int i = 0; i <= (1<<6); ++i) {
		qb_nums.push_back(dec2bin(i));
	}
	// debug(qb_nums);
	for(auto i : qb_nums){
		dp[i] = 1;
		dp_par[i] = i;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for(auto k : qb_nums){
			if (dp[i+k] == -1 or dp[i+k] > dp[i]+1) {
				dp[i+k] = dp[i]+1;
				dp_par[i+k] = k;
			}
		}
	}
	cout << dp[n] << endl;
	int now = n;
	while(now){
		cout << dp_par[now] << " ";
		now -= dp_par[now];
	} cout << endl;
}