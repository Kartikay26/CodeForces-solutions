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
const int N = 1e5+1;

map<int, vi> graph;
bool visited[N];

int32_t main(){
	fast_io();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	priority_queue<int> pq;
	pq.push(-1);
	while(!pq.empty()){
		int node = -pq.top();
		pq.pop();
		if(visited[node]) continue;
		visited[node] = true;
		cout << node << " ";
		for(auto i : graph[node]){
			if(!visited[i])
				pq.push(-i);
		}
	}
	return 0;
}