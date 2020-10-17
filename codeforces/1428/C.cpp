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
template<typename T, typename... A> void prints(T x,A... r){cout << x;prints(r...);}

const int mod = 1e9+7;
const int N = 1e6+1;

int testcase(int t){
	string s; cin >> s;
	stack<char> stk;
	for(auto x : s){
		if (x == 'A') {
			stk.push('A');
		} else { // x == 'B';
			if (!stk.empty() && stk.top() == 'A') {
				stk.pop();
			} else if (!stk.empty() && stk.top() == 'B') {
				stk.pop();
			} else {
				stk.push('B');
			}
		}
	}
	return stk.size();
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