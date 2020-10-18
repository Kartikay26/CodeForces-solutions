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

int a[N], n, k;

int testcase(){
	n = get();
	k = get();
	get(a,n);
	priority_queue<tuple<int, int, int>> pq; // gain, size, div
	auto time_eat = [&] (int sz, int r) -> int{
		if (r > sz) return INT_MAX;
		return (sz/r + 1) * (sz/r + 1) * (sz%r) + (sz/r) * (sz/r) * (r - (sz%r));
	};
	for (int i = 0; i < n; ++i) {
		int sz = a[i];
		int r = 1;
		int g = time_eat(sz,r) - time_eat(sz,r+1);
		pq.push({g, sz, r});
	}
	for (int i = 0; i < k-n; ++i) {
		auto [g,sz,r] = pq.top();
		pq.pop();
		r += 1;
		g = time_eat(sz,r) - time_eat(sz,r+1);
		pq.push({g,sz,r});
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		auto [g,sz,r] = pq.top();
		pq.pop();
		ans += time_eat(sz, r);
	}
	return ans;
}

int32_t main(){
	fast_io();
	print(testcase());
	return 0;
}