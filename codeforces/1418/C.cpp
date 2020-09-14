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

void testcase(int t){
	
	int n; cin >> n;
	vi a(n); get(a, n);

	int min_skip[n][2] = {0}; // 0 == frd, 1 == me
	int turns[n][2] = {0}; // num of turns we have taken

	for (int i = 0; i < n; ++i) {
		min_skip[i][0] = 1e9;
		min_skip[i][1] = 1e9;
	}

	min_skip[0][0] = (a[0]);
	min_skip[0][1] = 1e9;
	turns[0][0] = 0;
	turns[0][1] = 0;

	for (int i = 1; i < n; ++i) {
		for(auto j : {0, 1}){ // 0 == frd, 1 == me
			
			for (auto prev : {0, 1}) {
				if (j == prev and turns[i-1][prev] == 2) {
					continue;
				}
				int new_skip = min_skip[i-1][prev] + (a[i]&&!j);
				if (min_skip[i][j] > new_skip) {
					min_skip[i][j] = new_skip;
					turns[i][j] = (j==prev) ? turns[i-1][prev] + 1 : 1;
				}
			}

		}
	}

	debug(arr(min_skip, n));
	debug(arr ( turns , n));
	
	print(min(min_skip[n-1][0], min_skip[n-1][1]));
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