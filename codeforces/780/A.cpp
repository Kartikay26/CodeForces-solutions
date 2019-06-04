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
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

int32_t main(){
	fast_io();
	int n; cin >> n; vector<int> v(2*n);
	for(auto &i : v){
		cin >> i;
	}
	vector<bool> t(n);
	int x = 0, m = 0;
	for(auto &i : v){
		if(t[i]){
			x--;
		} else {
			t[i] = 1;
			x++;
		}
		m = max(m, x);
	}
	cout << m << "\n";
	return 0;
}