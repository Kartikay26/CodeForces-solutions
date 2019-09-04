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

int32_t main(){
	fast_io();
	int b, g, n;
	cin >> b >> g >> n;
	int x = max(0ll, n-g);
	int y = min(b, n);
	debug(x,y);
	print(y-x+1);
	return 0;
}