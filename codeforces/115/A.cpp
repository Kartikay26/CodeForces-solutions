#include <bits/stdc++.h>
// #include "prettyprint.hpp"
using namespace std;

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

map<int, vi> graph;
vector<int> depth;
vector<int> nums;

void dfs(int i, int d = 1){
	if (depth[i] != 0) return;
	depth[i] = d;
	for(auto n : graph[i]){
		dfs(n, d+1);
	}
}

int32_t main(){
	fast_io();
	
	int n; cin >> n;
	nums.resize(n);
	depth.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		nums[i]--;
		if (nums[i] != -2) graph[nums[i]].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		if (nums[i] == -2) {
			dfs(i);
		}
	}

	// debug(graph); debug(depth);

	cout << *max_element(all(depth)) << endl;
}
