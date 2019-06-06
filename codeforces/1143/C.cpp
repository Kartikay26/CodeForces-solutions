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
const int N = 1e5+1;

int n;
int p[N];
int c[N];
int x[N];

vi children[N];
vi del;

void dfs(int i){
	if(x[i]) del.push_back(i);
	for(auto &j : children[i]){
		dfs(j);
	}
}

int32_t main(){
	fast_io();
	cin >> n;
	int root = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i] >> c[i];
		if (p[i] == -1){
			root = i;
		} else {
			children[p[i]].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		x[i] = c[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i] != -1)
			x[p[i]] &= c[i];
	}
	dfs(root);
	if (del.size() == 0){
		cout << -1;
		return 0;
	}
	sort(all(del));
	for(auto &i : del){
		cout << i << " ";
	}
	return 0;
}