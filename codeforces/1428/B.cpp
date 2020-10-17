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

int testcase(){
	int n = get();
	string s; cin >> s;
	int ans = 0;
	int lc = 0, ec = 0, rc = 0;
	for(auto x : s){
		if (x == '<') {
			lc++;
		} else if (x == '-') {
			ec++;
		} else if (x == '>') {
			rc++;
		}
	}
	if (lc && rc) {
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int l = (i-1+n)%n;
			int r = i;
			if (s[l] == '-' or s[r] == '-') {
				ans++;
			}
		}
		return ans;
	} else {
		// only left or only right
		return n;
	}
}

int32_t main(){
	fast_io();
	int t = get();
	for (int i = 0; i < t; ++i) {
		print(testcase());
	}
	return 0;
}