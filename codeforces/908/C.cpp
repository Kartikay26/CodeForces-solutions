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
	int n, r; cin >> n >> r;
	vi x(n);
	for(auto &i : x){
		cin >> i;
	}
	vector<db> y(n);
	for (int i = 0; i < n; ++i) {
		int x2 = x[i];
		vector<db> yp = {db(r)};
		for (int j = 0; j < i; ++j) {
			int x1 = x[j];
			db y1 = y[j];
			if ((4*r*r) >= pow(x1-x2, 2)){
				db y2 = y1 + sqrt((4*r*r) - pow(x1-x2, 2));
				yp.push_back(y2);
			}
		}
		y[i] = * max_element(all(yp));
	}
	cout << setprecision(12);
	for(auto &i : y){
		cout << i << " ";
	}
	return 0;
}