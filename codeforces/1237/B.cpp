// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
void print(){cout << endl;} void prints(){}
template<typename T=int> T get(){T x; cin >> x; return x;}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clear(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const int N = 1e6+1;

int32_t main(){
	fast_io();

	int n = get();
	vi a(n); get(a, n);
	vi b(n); get(b, n);
	vi new_names(n+1);
	vi c;
	debug(a);
	debug(b);
	for (int i = 0; i < n; ++i) {
		new_names[a[i]] = i+1;
	}
	for(auto x : b){
		c.push_back(new_names[x]);
	}
	debug(c);

	vi d(n);
	d[n-1] = c[n-1];
	for (int i = n-2; i >= 0; --i) {
		d[i] = min(d[i+1], c[i]);
	}
	debug(d);

	int ans = 0;
	for (int i = n-1; i >= 0; --i) {
		if(c[i] > d[i]){
			ans += 1;
		}
	}

	print(ans);

	return 0;
}