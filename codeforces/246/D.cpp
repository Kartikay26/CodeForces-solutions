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
	int m = get();
	vector<int> c(n); get(c,n);
	map<int, set<int>> mp;
	for (int i = 0; i < m; ++i) {
		int a = get()-1;
		int b = get()-1;
		if (c[a] == c[b]) {
			continue;
		}
		mp[c[a]].insert(c[b]);
		mp[c[b]].insert(c[a]);
	}
	debug(mp);
	auto ans = max_element(all(c),
		[&](int a,int b){
			if (mp[a].size() != mp[b].size())
				return mp[a].size() < mp[b].size();
			else
				return a > b;
		});
	print(*ans);
}

int32_t main(){
	fast_io();
	solve();
	return 0;
}