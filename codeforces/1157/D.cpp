// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = "; _dbg(__VA_ARGS__);
#define debuga(arr, n) _dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
#endif
typedef long long int ll;
#define int ll
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

int get_start(int n, int k){
	int s = max(0ll, (n - k*(k-1)/2)/k - 1);
	while (true){
		s++;
		int start = s;
		int end = s+k-1;
		int ap_sum = (start+end) * k / 2;
		int gp_sum = start * (pow(2, k) - 1);
		if ((pow(2, k) - 1) > (inf / start)) gp_sum = inf;
		if (ap_sum <= n and n <= gp_sum) return s;
		if (ap_sum > n) {
			cout << "NO\n"; exit(0);
		}
	}
}

int32_t main(){
	fast_io();
	int n, k; cin >> n >> k;
	int s = get_start(n,k);
	vi ans(k);
	for (int i = 0; i < k; ++i) {
		ans[i] = i+s;
	}
	int sm = (s+s+k-1) * k / 2;
	while (sm != n){
		int z = k-1;
		ans[z] ++;
		while (ans[z] > ans[z-1] * 2){
			ans[z] --;
			ans[z-1] ++;
			z--;
			if (z == 0 || ans[z] <= ans[z-1]){
				cout << "NO\n"; exit(0);
			}
		}
		sm ++;
	}
	cout << "YES\n";
	for (int i = 0; i < k; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}