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
	
	int n; cin >> n;
	bool all_even_len = 1;
	bool odd_odd = 0;
	int ones = 0;
	int zeros = 0;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for(auto c : s){
			ones += (c == '1');
			zeros += (c == '0');
		}
		all_even_len &= (s.size() % 2 == 0);
		odd_odd ^= (s.size() % 2 == 1);
	}
	int o = 0, e = 0;
	for(int x : {ones, zeros}){
		o += (x%2 == 1);
		e += (x%2 == 0);
	}
	debug(o, e);
	debug(all_even_len);
	debug(odd_odd);
	if (o == 1 and e == 1){
		print(n);
	} else if (o == 2) {
		print(n - all_even_len);
	} else if (e == 2) {
		print(n - odd_odd);
	}
	
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