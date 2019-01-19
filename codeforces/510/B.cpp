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
const int N = 51;

int n, m;

char a[N][N];

int v[N][N];

bool adj(int i1, int j1, int i2, int j2){
	if (!(i2 >= 1 and i2 <= n and j2 >= 1 and j2 <= m)){
		return false;
	}
	if (v[i2][j2] == 0) {
		return a[i1][j1] == a[i2][j2];
	}
	if (v[i1][j1] - v[i2][j2] == 1){
		return false;
	}
	if (v[i1][j1] - v[i2][j2] > 1 and a[i1][j1] == a[i2][j2]){
		cout << "Yes" << endl;
		exit(0);
	}
	return 0; // should not execute
}

void dfs(int i, int j, int d = 1){
	v[i][j] = d;
	if(adj(i,j,i+1,j)) dfs(i+1,j,d+1);
	if(adj(i,j,i,j+1)) dfs(i,j+1,d+1);
	if(adj(i,j,i-1,j)) dfs(i-1,j,d+1);
	if(adj(i,j,i,j-1)) dfs(i,j-1,d+1);
}

int32_t main(){
	fast_io();

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if(v[i][j] == 0){
				dfs(i,j);
			}
		}
	}

	cout << "No" << endl;

	return 0;
}