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

const int N = 1e5+1;
int n, t;
int a[N];
int pr_sum[N];

int32_t main(){
	fast_io();
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		cin >> a[i+1];
	}
	for (int i = 1; i <= n; ++i) {
		pr_sum[i] = pr_sum[i-1] + a[i];
	}
	// sum [i,j] = pr_sum[j] - pr_sum[i-1]
	int m = -1;
	for (int i = 1; i <= n; ++i) {
		int f = pr_sum[i-1] + t;
		// pr_sum[j] == f means that books i to j can be read
		int k = upper_bound(pr_sum, pr_sum+n+1, f) - pr_sum;
		// debug(k - i); // k - i books will be read
		m = max(m, k-i);
	}
	cout << m << endl;
}