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
	
	int n; cin >> n;

	vi a(3); vi b(3);

	for (int i = 0; i < 3; ++i) {
		cin >> b[i] >> a[i];
	}

	int chosen = 0;
	vi ch = b;

	for (int i = 0; i < 3; ++i) {
		chosen += b[2-i];
	}

	int i = 0;
	while(chosen < n){
		int req = n - chosen;
		chosen += min(req, a[i]-b[i]);
		ch[i] += min(req, a[i]-b[i]);
		i++;
	}

	for(auto &i : ch){
		cout << i << ' ';
	}

	return 0;
}