// kartikay26
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#endif
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){} int get() {int x; cin >> x; return x;}
template<typename T> void print(T x){cout << x << endl;} template<typename T> void prints(T x){cout << x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x; prints(r...);}

const int mod = 1e9+7;
const int N = 1e6+1;

bool solve(int n);

int a[10];

void testcase(){
	int n = get();
	for (int d = 1; d <= 9; ++d) {
		cin >> a[d];
	}
	if (!solve(n)){
		print(-1);
	}
}

bool solve(int n) {
	int max_len = 0;
	int max_dig = 0;
	for (int d = 1; d <= 9; ++d) {
		if (n/a[d] > max_len) {
			max_dig = d;
			max_len = n/a[d];
		}
	}
	if (max_len == 0) return false;
	string ans = "";
	for (int i = 0; i < max_len; ++i) {
		ans += (max_dig+'0');
	}
	debug(ans);
	n -= max_len*a[max_dig];
	debug(n);
	for (int i = 0; i < max_len; ++i) {
		for (int d = 9; d > max_dig; --d) {
			if (a[d] - a[max_dig] <= n) {
				ans[i] = d+'0';
				n -= a[d] - a[max_dig];
				break;
			}
		}
	}
	cout << ans;
	return true;
}

int32_t main(){
	fast_io();
	testcase();
	return 0;
}