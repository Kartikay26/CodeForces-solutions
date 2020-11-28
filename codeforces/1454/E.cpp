// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

void testcase(int)
{
    int n;
    cin >> n;
    vector<int> adj[n+1];
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<int> cycle;
    {
        set<int> vis;
        vector<int> vec;
        function<int(int, int)> dfs = [&](int x, int p) -> int {
            if (vis.count(x)) return x;
            vis.insert(x);
            vec.push_back(x);
            for (int y : adj[x]) {
                if (y == p) continue;
                int ok = dfs(y, x);
                if (ok) return ok;
            }
            vis.erase(x);
            vec.pop_back();
            return 0;
        };
        int cyc_start = dfs(1, -1);
        bool in_cycle = false;
        for (int a : vec) {
            if (a == cyc_start) in_cycle = true;
            if (in_cycle) cycle.insert(a);
        }
    }
    vector<int> subtree_size; 
    for (int c : cycle) {
        set<int> vis;
        function<int(int)> dfs = [&](int x) -> int {
            int ans = 1;
            vis.insert(x);
            for (int y : adj[x]) {
                if (vis.count(y) or cycle.count(y))
                    continue;
                ans += dfs(y);
            }
            return ans;
        };
        subtree_size.push_back(dfs(c));
    }
    debug(cycle);
    debug(subtree_size);
    auto nc2 = [] (int n) {
        return n * (n-1) / 2;
    };
    int ans = 0;
    for (int si : subtree_size) {
        ans += (nc2(si) + si * (n - si));
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        testcase(i);
    }
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}