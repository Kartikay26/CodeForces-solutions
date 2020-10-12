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

struct BIT {
	// 1-indexed BIT. range 1 to n inclusive.
	vector<int> arr;
	BIT(int n) {
		arr.resize(n+1);
	}
	void add(int x, int delta) {
		assert(x > 0 && x < arr.size());
		for (int u = x; u < arr.size(); u += u&-u)
			arr[u] += delta;
	}
	void inc(int x) { add(x, 1); }
	int query(int r) {
		assert(r > 0 && r < arr.size());
		int a = 0;
		for (int q = r; q > 0; q -= q&-q)
			a += arr[q];
		return a;
	}
	int query(int l, int r) {
		assert(r > l && l > 0 && r < arr.size());
		if (l == 1) return query(r);
		return query(r) - query(l-1);
	}
};

int inv(vi& a){
	int ans = 0;
	int n = a.size();
	BIT b(n+1);
	for(auto x : a){
		ans += b.query(x);
		b.inc(x);
	}
	return n*(n-1)/2 - ans;
}

void solve(){
	int n = get();
	string s; cin >> s;
	map<char, vi> c;
	map<char, vi> m;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		c[s[i]].push_back(i);
		m[s[i]].push_back(n-i-1);
	}
	for(auto& [ch,idxs] : c){
		reverse(all(m[ch]));
		for (int i = 0; i < idxs.size(); ++i) {
			a[idxs[i]] = m[ch][i]+1;
		}
	}
	debug(a);
	print(inv(a));
}

int32_t main(){
	fast_io();
	solve();
	return 0;
}