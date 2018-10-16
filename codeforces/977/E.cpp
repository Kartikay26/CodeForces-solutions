#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
	#include "prettyprint.hpp"
	#define debug(x) cout << "debug: " << #x " = " << x << endl
#else
	#define debug(x) 0
#endif

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, vi> g;
map<int, bool> visited;
void dfs(int node);
vi cur_con;

int32_t main(){
	fast_io();
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	debug(g);

	int ans = 0;
	for (int node = 1; node <= n; ++node) {
		if (!visited[node]) {
			debug(node);
			dfs(node);
			ans += all_of(all(cur_con),[](int x){
				return g[x].size() == 2;
			});
			cur_con.clear();
		}
	}

	cout << ans << endl;

}

void dfs(int node){
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	cur_con.push_back(node);
	for(auto i : g[node]){
		dfs(i);
	}
}