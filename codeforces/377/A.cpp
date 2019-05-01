// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
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
const int N = 500+2;

int n, m, k, save;
char a[N][N];
bool vis[N][N];

void dfs(int i, int j){
	if (vis[i][j]) return;
	save--;
	if(save < 0) return;
	else a[i][j] = 'S';
	vis[i][j] = true;
	if (a[i+0][j+1] == '.') dfs(i+0, j+1);
	if (a[i+1][j+0] == '.') dfs(i+1, j+0);
	if (a[i+0][j-1] == '.') dfs(i+0, j-1);
	if (a[i-1][j+0] == '.') dfs(i-1, j+0);
}

int32_t main(){
	fast_io();
	cin >> n >> m >> k;
	fill((char*) a, (char*) a+N*N, '#');
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			save += (a[i][j] == '.');
		}
	}
	save -= k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '.'){
				dfs(i,j);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '.'){
				cout << 'X';
			} else if (a[i][j] == 'S') {
				cout << '.';
			} else {
				cout << '#';
			}
		}
		cout << '\n';
	}
	return 0;
}