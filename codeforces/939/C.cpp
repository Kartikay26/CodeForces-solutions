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
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}

const int mod = 1e9+7;
const int N = 1e6+1;

void solve(){
	int n = get();
	vector<int> a(n); get(a,n);
	int s = get()-1;
	int f = get()-1;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (s <= i and i < f) sum += a[i];
	}
	int l = s, r = f;
	int ans = 0, max_sum = sum;
	for (int i = 0; i < n; ++i) {
		debug(i,l,r,sum);
		if (sum > max_sum) {
			ans = i; max_sum = sum;
		}
		l--; r--; l = (l+n)%n; r = (r+n)%n;
		sum += a[l]; sum -= a[r];
	}
	print(ans+1);
}

int32_t main(){
	fast_io();
	solve();
	return 0;
}