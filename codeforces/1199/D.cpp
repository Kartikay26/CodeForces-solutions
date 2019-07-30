// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(...)
#define debuga(arr, n)
#define debugg(grid, n) 
#endif
typedef long long int ll;
#define int ll
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
int get() { int x; cin >> x; return x; }
void getl(int* ar, int sz){ for(int i=0; i<sz; i++) cin >> ar[i];}
template <typename T> void print(T x) { cout << x << "\n";}
template <typename T> void prints(T x) { cout << x << " ";}
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 2e5+2;

int n, q;
int a[N];
int u[N];
int mp[N];

int32_t main(){
	fast_io();
	n = get();
	getl(a, n);
	q = get();
	for (int i = 0; i < q+1; ++i) {
		mp[i] = -1;
	}
	for (int i = 0; i < q; ++i) {
		// query
		int x = get();
		if (x == 1){
			// set array value
			int j = get() - 1;
			int p = get();
			a[j] = p;
			u[j] = i;
		} else {
			// set mp values
			int p = get();
			mp[i] = p;
		}
	}
	// for (int i = 1; i < q+1; ++i) {
	// 	if(mp[i] == -1){
	// 		mp[i] = mp[i-1];
	// 	}
	// }
	for (int i = q-1; i >= 0; --i) {
		mp[i] = max(mp[i], mp[i+1]);
	}
	debuga(a, n);
	debuga(u, n);
	debuga(mp, q);
	for (int i = 0; i < n; ++i) {
		cout << max(a[i], mp[u[i]]) << " ";
	}
	return 0;
}