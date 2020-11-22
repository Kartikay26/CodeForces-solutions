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

const int mod = 1e8;

void test()
{
    int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
    int dp[n1+2][n2+2][k1+1][k2+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            // could remove factor of 10 here
            for (int a = 0; a <= k1; ++a) {
                for (int b = 0; b <= k2; ++b) {
                    if (a+1 <= k1) {
                        dp[i+1][j][a+1][0] += dp[i][j][a][b];
                        dp[i+1][j][a+1][0] %= mod;
                    }
                    if (b+1 <= k2) {
                        dp[i][j+1][0][b+1] += dp[i][j][a][b];
                        dp[i][j+1][0][b+1] %= mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int a = 0; a <= k1; ++a) {
        for (int b = 0; b <= k2; ++b) {
            ans += dp[n1][n2][a][b];
            ans %= mod;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}