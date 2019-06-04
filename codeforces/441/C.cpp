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
	int n, m, k; cin >> n >> m >> k;
	vector<pii> coord;
	for (int i = 1; i <= n; i++){
		if (i % 2 == 1){
			for (int j = 1; j <= m; j++){
				coord.push_back({i,j});
			}
		} else {
			for (int j = m; j >= 1; j--){
				coord.push_back({i,j});
			}
		}
	}
	debug(coord);
	int z = n*m / k;
	int p = 0;
	for (int i = 0; i < k-1; i++){
		cout << z << " ";
		for (int j = 0; j < z; j++){
			cout << coord[p].first << " ";
			cout << coord[p].second << " ";
			p++;
		}
		cout << endl;
	}
	cout << n*m - p << " ";
	while (p < n*m){
		cout << coord[p].first << " ";
		cout << coord[p].second << " ";
		p++;
	}
	return 0;
}