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

void test()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    function<pair<int,int>(int, int)> dfs = [&](int n, int p) -> pair<int, int> {
        int ans_u = 0;
        int ans_d = 0;
        for (int m : adj[n]) {
            if (m != p) {
                auto [u, d] = dfs(m, n);
                ans_u = max(ans_u, u);
                ans_d = max(ans_d, d);
            }
        }
        int new_val = val[n] + ans_u - ans_d;
        if (new_val > 0) ans_d += new_val;
        if (new_val < 0) ans_u -= new_val;
        return {ans_u, ans_d};
    };
    auto [u, d] = dfs(0, -1);
    cout << u+d << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}