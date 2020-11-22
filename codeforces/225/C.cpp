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
    int n, m, x, y; cin >> n >> m >> x >> y; // upto 1000
    int cost[m+1][2]; // cost[i][0] = cost to change whole col i to '.'
                      // cost[i][1] = cost to change whole col i to '#'
    int pref[m+1][2]; // prefix sums for cost
    memset(cost, 0, sizeof(cost));
    memset(pref, 0, sizeof(pref));
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 1; j <= m; ++j) {
            if (s[j-1] == '.') {
                cost[j][1]++;
            } else if (s[j-1] == '#') {
                cost[j][0]++;
            }
        }
    }
    debug(arr(cost, m+1));
    // now select lowest cost such that width >= x and <= y
    // definition: lowest_cost = dp[i][color]    min cost to solve upto i and color it white/black
    // base case:  dp[0][color] = 0           (dp of everything else -> inf)
    // transition: dp[i][color] = min(coloring upto i-x opp color, i-x-1, .. upto i-y)   // O(n)
    int dp[m+1][2];
    memset(dp, 0, sizeof(dp));
    const int inf = 1e18;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j] = inf;
            pref[i][j] = (i?pref[i-1][j]:0) + cost[i][j];
        }
    }
    debug(arr(pref, m+1));
    auto getCost = [&] (int i, int j, int c) {
        // cost to color column i to j (inclusive) with color c
        return pref[j][c] - (i?pref[i-1][c]:0);
    };
    for (int i = 0; i <= m; ++i) {
        for (int c : {0, 1}) {
            for (int j = x; j <= y; ++j) {
                dp[i][c] = min(dp[i][c], ((i-j>=0)? dp[i-j][1-c] + getCost(i-j+1, i, c) :inf));
            }
        }
    }
    // for (int j = 0; j < 2; ++j) {
    //     for (int i = 0; i <= m; ++i) {
    //         cout << dp[i][j] << '\t';
    //     }
    //     cout << endl;
    // }
    cout << min(dp[m][0], dp[m][1]) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}