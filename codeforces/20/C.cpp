// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

// PROBLEM: https://codeforces.com/problemset/problem/20/C

void solve()
{
	int V, E; cin >> V >> E;
	vector<pair<int, int>> adj[V]; // [edge_to, weight]
	for (int i = 0; i < E; ++i) {
		int a, b, w; cin >> a >> b >> w;
		a--; b--;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
 
	// find shortest path from 0 to (V-1)
	int par[V]; memset(par, -1, sizeof(par)); // parent
	ll dis[V]; // distance
	for (int i = 0; i < V; ++i) {
		dis[i] = LLONG_MAX;
	}
	dis[0] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push({0, 0});

	while (!pq.empty()) {
		auto [d, n] = pq.top();
		debug(n, d);
		pq.pop();
		if (n == V-1) break;
		for (auto [m, w] : adj[n]) {
			if (dis[n] + w < dis[m]) {
				debug(m);
				pq.push({d-w, m});
				par[m] = n;
				dis[m] = dis[n] + w;
			}
		}
	}

	if (par[V-1] == -1) {
		cout << -1 << endl; return;
	}
	
	vector<int> path = {};
	int cur = V-1;
	while (cur != 0) {
		path.push_back(cur);
		cur = par[cur];
	}
	path.push_back(0);
	reverse(path.begin(), path.end());
	for (auto& i : path) {
		cout << i+1 << " ";
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
	return 0;
}