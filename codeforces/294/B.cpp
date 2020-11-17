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
    vector<pair<int, int>> v(n); // profit, cost
    int T = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        v[i].second += v[i].first;
        T += v[i].first;
    }
    int dp[n][T+1]; // profit = dp[item][max_cost]
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        auto [p, c] = v[i];
        for (int j = 0; j <= T; ++j) {
            if (i) {
                dp[i][j] = dp[i-1][j];
            }
            if (j >= c) {
                dp[i][j] = max(dp[i][j], (i?dp[i-1][j-c]:0) + p);
            }
        }
        debug(arr(dp[i], T+1));
    }
    debug(dp[n-1][T]);
    cout << T - dp[n-1][T] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}