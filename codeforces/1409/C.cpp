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
	
	int n, x, y; cin >> n >> x >> y;

	int d = y - x;

	int cf = 0;

	for (int f = 1; f <= d; f++) {
		if (d % f) continue;
		debug(d, f, d/f+1);
		if ((d / f) + 1 <= n) {
			cf = f;
			break;
		}
	}

	int cd =  cf;

	debug(x, y, cd);

	int of = 0;
	int last = y - (n-1) * cd + (of * cd);
	while (last <= 0) {
		of ++;
		last = y - (n-1) * cd + (of * cd);
		debug(last, of);
	}


	int a = y;
	for (int i = 0; i < n; ++i) {
		prints(a + (of * cd));
		a -= cd;
	}
	print();
	
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