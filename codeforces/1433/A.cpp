// kartikay26
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
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

const int mod = 6e9+7;
const int N = 6e6+1;

vector<int> s = {
	1,
	11,
	111,
	1111,
	2,
	22,
	222,
	2222,
	3,
	33,
	333,
	3333,
	4,
	44,
	444,
	4444,
	5,
	55,
	555,
	5555,
	6,
	66,
	666,
	6666,
	7,
	77,
	777,
	7777,
	8,
	88,
	888,
	8888,
	9,
	99,
	999,
	9999,
};

int testcase(){
	int n; cin >> n;
	int ans = 0;
	for(auto &i : s){
		ans += to_string(i).size();
		if (i == n) {
			return ans;
		}
	}
	return 0;
}

int32_t main(){
	fast_io();
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		print(testcase());
	}
	return 0;
}