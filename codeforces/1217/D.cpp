#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[5001];
pair<int, int> edges[5001];

int max_color = 1;

int n, m;
int color[5001];
int vis[5001];

void dfs(int i){
	vis[i] = 1;
	for(auto [j,z] : adj[i]){
		if (!vis[j]){
			dfs(j);
		}
		if (vis[j] == 1){
			// cout << "cycle detected! " << i << " -> " << j << endl;
			max_color = 2;
			color[z] = 1;
		}
	}
	vis[i] = 2;
}

void colorise(){
	for(int i = 0; i < n; i++){
		if(!vis[i]) dfs(i);
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back({v, i});
		edges[i] = {u,v};
	}

	colorise();
	
	cout << max_color << endl;
	for(int i = 0; i < m; i++){
		cout << color[i] + 1 << " ";
	}
	cout << endl;
}
