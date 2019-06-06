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

vi c[N];
int d[N];

void color(int i){
	set<int> colors_unused = {1,2,3};
	for(auto j : c[i]){
		if(d[j]) colors_unused.erase(d[j]);
	}
	d[i] = *colors_unused.begin();
	for(auto j : c[i]){
		if(!d[j]) color(j);
	}
}

int32_t main(){
	fast_io();
	int n; cin >> n; int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int x,y,z;
		cin >> x >> y >> z;
		c[x].push_back(y);
		c[x].push_back(z);
		c[y].push_back(x);
		c[y].push_back(z);
		c[z].push_back(x);
		c[z].push_back(y);
	}
	for (int i = 1; i <= n; ++i) {
		if (!d[i]) color(i);
		cout << d[i] << " ";
	}
	return 0;
}