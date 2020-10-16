// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){} int get() {int x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x; prints(r...);}

const int mod = 1e9+7;
const int N = 1e3+1;

int a[N];
int dp[N][N];

int solve(int n, int s) {
	if (dp[n][s]) return dp[n][s];
	int ans;
	if (n > s) {
		ans = (solve(n-1, s) + solve(n, n)) % mod;
	} else if (n == s) {
		ans = 2;
		for (int i = a[n]; i < n; ++i) {
			ans += solve(i, i);
			ans %= mod;
		}
	} else {
		return 0;
	}
	debug(n,s,ans);
	return dp[n][s]=ans;
}

void testcase(){
	int n = get();
	get(a, n);
	for (int i = 0; i < n; ++i) {
		a[i]--;
	}
	print(solve(n-1, 0));
}

int32_t main(){
	fast_io();
	testcase();
	return 0;
}