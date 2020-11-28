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

void as(bool c)
{
    if (!c) {
        cout << -1 << endl;
        exit(0);
    }
}


void solve()
{
    int n, k; cin >> n >> k;
    vector<int> v(n+1);
    map<int, vector<int>> lev;    
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        lev[v[i]].push_back(i);
    }
    int max_lev = *max_element(v.begin(), v.end());
    as(lev[0].size() == 1);
    vector<pair<int, int>> ans;
    for (int l = 1; l <= max_lev; ++l) {
        int i = 0; // index in prev lev
        int d = l == 1 ? k : k - 1;
        as(lev[l-1].size() * d >= lev[l].size());
        for (int x : lev[l]) {
            // connect x from lev[l] to y in lev[l-1]
            ans.push_back({x, lev[l-1][i/d]});
            i++;
        }
    }
    cout << ans.size() << endl;
    for (auto& [x, y] : ans) {
        cout << x << " " << y << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}