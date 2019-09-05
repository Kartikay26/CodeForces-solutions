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
const int N = 1e6+1;

void testcase(int t){
	vi blows;
	int n, x; cin >> n >> x;
	int m = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		blows.push_back(a - b);
		m = max(m, a);
	}
	int max_blow = *max_element(all(blows));
	int reduce = x - m;
	if (reduce <= 0){
		print(1);
		return;
	}
	if (max_blow <= 0){
		print(-1);
	} else {
		int ans = ((reduce + max_blow - 1) / max_blow) + 1;
		print(ans);
	}
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		testcase(i);
	}
	return 0;
}