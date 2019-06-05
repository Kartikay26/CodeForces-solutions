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
const int N = 1e2+1;

int a[N][N]; int n;

int32_t main(){
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	vi good;
	for (int i = 0; i < n; ++i) {
		bool g = true;
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == 1 or a[i][j] == 3){
				g = false;
			}
		}
		if (g) good.push_back(i);
	}
	cout << good.size() << endl;
	for(auto &i : good){
		cout << i+1 << ' ';
	}
	cout << endl;
	return 0;
}