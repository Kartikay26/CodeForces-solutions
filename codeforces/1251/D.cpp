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
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
const int mod = 1e9+7;
const int N = 1e6+1;
 
void testcase(int t){
	
	using emp = pii;
	int n, s; cin >> n >> s;

 
	vector<emp> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
 
	auto check = [&](int m){
		vector<emp> rem;
		int less_done = 0, more_done = 0;
		int min_cost = 0;
		for(auto [l, r] : v){
			if (r < m){
				less_done++;
				min_cost += l;
			} else if (l > m){
				more_done++;
				min_cost += l;
			} else {
				rem.push_back({l, r});
			}
		}
		sort(all(rem));
		for(auto [l, r] : rem){
			if (less_done < n/2){
				min_cost += l;
				less_done++;
			} else {
				more_done++;
				min_cost += max(m, l);
			}
		}
		if (less_done > n/2){
			return false;
		}
		return min_cost <= s;
	};
 
	int x = 0;
	// find last true
	debug(t);
	for (int b = s; b >= 1; b /= 2) {
		while(check(x+b)) x += b;
		debug(x);
	}
 
	print(x);
 
}
 
int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		testcase(i);
	}
	return 0;
}