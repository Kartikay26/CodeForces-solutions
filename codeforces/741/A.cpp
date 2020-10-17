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
const int N = 1e6+1;

int a[N];
int vis[N];

int dfs(int n) {
	int len = 0;
	int x = n;
	do {
		vis[x] = true;
		x = a[x];
		len++;
	} while (!vis[x]);
	if (x == n)
		return len;
	return -1;
}

void testcase(){
	int n = get();
	get(a+1,n);
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			int c = dfs(i);
			if (c == -1) {ans = -1; break;}
			if (c%2==0) c /= 2;
			ans = lcm(ans, c);
		}
	}
	print(ans);
}

int32_t main(){
	fast_io();
	testcase();
	return 0;
}