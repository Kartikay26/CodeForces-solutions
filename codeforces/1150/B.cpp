// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = "; _dbg(__VA_ARGS__);
#define debuga(arr, n) _dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
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
const int N = 52;

int n;
char grid[N][N];

int32_t main(){
	fast_io();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			grid[i][j] = '#';
		}
	}
	cin >> n;
	int dots = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> grid[i][j];
			dots += (grid[i][j] == '.');
		}
	}
	for (int i = 2; i <= n-1; ++i) {
		for (int j = 2; j <= n-1; ++j) {
			bool ok = true;
			for (int x = -1; x <= +1; ++x) {
				ok &= (grid[i+x][j] == '.');
			}
			for (int y = -1; y <= +1; ++y){
				ok &= (grid[i][j+y] == '.');
			}
			if(ok){
				debug(i,j);
				for (int x = -1; x <= +1; ++x) {
					grid[i+x][j] = '#';
				}
				for (int y = -1; y <= +1; ++y){
					grid[i][j+y] = '#';
				}
				dots -= 5;
			}
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = 1; j <= n; ++j) {
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	debug(dots);
	cout << (dots ? "NO" : "YES") << endl;
	return 0;
}