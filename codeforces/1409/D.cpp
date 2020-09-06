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
void print(){cout << endl;} void prints(){}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}

const int mod = 1e9+7;
const int N = 1e6+1;

int sum(int n) {
	string s = to_string(n);
	int ans = 0;
	for(auto c : s){
		ans += (c-'0');
	}
	return ans;
}

int testcase(int t){
	
	int n, s; cin >> n >> s;

	if (sum(n) <= s) return 0;

	int p, ans = LLONG_MAX;
	for (p = 1; p < n; p *= 10) {
		int n2 = p * (n/p + 1);
		if (sum(n2) <= s) {
			ans = min(ans, n2 - n);
		}
	}
	int n2 = p;
	ans = min(ans, n2 - n);

	return ans;
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		print(testcase(i));
	}
	return 0;
}