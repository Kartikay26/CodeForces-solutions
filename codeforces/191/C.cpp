// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(...)
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef vector<int> vi; typedef long long int ll;

const int mod = 1e9+7;
const int N = 1e6+1;
 
class RMQ {
    int floorLog2(int n){return (64 - __builtin_clzll(n) - 1);}
public:
    int n, maxK;
    vector<vector<int>> rmq;
    vector<vector<int>> idx;
    RMQ(vi arr) { // construct RMQ table from array in O(n log n)
        n = arr.size();
        maxK = floorLog2(n) + 1;
        rmq.assign(maxK, vi(n));
        idx.assign(maxK, vi(n));
        rmq[0] = arr;
        for (int i = 0; i < n; i++) idx[0][i] = i;
        for (int k = 1; k < maxK; k++) {
            for (int i = 0; i < n; i++) {
                if (i+(1<<(k-1)) < n) {
                    rmq[k][i] = min(rmq[k-1][i], rmq[k-1][i+(1<<(k-1))]);
                    idx[k][i] = rmq[k-1][i] <= rmq[k-1][i+(1<<(k-1))] ? idx[k-1][i] : idx[k-1][i+(1<<(k-1))];
                }
            }
        }
    }
    pair<int, size_t> minq(int l, int r) { // returns value, index of first minimum in range in O(1)
        assert(0 <= l and l <= r and r < n);
        int k = floorLog2(r-l+1);
        return {
            min(rmq[k][l], rmq[k][r+1-(1<<k)]),
            rmq[k][l] <= rmq[k][r+1-(1<<k)] ? idx[k][l] : idx[k][r+1-(1<<k)]
        };
    }
};
 
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n; cin >> n;

    vi adj[n+1];

    vector<pair<int, int>> edges;

    for (int i = 0; i < n-1; ++i) {
    	int u, v; cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    	edges.push_back({u,v});
    }

    vi d(n+1); // depth
    vi start(n+1, -1);
    vi end(n+1, -1);
    vi tour_depth;
    vi tour_node;
 
    function<void(int, int, int)> dfs = [&](int x, int h, int p) {
        d[x] = h;
        start[x] = tour_depth.size();
        tour_depth.push_back(d[x]);
        tour_node.push_back(x);
        for(auto &i : adj[x]){
        	if (i == p) continue;
            dfs(i, h+1, x);
            tour_depth.push_back(d[x]);
            tour_node.push_back(x);
        }
        end[x] = tour_depth.size();
        tour_depth.push_back(d[x]);
        tour_node.push_back(x);
    };
 
    dfs(1, 0, 0);
 
    RMQ r(tour_depth);

    int q; cin >> q;

    vi diff(n+1);
    vi edge_ans(n+1);
 
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        if (start[a] > end[b]) swap(a,b);
        int lca_node = tour_node[r.minq(start[a], end[b]).second];
        diff[a] += 1;
        diff[b] += 1;
        diff[lca_node] -= 2;
    }

    function<int(int, int)> dfs2 = [&](int node, int p) -> int {
    	int ans = diff[node];
    	for(auto child : adj[node]){
    		if (child == p) continue;
    		int down = dfs2(child, node);
    		edge_ans[child] = down;
    		ans += down;
    	}
    	return ans;
    };

    dfs2(1, 0);

    for(auto [u,v] : edges){
    	if (d[u] > d[v]) swap(u,v);
    	// u is always upper
    	cout << edge_ans[v] << " ";
    }

    cout << endl;
    return 0;
}